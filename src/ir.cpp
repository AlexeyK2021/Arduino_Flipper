#include "ir.h"

// #define pinIR 2
// CNec IRLremote;
//  CPanasonic IRLremote;
//  CHashIR IRLremote;

iarduino_IR_TX VD(IR_SENDER);
iarduino_IR_RX IR(IR_RECIEVER); // объявляем  объект IR  для работы с ИК приёмником (с указанием любого вывода к которому подключён ИК приёмник)

void setup_ir()
{
    /* if (!IRLremote.begin(pinIR))
         Serial.println(F("You did not choose a valid pin."));*/
    IR.begin(); // инициализируем работу с  ИК приёмопередатчиком*/
    VD.begin();
}

int read_ir()
{
    /*if (IRLremote.available())
    {
        // Get the new data from the remote
        auto data = IRLremote.read();
        Serial.print(F("Address: 0x"));
        Serial.println(data.address, HEX);
        Serial.print(F("Command: 0x"));
        Serial.println(data.command, HEX);
        Serial.println();
    }*/
    if (IR.check())
    { // если принят информационный пакет (без учета пакетов повтора)
        Serial.print("Protocol: ");
        Serial.println(IR.protocol());
        Serial.print("Data: ");
        Serial.println(IR.data, HEX);
        Serial.println("----------------------");
        return IR.data;
    }
    return 0;
}

void send_ir(int msg)
{
    VD.send(msg, true);
}