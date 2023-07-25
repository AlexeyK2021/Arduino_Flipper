#include "oled.h"
GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;

void setup_oled()
{
    oled.init();
    oled.clear();
    oled.home();
}

void print_text(int row, int column, String &msg)
{
    oled.setCursor(row, column);
    oled.print(msg);
}

void draw_bitmap(int x, int y, uint8_t *bitmap, int width, int height, uint8_t invert, byte mode)
{
    oled.drawBitmap(x, y, bitmap, width, height, invert, mode);
    oled.update();
}

void draw_bluetooth()
{
    oled.drawBitmap(118, 0, bluetooth_bitmap, 10, 10, BITMAP_NORMAL, BUF_ADD);
}
