#include <Arduino.h>

#include "ir.h"
#include "sd.h"
#include "oled.h"
#include "bt.h"

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
  // setup_ir();
  // setup_sd();
  setup_oled();
  // setup_bt();
  print_text(0, 0, "Hello World!", 1);
  print_text(0,1,"Now 13:30", 2);
  print_text(0,3,"26.07.2023",2);
  print_text(0,5,"Rainy", 3);
}

void my_loop()
{
}
