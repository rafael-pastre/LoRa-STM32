  HAL_StatusTypeDef status = HAL_OK;
  rfmTX = (RFM96*)malloc(sizeof(RFM96));
  status = RFM96_set_pins(rfmTX, hspi2, SS_COMM_TX_GPIO_Port, SS_COMM_TX_Pin, RESET_COMM_TX_GPIO_Port, RESET_COMM_TX_Pin);
  status = RFM96_init(rfmTX, 433.123E6, 0x12);
  status = RFM96_set_tx_power(rfmTX, 20, RFM96_LORA_PA_BOOST_PIN);
  status = RFM96_set_signal_bandwidth(rfmTX, RFM96_LORA_BW_125);
  status = RFM96_set_spreading_factor(rfmTX, 11);
  status = RFM96_enable_crc(rfmTX);
  //Teste LoRa com funcoes proprias
  uint8_t teste[32] = "Teste";
  status = RFM96_send_packet(rfmTX, teste, sizeof(teste));	//loraTX.sendPacket(teste, sizeof(teste));
  loraRX.readPacket(RxData, sizeof(RxData));
  teste[0] = 0;
