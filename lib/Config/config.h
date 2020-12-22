#ifndef CONFIG_H_
#define CONFIG_H_

/*
        C-----------------B
        |                            | 
        |                            | 
        |                            | 
        |                            | 
        D-----------------A
*/
//Motor pin M+ and M-
#define AIN1 30
#define AIN2 31
#define BIN1 32
#define BIN2 33
#define CIN1 34
#define CIN2 35
#define DIN1 36
#define DIN2 37

//Motor pin PWM
#define PWMA 12
#define PWMB 11
#define PWMC 10
#define PWMD 9

//Encoder pin VAout and VBout
#define MOTOR_A_ENCODER_A_PIN 22
#define MOTOR_A_ENCODER_B_PIN 23
#define MOTOR_B_ENCODER_A_PIN 24
#define MOTOR_B_ENCODER_B_PIN 25
#define MOTOR_C_ENCODER_A_PIN 26
#define MOTOR_C_ENCODER_B_PIN 27
#define MOTOR_D_ENCODER_A_PIN 28
#define MOTOR_D_ENCODER_B_PIN 29

//Encoder total value
/*#define MOTOR_A_ENCODER_VALUE;
#define MOTOR_B_ENCODER_VALUE;
#define MOTOR_C_ENCODER_VALUE;
#define MOTOR_D_ENCODER_VALUE;*/

#define PWM_MAX 200
#endif