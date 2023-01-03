#ifndef UNTITLED_MULTISERVO_H
#define UNTITLED_MULTISERVO_H


#include <Servo.h>

class MultiServo {
private:
    Servo **servo{};
    int count_servo, default_position, run_position;

public:
    explicit MultiServo(int countServo = 4, int startPin = 6, int defaultPosition = 0, int runPosition = 90);

    void run();

    void reset();
};


#endif //UNTITLED_MULTISERVO_H
