#ifndef MOTOR_H_
#define MOTOR_H_

#include <Arduino.h>

class motor{
    public:
    motor (int pwm_pin,int motor_pinA,int motor_pinB);
    void spin(int pwm);
    void backspin(int pwm);
    void brake();

    private:
        int pwm_pin_;
        int motor_pinA_;
        int motor_pinB_;
};

#endif