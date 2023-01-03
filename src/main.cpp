#include <Arduino.h>
#include <MultiServo.cpp>
#include <HC12.cpp>
#include <CommandBus.h>

MultiServo servo;
HC12 radio;
CommandBus *commandBus;

__attribute__((unused)) void setup() {
    Serial.begin(9600);

    Stream *command_streams[] = {radio.serial, &Serial};
    commandBus = new CommandBus(2, command_streams);

    if (radio.setup(2)) {
        Serial.println("Setup HC12 success");
    } else {
        Serial.println("Setup HC12 not success");
    }
}

long long int reset_after = 0;

__attribute__((unused)) void loop() {
    String *command = commandBus->getCommand();

    if (command) {
        if (*command == "run") {
            servo.run();
        } else if (*command == "test-run") {
            servo.run();
            reset_after = millis() + 5000;
        } else {
            Serial.println("Invalid command \"" + *command + "\"");
        }
    }

    if (reset_after and reset_after < millis()) {
        reset_after = 0;
        servo.reset();
    }
}
