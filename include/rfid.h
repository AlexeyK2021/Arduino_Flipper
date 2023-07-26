#include <SPI.h>
#include <MFRC522.h>
#include "pins.h"

void setup_rfid();
void read_rfid();
void read_register();
void* read_card_data();