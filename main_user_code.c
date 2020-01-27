  RFM96* rfmTX;
  RFM96* rfmRX;
  HAL_StatusTypeDef status = HAL_OK;

  //TX Config
  rfmTX = (RFM96*)malloc(sizeof(RFM96));
  status = RFM96_set_pins(rfmTX, hspi2, SS_COMM_TX_GPIO_Port, SS_COMM_TX_Pin, RESET_COMM_TX_GPIO_Port, RESET_COMM_TX_Pin);
  status = RFM96_init(rfmTX, 433.123E6, 0x12);
  status = RFM96_set_tx_power(rfmTX, 20, RFM96_LORA_PA_BOOST_PIN);
  status = RFM96_set_signal_bandwidth(rfmTX, RFM96_LORA_BW_125);
  status = RFM96_set_spreading_factor(rfmTX, 11);
  status = RFM96_enable_crc(rfmTX);

  //RX Config
  rfmRX = (RFM96*)malloc(sizeof(RFM96));
  status = RFM96_set_pins(rfmRX, hspi2, SS_COMM_RX_GPIO_Port, SS_COMM_RX_Pin, RESET_COMM_RX_GPIO_Port, RESET_COMM_RX_Pin);
  status = RFM96_init(rfmRX, 433.123E6, 0x12);
  status = RFM96_set_signal_bandwidth(rfmRX, RFM96_LORA_BW_125);
  status = RFM96_set_spreading_factor(rfmRX, 11);
  status = RFM96_enable_crc(rfmRX);
  status = RFM96_explicit_header_mode(rfmRX);
  status = RFM96_set_op_mode(rfmRX, RFM96_LORA_MODE_RX_CONT);

  //Teste LoRa com funcoes proprias
  uint8_t teste[32] = "Teste";
  uint8_t RxData[128];
  status = RFM96_send_packet(rfmTX, teste, sizeof(teste));
  status = RFM96_read_packet(rfmRX, RxData, sizeof(RxData));
  
  while(1){
	  teste[0]++;
	  status = RFM96_send_packet(rfmTX, teste, sizeof(teste));
	  status = RFM96_read_packet(rfmRX, RxData, sizeof(RxData));//loraRX.readPacket(RxData, sizeof(RxData));
  }
