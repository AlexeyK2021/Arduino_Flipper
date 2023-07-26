#include <Arduino.h>

/*#include "ir.h"
#include "sd.h"
#include "oled.h"
#include "bt.h"*/
//#include "rfid.h"

void init_hardware();
void my_loop();

int main()
{
  init();
  init_hardware();
  for (;;)
  {
    my_loop();
  }
}

void init_hardware()
{
  //SPI.begin();
  Serial.begin(9600);
  // setup_ir();
  // setup_sd();
  // setup_oled();
  //setup_rfid();
  // setup_bt();
}

void my_loop()
{
  

  // read_rfid();
}
