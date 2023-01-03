#include "CommandBus.h"

CommandBus::CommandBus(int stream_length, Stream **stream) : streamLength(stream_length), streams(stream) {}

String *CommandBus::getCommand() {
    for (int i = 0; i < streamLength; ++i) {
        int available = streams[i]->available();
        if (available) return new String(streams[i]->readString());
    }
    return nullptr;
}
