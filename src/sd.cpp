#include "sd.h"

File myFile;

void setup_sd()
{
    //Serial.println("Initializing SD card...");
    // если microSD-карта не была обнаружена
    if (!SD.begin(SD_CS))
    {
        // выводим сообщение об ошибке
        //Serial.println("Card failed, or not present");
        // don't do anything more:
        return;
    }
    else
    {
        //Serial.println("Card initialized.");
    }
}

void write_sd(String dataString, String filename)
{

    File dataFile = SD.open(filename, FILE_WRITE);
    // если файл доступен для записи
    if (dataFile)
    {
        // сохраняем данные
        dataFile.println(dataString);
        // закрываем файл
        dataFile.close();
        // выводим сообщение об удачной записи
        Serial.println("Save OK");
    }
    else
    {
        // если файл не доступен
        //Serial.println("Error opening datalog.txt");
    }
}
void read_sd()
{
}