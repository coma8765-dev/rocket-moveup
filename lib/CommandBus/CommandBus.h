#ifndef UNTITLED_COMMANDBUS_H
#define UNTITLED_COMMANDBUS_H


#include <HardwareSerial.h>
#include <SoftwareSerial.h>


class CommandBus {
public:
    CommandBus(int stream_length, Stream **stream);

    String *getCommand();

private:
    int streamLength;
    Stream **streams;
};


#endif //UNTITLED_COMMANDBUS_H
