#include <Arduino.h>

#include "ir.h"
#include "sd.h"

void init_hardware();

int main()
{
  init();
  init_hardware();
  for (;;)
  {
    write_sd("Hello World!", "text.txt");
    delay(1000);
  }
}

void init_hardware()
{
  //Serial.begin(9600);
  setup_ir();
  setup_sd();
}
