#include "rfid.h"

MFRC522 mfrc522(RFID_CS, RFID_RST); // SDA, RST

byte buffer[18];
byte block;
MFRC522::StatusCode status;
MFRC522::MIFARE_Key key;

bool isCardPresent();

void setup_rfid()
{
    mfrc522.PCD_Init();
    delay(4);
    mfrc522.PCD_DumpVersionToSerial();
    delay(10);
    Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void read_rfid()
{
    if (!isCardPresent())
        return;
    mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}

bool isCardPresent()
{
    if (!mfrc522.PICC_IsNewCardPresent())
    {
        return false;
    }

    if (!mfrc522.PICC_ReadCardSerial())
    {
        return false;
    }
    return true;
}

void *read_card_data()
{
    byte card_data[64][16];
    bool result = false;
    for (byte i = 0; i < 6; i++)
        key.keyByte[i] = 0xFF;

    if (!isCardPresent())
        return /*false*/ nullptr;

    for (byte block = 0; block < 64; block++)
    {
        // Serial.println(F("Authenticating using key A..."));
        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
        if (status != MFRC522::STATUS_OK)
        {
            Serial.print(F("PCD_Authenticate() failed: "));
            Serial.println(mfrc522.GetStatusCodeName(status));
            return /*false*/ nullptr;
        }

        // Read block
        byte byteCount = sizeof(buffer);
        status = mfrc522.MIFARE_Read(block, buffer, &byteCount);
        if (status != MFRC522::STATUS_OK)
        {
            Serial.print(F("MIFARE_Read() failed: "));
            Serial.println(mfrc522.GetStatusCodeName(status));
        }
        else
        {
            // Successful read
            result = true;
            Serial.print(F("Success with key:"));
            Serial.println();

            // Dump block data
            Serial.print(F("Block "));
            Serial.print(block);
            Serial.print(F(":"));
            Serial.println();

            for (int p = 0; p < 16; p++) // De 16 bits uit de block uitlezen
            {
                card_data[block][p] = buffer[p];
                //Serial.print(card_data[block][p]);
                //Serial.print(" ");
            }
        }
    }
    Serial.println();

    mfrc522.PICC_HaltA();      // Halt PICC
    mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
    return (void *)card_data;
}

bool write_to_card()
{
    return true;
}