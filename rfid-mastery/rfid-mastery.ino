#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9



//PCD - Proximity Coupling Device
//PICC - Proximity Integrated Circuit Card
MFRC522 rfid(SS_PIN, RST_PIN);

// Key for authentication
MFRC522::MIFARE_Key key;

void setup() {

  Serial.begin(9600);

  // Start SPI
  SPI.begin();

  // Initialize RFID
  rfid.PCD_Init();

  // Show firmware version
  rfid.PCD_DumpVersionToSerial();

  Serial.println("Scan RFID Card");

  // Default Key = FF FF FF FF FF FF
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
}

void loop() {

  // Check if card is present
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  Serial.println("Card Detected!");

  // Read card serial
  if (!rfid.PICC_ReadCardSerial()) {
    Serial.println("Reading Failed");
    return;
  }

  Serial.println("Card Read Success");

  // Print UID Size
  Serial.print("UID Size: ");
  Serial.println(rfid.uid.size);

  // Print UID
  Serial.print("UID: ");

  for (byte i = 0; i < rfid.uid.size; i++) {

    Serial.print(rfid.uid.uidByte[i], HEX);
    Serial.print(" ");
  }

  Serial.println();

  // -------------------------
  // AUTHENTICATION
  // -------------------------

  byte block = 1;

  MFRC522::StatusCode status;

  status = rfid.PCD_Authenticate(
              MFRC522::PICC_CMD_MF_AUTH_KEY_A,
              block,
              &key,
              &(rfid.uid)
           );

  // Print authentication status
  Serial.print("Authentication Status: ");

  Serial.println(rfid.GetStatusCodeName(status));

  if (status != MFRC522::STATUS_OK) {

    Serial.println("Authentication Failed");

    return;
  }

  // -------------------------
  // READ BLOCK
  // -------------------------

  byte buffer[18];
  byte size = sizeof(buffer);

  status = rfid.MIFARE_Read(block, buffer, &size);

  Serial.print("Read Status: ");

  Serial.println(rfid.GetStatusCodeName(status));

  if (status == MFRC522::STATUS_OK) {

    Serial.println("Data in Block:");

    for (byte i = 0; i < 16; i++) {

      Serial.write(buffer[i]);
    }

    Serial.println();
  }

  // -------------------------
  // WRITE BLOCK
  // -------------------------

  byte dataBlock[16] = {

    'A','A','Y','U','S','H',
    ' ','R','F','I','D',
    ' ','1','2','3','4'
  };

  status = rfid.MIFARE_Write(block, dataBlock, 16);

  Serial.print("Write Status: ");

  Serial.println(rfid.GetStatusCodeName(status));

  if (status == MFRC522::STATUS_OK) {

    Serial.println("Write Successful");
  }

  // Stop encrypted communication
  rfid.PCD_StopCrypto1();

  // Halt card
  rfid.PICC_HaltA();

  Serial.println("------------------");

  delay(3000);
}