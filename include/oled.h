#include <Wire.h>
#include <GyverOLED.h>
#include "pins.h"
#include "oled_icons.h"

void setup_oled();
void print_text(int, int, String &);
void draw_bitmap(int, int, uint8_t *, int, int, uint8_t, byte);
