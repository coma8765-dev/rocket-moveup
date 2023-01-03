#include <MultiServo.h>

MultiServo::MultiServo(int countServo, int startPin, int defaultPosition, int runPosition) :
        count_servo(countServo),
        default_position(defaultPosition),
        run_position(runPosition) {
    servo = new Servo *[countServo];

    for (int i = 0; i < countServo; ++i) {
        servo[i] = new Servo;
        servo[i]->attach(startPin + i);
        servo[i]->write(default_position);
    }
}

void MultiServo::reset() {
    for (int i = 0; i < count_servo; ++i) {
        servo[i]->write(default_position);
    }
}

void MultiServo::run() {
    for (int i = 0; i < count_servo; ++i)
        if (servo) servo[i]->write(run_position);
}
