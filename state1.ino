// This borrows code from Examples->EEPROM->eeprom_read

byte value;

void state1Setup() {
  Serial.println("Reading from EEPROM");

  //Print State 
  Serial.println("Current State is :");
  Serial.println(state);
  
  for (int i = 0; i < EEPROMSIZE; i++) {
    value = EEPROM.read(i);
    //Serial.println(value);

    // convert byte to char
    char packetBuffer;
    packetBuffer = (char) value;
    Serial.println((char) packetBuffer);

  }
  Serial.println();

  Serial.println("Done reading from EEPROM");
}

void state1Loop() {
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}

void doState1() {
  if (lastState != 1) { state1Setup(); }
  state1Loop();
}
