#ifndef UNTITLED_HC12_H
#define UNTITLED_HC12_H


#include <SoftwareSerial.h>

class HC12 {
public:
    SoftwareSerial *serial;

    explicit HC12(int setPin = 5, int rxPin = 3, int txPin = 4);

    bool setup(int channel = 1) const;

private:
    int set_pin, rx_pin, tx_pin;
};


#endif //UNTITLED_HC12_H
