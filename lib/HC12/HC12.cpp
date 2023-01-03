#include <Arduino.h>
#include "HC12.h"


HC12::HC12(int setPin, int rxPin, int txPin) : set_pin(setPin), rx_pin(rxPin), tx_pin(txPin) {
    serial = new SoftwareSerial(tx_pin, rx_pin);
    serial->begin(9600);
    pinMode(set_pin, OUTPUT);
    digitalWrite(set_pin, HIGH);
}

bool HC12::setup(int channel) const {
    digitalWrite(set_pin, LOW);
    delay(50);

    serial->println("AT");
    if (serial->readStringUntil('\n') != "OK\r") {
        return false;
    }

    serial->println("AT+DEFAULT");
    if (serial->readStringUntil('\n') != "OK+DEFAULT\r") {
        return false;
    }

    String channel_string = (String) channel;
    String padding_channel_string = "";

    for (unsigned int i = 0; i < 3 - channel_string.length(); ++i) {
        padding_channel_string += "0";
    }

    padding_channel_string += channel_string;

    serial->println("AT+C" + padding_channel_string);
    if (serial->readStringUntil('\n') != "OK+C" + padding_channel_string + "\r") {
        return false;
    }

    digitalWrite(set_pin, HIGH);
    delay(50);

    return true;
}
