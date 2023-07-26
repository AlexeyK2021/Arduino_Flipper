#include <Wire.h>
#include <GyverOLED.h>
#include "pins.h"
#include "oled_icons.h"

void setup_oled();
void print_text(int, int, char *, int);
void draw_bitmap(int, int, uint8_t *, int, int, uint8_t, byte);
void clear_display();
void switch_display(bool);
void set_contrast(uint8_t);
