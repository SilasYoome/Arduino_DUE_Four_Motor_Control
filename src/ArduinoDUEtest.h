#ifndef ARDUINODUETEST_H_
#define ARDUIJODUETEST_H_


#include <Arduino.h>
#include <Encoder.h>

class ArduinoDUEtest{
    public:
        ArduinoDUEtest();
        void Fwd(int pwm);
        void Back(int pwm);
        void Left(int pwm);
        void Right(int pwm);

        void LeftFwd(int pwm);
        void RightFwd(int pwm);

        void LeftBack(int pwm);
        void RightBack(int pwm);

        void TurnLeft(int pwm);
        void TurnRight(int pwm);

        void brake();
        void Run_A_Circle();
        void PrintEncoder(); 
        int ReturnEncoderValue(int encoder); 
        void Get_IMU_Value();
    private:
        long MOTOR_A_ENCODER_VALUE;
        long MOTOR_B_ENCODER_VALUE;
        long MOTOR_C_ENCODER_VALUE;
        long MOTOR_D_ENCODER_VALUE;
        int ax,ay,az;
        int  cx,cy,cz;
        float gx,gy,gz,gt;
};

#endif