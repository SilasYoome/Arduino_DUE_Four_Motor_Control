#include <Arduino.h>
#include "motor.h"

motor::motor(int pwm_pin, int motor_pinA,int motor_pinB){
    pinMode(pwm_pin,OUTPUT);
    pinMode(motor_pinA,OUTPUT);
    pinMode(motor_pinB,OUTPUT);

    pwm_pin_ = pwm_pin;
    motor_pinA_ = motor_pinA;
    motor_pinB_ = motor_pinB;
}
void motor::spin(int pwm){
    digitalWrite(motor_pinA_,HIGH);
    digitalWrite(motor_pinB_,LOW);
    analogWrite(pwm_pin_,pwm);
}
void motor::backspin(int pwm){
    digitalWrite(motor_pinA_,LOW);
    digitalWrite(motor_pinB_,HIGH);
    analogWrite(pwm_pin_,pwm);
}
void motor::brake()
{
    digitalWrite(motor_pinA_,HIGH);
    digitalWrite(motor_pinB_,HIGH);
    analogWrite(pwm_pin_,0);
}