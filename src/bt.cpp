#include "bt.h"

SoftwareSerial btSerial(BT_RX, BT_TX);

void setup_bt(){
    btSerial.begin(9600);
}

void send_bt(String& msg){
    if (btSerial.available())
    {
       btSerial.print(msg);
    }
    
}