const int CE = 10;
const int OE = 11;
const int WE = 12;

// Instructions: /////////////////////////////////////////////////////////////////////////////////////////
const uint32_t NOP =           0b00000000;
const uint32_t STAx =          0b00000001;
const uint32_t LDAx =          0b00000010;
const uint32_t ADDx =          0b00000011;
const uint32_t SUBx =          0b00000100;
const uint32_t JMPx =          0b00000101;
const uint32_t _RESERVED1_ =   0b00000110;
const uint32_t _RESERVED2_ =   0b00000111;
const uint32_t _RESERVED3_ =   0b00001000;
const uint32_t _RESERVED4_ =   0b00001001;
const uint32_t _RESERVED5_ =   0b00001010;
const uint32_t _RESERVED6_ =   0b00001011;
const uint32_t _RESERVED7_ =   0b00001100;
const uint32_t _RESERVED8_ =   0b00001101;
const uint32_t OUT =           0b00001110;
const uint32_t HLT =           0b00001111;
//////////////////////////////////////////////////////////////////////////////////////////////////////////

// Control bits: /////////////////////////////////////////////////////////////////////////////////////////
const uint32_t _Cstop =        0b0000000000000001;
const uint32_t _RCreset =      0b0000000000000010;
const uint32_t _PCin =         0b0000000000000100;
const uint32_t _PCout =        0b0000000000001000;
const uint32_t PCincrement =   0b0000000000010000;
const uint32_t MARin =         0b0000000000100000;
const uint32_t RAMin =         0b0000000001000000;
const uint32_t _RAMout =       0b0000000010000000;
const uint32_t IRin =          0b0000000100000000;
const uint32_t _IRout =        0b0000001000000000;
const uint32_t RAin =          0b0000010000000000;
const uint32_t _RAout =        0b0000100000000000;
const uint32_t RBin =          0b0001000000000000;
const uint32_t _SRout =        0b0010000000000000;
const uint32_t SRsubstract =   0b0100000000000000;
const uint32_t ORin =          0b1000000000000000;

const uint32_t INVERTED_LOGIC_MASK = 0b0010101010001111;
//////////////////////////////////////////////////////////////////////////////////////////////////////////

// Micro-codes: //////////////////////////////////////////////////////////////////////////////////////////
const long MICRO_CODES_COUNT = 60; // Change manually when adding more!
const uint32_t MICRO_CODES[MICRO_CODES_COUNT] = {
  0 + (NOP << 3) + ((_PCout | MARin) << 16),
  1 + (NOP << 3) + ((_RAMout | IRin | PCincrement) << 16),
  2 + (NOP << 3) + ((_RCreset) << 16),

  0 + (STAx << 3) + ((_PCout | MARin) << 16),
  1 + (STAx << 3) + ((_RAMout | IRin | PCincrement) << 16),
  2 + (STAx << 3) + ((_IRout | MARin) << 16),
  3 + (STAx << 3) + ((_RAMout | RAin) << 16),
  4 + (STAx << 3) + ((_RCreset) << 16),

  0 + (LDAx << 3) + ((_PCout | MARin) << 16),
  1 + (LDAx << 3) + ((_RAMout | IRin | PCincrement) << 16),
  2 + (LDAx << 3) + ((_IRout | MARin) << 16),
  3 + (LDAx << 3) + ((_RAout | RAMin) << 16),
  4 + (LDAx << 3) + ((_RCreset) << 16),

  0 + (ADDx << 3) + ((_PCout | MARin) << 16),
  1 + (ADDx << 3) + ((_RAMout | IRin | PCincrement) << 16),
  2 + (ADDx << 3) + ((_IRout | MARin) << 16),
  3 + (ADDx << 3) + ((_RAMout | RBin) << 16),
  4 + (ADDx << 3) + ((_SRout | RAin) << 16),
  5 + (ADDx << 3) + ((_RCreset) << 16),

  0 + (SUBx << 3) + ((_PCout | MARin) << 16),
  1 + (SUBx << 3) + ((_RAMout | IRin | PCincrement) << 16),
  2 + (SUBx << 3) + ((_IRout | MARin) << 16),
  3 + (SUBx << 3) + ((_RAMout | RBin) << 16),
  4 + (SUBx << 3) + ((SRsubstract | _SRout | RAin) << 16),
  5 + (SUBx << 3) + ((_RCreset) << 16),

  0 + (JMPx << 3) + ((_PCout | MARin) << 16),
  1 + (JMPx << 3) + ((_RAMout | IRin | PCincrement) << 16),
  2 + (JMPx << 3) + ((_IRout | _PCin) << 16),
  3 + (JMPx << 3) + ((_RCreset) << 16),

  0 + (_RESERVED1_ << 3) + ((_PCout | MARin) << 16),
  1 + (_RESERVED1_ << 3) + ((_RAMout | IRin | PCincrement) << 16),
  2 + (_RESERVED1_ << 3) + ((_RCreset) << 16),

  0 + (_RESERVED2_ << 3) + ((_PCout | MARin) << 16),
  1 + (_RESERVED2_ << 3) + ((_RAMout | IRin | PCincrement) << 16),
  2 + (_RESERVED2_ << 3) + ((_RCreset) << 16),

  0 + (_RESERVED3_ << 3) + ((_PCout | MARin) << 16),
  1 + (_RESERVED3_ << 3) + ((_RAMout | IRin | PCincrement) << 16),
  2 + (_RESERVED3_ << 3) + ((_RCreset) << 16),

  0 + (_RESERVED4_ << 3) + ((_PCout | MARin) << 16),
  1 + (_RESERVED4_ << 3) + ((_RAMout | IRin | PCincrement) << 16),
  2 + (_RESERVED4_ << 3) + ((_RCreset) << 16),

  0 + (_RESERVED5_ << 3) + ((_PCout | MARin) << 16),
  1 + (_RESERVED5_ << 3) + ((_RAMout | IRin | PCincrement) << 16),
  2 + (_RESERVED5_ << 3) + ((_RCreset) << 16),

  0 + (_RESERVED6_ << 3) + ((_PCout | MARin) << 16),
  1 + (_RESERVED6_ << 3) + ((_RAMout | IRin | PCincrement) << 16),
  2 + (_RESERVED6_ << 3) + ((_RCreset) << 16),

  0 + (_RESERVED7_ << 3) + ((_PCout | MARin) << 16),
  1 + (_RESERVED7_ << 3) + ((_RAMout | IRin | PCincrement) << 16),
  2 + (_RESERVED7_ << 3) + ((_RCreset) << 16),

  0 + (_RESERVED8_ << 3) + ((_PCout | MARin) << 16),
  1 + (_RESERVED8_ << 3) + ((_RAMout | IRin | PCincrement) << 16),
  2 + (_RESERVED8_ << 3) + ((_RCreset) << 16),

  0 + (OUT << 3) + ((_PCout | MARin) << 16),
  1 + (OUT << 3) + ((_RAMout | IRin | PCincrement) << 16),
  2 + (OUT << 3) + ((_RAout | ORin) << 16),
  3 + (OUT << 3) + ((_RCreset) << 16),

  0 + (HLT << 3) + ((_PCout | MARin) << 16),
  1 + (HLT << 3) + ((_RAMout | IRin | PCincrement) << 16),
  2 + (HLT << 3) + ((_Cstop) << 16)
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////


void enableEEPROM(bool enabled) {
  digitalWrite(CE, enabled ? LOW : HIGH);
}

void enableEEPROMOutput(bool enabled) {
  digitalWrite(OE, enabled ? LOW : HIGH);
}

void enableEEPROMWrite(bool enabled) {
  digitalWrite(WE, enabled ? LOW : HIGH);
}

void setDataPinsMode(int mode) {
  for (int i = 0; i < 8; i++)
    pinMode(i + 2, mode);
}

void setDataPinsValue(uint8_t value) {
  for (int i = 0; i < 8; i++)
    digitalWrite(i + 2, (value >> i) & 0b00000001);
}

uint8_t getDataPinsValue() {
  uint8_t value = 0;
  for (int i = 0; i < 8; i++)
    value += digitalRead(i + 2) << i;
  return value;
}

void setAddressPinsValue(uint16_t value) {
  for (int i = 0; i < 13; i++)
    digitalWrite(i + 54, (value >> i) & 0b0000000000000001);
}

uint8_t readEEPROM(uint16_t address) {
  setDataPinsMode(INPUT);
  enableEEPROM(true);
  setAddressPinsValue(address);
  enableEEPROMOutput(true);
  uint8_t data = getDataPinsValue();
  enableEEPROMOutput(false);
  enableEEPROM(false);
  return data;
}

void writeEEPROM(uint16_t address, uint8_t data) {
  setDataPinsMode(OUTPUT);
  enableEEPROM(true);
  setAddressPinsValue(address);
  setDataPinsValue(data);
  enableEEPROMWrite(true);
  delayMicroseconds(1);
  enableEEPROMWrite(false);
  enableEEPROM(false);
}

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(CE, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(WE, OUTPUT);
  for (int i = 0; i < 13; i++)
    pinMode(i + 54, OUTPUT);
  enableEEPROM(false);
  enableEEPROMOutput(false);
  enableEEPROMWrite(false);
}

void loop() {
  while (!Serial.available());
  char operationChar = Serial.read();
  if (operationChar == 'w') {
    while (!Serial.available());
    operationChar = Serial.read();
    if (operationChar == 'o') {
      while (!Serial.available());
      operationChar = Serial.read();
      if (operationChar == 'd') {
        Serial.print("Programming EEPROM (output display)... ");
        programEEPROMForOutputDisplay();
        Serial.println("Done!");
      }
    } else if (operationChar == 'i') {
      while (!Serial.available());
      operationChar = Serial.read();
      if (operationChar == 'd') {
        while (!Serial.available());
        operationChar = Serial.read();
        if (operationChar == '0') {
          Serial.print("Programming EEPROM (first instruction decoder)... ");
          programEEPROMForInstructionDecoder(0);
          Serial.println("Done!");
        } else if (operationChar == '1') {
          Serial.print("Programming EEPROM (second instruction decoder)... ");
          programEEPROMForInstructionDecoder(1);
          Serial.println("Done!");
        }
      }
    }
  } else if (operationChar == 'r') {
    printAllEEPROM();
  } else if (operationChar == 'c') {
    while (!Serial.available());
    operationChar = Serial.read();
    if (operationChar == 'l') {
      Serial.print("Clearing EEPROM (to low state)... ");
      clearEEPROMToLow();
      Serial.println("Done!");
    } else if (operationChar == 'h') {
      Serial.print("Clearing EEPROM (to high state)... ");
      clearEEPROMToHigh();
      Serial.println("Done!");
    } else if (operationChar == 'i') {
      while (!Serial.available());
      operationChar = Serial.read();
      if (operationChar == 'l') {
        while (!Serial.available());
        operationChar = Serial.read();
        if (operationChar == 'm') {
          while (!Serial.available());
          operationChar = Serial.read();
          if (operationChar == '0') {
            Serial.print("Clearing EEPROM (to the inverted logic mask value for the first EEPROM)... ");
            clearEEPROMToInvertedLogicMaskValue(0);
            Serial.println("Done!");
          } else if (operationChar == '1') {
            Serial.print("Clearing EEPROM (to the inverted logic mask value for the second EEPROM)... ");
            clearEEPROMToInvertedLogicMaskValue(1);
            Serial.println("Done!");
          }
        }
      }
    }
  }
}

void clearEEPROMToLow() {
  for (uint16_t i = 0; i < 8192; i++) {
    writeEEPROM(i, 0);
    delay(1);
  }
}

void clearEEPROMToHigh() {
  for (uint16_t i = 0; i < 8192; i++) {
    writeEEPROM(i, 255);
    delay(1);
  }
}

void clearEEPROMToInvertedLogicMaskValue(int indexOfEEPROM) {
  for (uint16_t i = 0; i < 8192; i++) {
    if (indexOfEEPROM == 0) {
      writeEEPROM(i, INVERTED_LOGIC_MASK & 0b11111111);
      delay(1);
    } else if (indexOfEEPROM == 1) {
      writeEEPROM(i, INVERTED_LOGIC_MASK >> 8);
      delay(1);
    }
  }
}

void programEEPROMForOutputDisplay() {
  for (int16_t i = -128; i < 128; i++) {
    uint8_t ii = i;
    if (i / 10 == 0) {
      writeEEPROM(0b0000000000000000 + (ii << 2), convertDecimalDigitTo7SegmentsDigit(abs(i) % 10));
      delay(1);
      writeEEPROM(0b0000000000000001 + (ii << 2), 0);
      delay(1);
      writeEEPROM(0b0000000000000010 + (ii << 2), 0);
      delay(1);
    } else if (i / 100 == 0) {
      writeEEPROM(0b0000000000000000 + (ii << 2), convertDecimalDigitTo7SegmentsDigit(abs(i) % 10));
      delay(1);
      writeEEPROM(0b0000000000000001 + (ii << 2), convertDecimalDigitTo7SegmentsDigit((abs(i) / 10) % 10));
      delay(1);
      writeEEPROM(0b0000000000000010 + (ii << 2), 0);
      delay(1);
    } else {
      writeEEPROM(0b0000000000000000 + (ii << 2), convertDecimalDigitTo7SegmentsDigit(abs(i) % 10));
      delay(1);
      writeEEPROM(0b0000000000000001 + (ii << 2), convertDecimalDigitTo7SegmentsDigit((abs(i) / 10) % 10));
      delay(1);
      writeEEPROM(0b0000000000000010 + (ii << 2), convertDecimalDigitTo7SegmentsDigit((abs(i) / 100) % 10));
      delay(1);
    }
    if (i < 0) {
      writeEEPROM(0b0000000000000011 + (ii << 2), 0b01000000);
      delay(1);
    } else {
      writeEEPROM(0b0000000000000011 + (ii << 2), 0b00000000);
      delay(1);
    }
  }
}

void programEEPROMForInstructionDecoder(int indexOfEEPROM) {
  for (long i = 0; i < MICRO_CODES_COUNT; i++) {
    if (indexOfEEPROM == 0) {
      writeEEPROM(MICRO_CODES[i] & 0b00000000000000000000000001111111, ((MICRO_CODES[i] >> 16) ^ INVERTED_LOGIC_MASK) & 0b11111111);
      delay(1);
    } else if (indexOfEEPROM == 1) {
      writeEEPROM(MICRO_CODES[i] & 0b00000000000000000000000001111111, ((MICRO_CODES[i] >> 16) ^ INVERTED_LOGIC_MASK) >> 8);
      delay(1);
    }
  }
}

void printAllEEPROM() {
  for (int i = 0; i < 8192; i++) {
    Serial.print("0b");
    Serial.print(i, BIN);
    Serial.print(":    0b");
    Serial.println(readEEPROM(i), BIN);
  }
}

uint8_t convertDecimalDigitTo7SegmentsDigit(uint8_t digit) {
  switch (digit) {
    case 0:
      return 0b00111111;
      break;
    case 1:
      return 0b00000110;
      break;
    case 2:
      return 0b01011011;
      break;
    case 3:
      return 0b01001111;
      break;
    case 4:
      return 0b01100110;
      break;
    case 5:
      return 0b01101101;
      break;
    case 6:
      return 0b01111101;
      break;
    case 7:
      return 0b00000111;
      break;
    case 8:
      return 0b01111111;
      break;
    case 9:
      return 0b01101111;
      break;
  }
}

