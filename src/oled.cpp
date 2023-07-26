#include "oled.h"
GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;

void setup_oled()
{
    oled.init();
    oled.clear();
    oled.home();
    oled.textMode(BUF_REPLACE);
}

void print_text(int row, int column, char *msg, int scale = 1)
{
    oled.setScale(scale);
    oled.setCursor(row, column);
    oled.print(msg);
}

void draw_bitmap(int x, int y, uint8_t *bitmap, int width, int height, uint8_t invert, byte mode)
{
    oled.drawBitmap(x, y, bitmap, width, height, invert, mode);
    oled.update();
}

/*void draw_bluetooth()
{
    oled.drawBitmap(118, 0, bluetooth_bitmap, 10, 10, BITMAP_NORMAL, BUF_REPLACE);
}

void hide_bluetooth()
{
}*/

void clear_display()
{
    oled.clear();
}

void switch_display(bool power)
{
    oled.setPower(power);
}

void set_display_contrast(uint8_t brightness)
{
    oled.setContrast(brightness);
}