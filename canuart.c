
void can_uart(void)
{
	/* redirect UART input/output to CAN */

	unsigned n, i;

	tx_msg.PRIOR_0 = DISABLE;
	tx_msg.IDE = CAN_ID_EXT;

	//while ( UART_GetFlagStatus(MDR_UART1, UART_FLAG_RXFE) == RESET ) {
	while (uart_buf_count < sizeof uart_buf) {
		//tx_msg.Data[0] = (UART_ReceiveData(MDR_UART1) & 0xff);
		tx_msg.Data[0] = uart_buf[uart_buf_count++];
		tx_msg.DLC = 1;
		tx_msg.ID = 1;

		while (1) {
			if ( !(CAN_GetBufferStatus(BMC_CAN, can_bufnum) & CAN_BUF_CON_TX_REQ) ) {
				CAN_Transmit(BMC_CAN, can_bufnum, &tx_msg);
				can_bufnum = (can_bufnum + 1) % 16;
				break;
			}
		}
	}

	if ((CAN_GetBufferStatus(BMC_CAN, 31) & CAN_BUF_CON_RX_FULL)) {
		CAN_ITClearRxTxPendingBit(BMC_CAN, 31, CAN_STATUS_RX_READY);
		CAN_GetRawReceivedData(BMC_CAN, 31, &rx_msg);
		for (n = 0; n < rx_msg.Rx_Header.DLC; ++n) {
			while (UART_GetFlagStatus(MDR_UART1, UART_FLAG_TXFF) == SET)
				;
			if (n < 4)
				UART_SendData(MDR_UART1,  ( rx_msg.Data[0] >> (n * 8) ) & 0xff);
			else
				UART_SendData(MDR_UART1,  ( rx_msg.Data[1] >> ((n % 4) * 8) ) & 0xff);
		}
	}
}
