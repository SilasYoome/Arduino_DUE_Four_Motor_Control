#include <Arduino.h>
#include "ArduinoDUEtest.h"

#include "Encoder.h"
#include "config.h"
#include "motor.h"
#include "GY85.h"

GY_85 GY85;

//MOTOR PIN set
motor MOTOR_A(PWMA,AIN1,AIN2);
motor MOTOR_B(PWMB,BIN1,BIN2);
motor MOTOR_C(PWMC,CIN1,CIN2);
motor MOTOR_D(PWMD,DIN1,DIN2);

//ENCODER PIN set
Encoder ENCODER_A(MOTOR_A_ENCODER_A_PIN,MOTOR_A_ENCODER_B_PIN);
Encoder ENCODER_B(MOTOR_B_ENCODER_A_PIN,MOTOR_B_ENCODER_B_PIN);
Encoder ENCODER_C(MOTOR_C_ENCODER_A_PIN,MOTOR_C_ENCODER_B_PIN);
Encoder ENCODER_D(MOTOR_D_ENCODER_A_PIN,MOTOR_D_ENCODER_B_PIN);


ArduinoDUEtest::ArduinoDUEtest(){

}
void ArduinoDUEtest::Fwd(int pwm){
    //A、D馬達減速比55，B、C馬達減速比100
     int pwma,pwmb;
     pwma = pwm;
     pwmb = pwm * 0.55;
     MOTOR_A.backspin(pwmb);
     MOTOR_B.backspin(pwma);
     MOTOR_C.spin(pwma);
     MOTOR_D.backspin(pwmb);
}
void ArduinoDUEtest::Back(int pwm){
    //A、D馬達減速比55，B、C馬達減速比100
     int pwma,pwmb;
     pwma = pwm;
     pwmb = pwm * 0.55;
     MOTOR_A.spin(pwmb);
     MOTOR_B.spin(pwma);
     MOTOR_C.backspin(pwma);
     MOTOR_D.spin(pwmb);
}
void ArduinoDUEtest::Left(int pwm){
    //A、D馬達減速比55，B、C馬達減速比100
     int pwma,pwmb;
     pwma = pwm;
     pwmb = pwm * 0.55;
     MOTOR_A.backspin(pwmb);
     MOTOR_B.backspin(pwma);
     MOTOR_C.backspin(pwma);
     MOTOR_D.spin(pwmb);
}
void ArduinoDUEtest::Right(int pwm){
    //A、D馬達減速比55，B、C馬達減速比100
     int pwma,pwmb;
     pwma = pwm;
     pwmb = pwm * 0.55;
     MOTOR_A.spin(pwmb);
     MOTOR_B.spin(pwma);
     MOTOR_C.spin(pwma);
     MOTOR_D.backspin(pwmb);
}
void ArduinoDUEtest::LeftFwd(int pwm){
    //A、D馬達減速比55，B、C馬達減速比100
     int pwma,pwmb;
     pwma = pwm;
     pwmb = pwm * 0.55;
     MOTOR_A.brake();
     MOTOR_B.backspin(pwma);
     MOTOR_C.brake();
     MOTOR_D.backspin(pwmb);
}
void ArduinoDUEtest::RightFwd(int pwm){
    //A、D馬達減速比55，B、C馬達減速比100
     int pwma,pwmb;
     pwma = pwm;
     pwmb = pwm * 0.55;
     MOTOR_A.backspin(pwmb);
     MOTOR_B.brake();
     MOTOR_C.spin(pwma);
     MOTOR_D.brake();
}
void ArduinoDUEtest::LeftBack(int pwm){
    //A、D馬達減速比55，B、C馬達減速比100
      int pwma,pwmb;
     pwma = pwm;
     pwmb = pwm * 0.55;
     MOTOR_A.spin(pwma);
     MOTOR_B.brake();
     MOTOR_C.backspin(pwmb);
     MOTOR_D.brake();
}
void ArduinoDUEtest::RightBack(int pwm){
    //A、D馬達減速比55，B、C馬達減速比100
     int pwma,pwmb;
     pwma = pwm;
     pwmb = pwm * 0.55;
     MOTOR_A.brake();
     MOTOR_B.spin(pwma);
     MOTOR_C.brake();
     MOTOR_D.spin(pwmb);
}
void ArduinoDUEtest::TurnLeft(int pwm){
    //A、D馬達減速比55，B、C馬達減速比100
     int pwma,pwmb;
     pwma = pwm;
     pwmb = pwm * 0.55;
     MOTOR_A.brake();
     MOTOR_B.backspin(pwma);
     MOTOR_C.backspin(pwma);
     MOTOR_D.brake();
}
void ArduinoDUEtest::TurnRight(int pwm){
    //A、D馬達減速比55，B、C馬達減速比100
     int pwma,pwmb;
     pwma = pwm;
     pwmb = pwm * 0.55;
     MOTOR_A.brake();
     MOTOR_B.spin(pwma);
     MOTOR_C.spin(pwma);
     MOTOR_D.brake();
}
void ArduinoDUEtest::brake(){
    MOTOR_A.brake();
    MOTOR_B.brake();
    MOTOR_C.brake();
    MOTOR_D.brake();
}
void ArduinoDUEtest::Run_A_Circle(){
    //TT馬達一圈700
    if(ReturnEncoderValue(1) >= 710 || ReturnEncoderValue(1) <= -710 
            || ReturnEncoderValue(1) >= 700 || ReturnEncoderValue(1)  <= -700)
            {
                brake();
                Serial.print(ReturnEncoderValue(1));
            }
    else
    {
        Fwd(125);
    }
    
}
void ArduinoDUEtest::PrintEncoder(){
    Serial.print(ReturnEncoderValue(1));
    Serial.print(" , ");
    Serial.print(ReturnEncoderValue(2));
    Serial.print(" , ");
    Serial.print(ReturnEncoderValue(3));
    Serial.print(" , ");
    Serial.print(ReturnEncoderValue(4));
    Serial.println();
}
int ArduinoDUEtest::ReturnEncoderValue(int encoder){
    MOTOR_A_ENCODER_VALUE = ENCODER_A.read();
    MOTOR_B_ENCODER_VALUE = ENCODER_B.read();
    MOTOR_C_ENCODER_VALUE = ENCODER_C.read();
    MOTOR_D_ENCODER_VALUE = ENCODER_D.read();
    switch(encoder){
        case 1:
            return MOTOR_A_ENCODER_VALUE;
            break;
        case 2:
            return MOTOR_B_ENCODER_VALUE;
            break;
        case 3:
            return MOTOR_C_ENCODER_VALUE;
            break;
        case 4:
            return MOTOR_D_ENCODER_VALUE;
            break;
    }
}
void ArduinoDUEtest::Get_IMU_Value(){
    ax = GY85.accelerometer_x( GY85.readFromAccelerometer() );
    ay = GY85.accelerometer_y( GY85.readFromAccelerometer() );
    az = GY85.accelerometer_z( GY85.readFromAccelerometer() );
    
    cx = GY85.compass_x( GY85.readFromCompass() );
    cy = GY85.compass_y( GY85.readFromCompass() );
    cz = GY85.compass_z( GY85.readFromCompass() );

    gx = GY85.gyro_x( GY85.readGyro() );
    gy = GY85.gyro_y( GY85.readGyro() );
    gz = GY85.gyro_z( GY85.readGyro() );
    gt = GY85.temp  ( GY85.readGyro() );
    
    Serial.print  ( " ax:" );
    Serial.print  ( ax );
    Serial.print  ( " ay:" );
    Serial.print  ( ay );
    Serial.print  ( " az:" );
    Serial.print  ( az );
    Serial.println();
    
    Serial.print  ( " cx:" );
    Serial.print  ( cx );
    Serial.print  ( "c y:" );
    Serial.print  ( cy );
    Serial.print  (" cz:");
    Serial.print  ( cz );
    Serial.println();
    
    Serial.print  ( " gx:" );
    Serial.print  ( gx );
    Serial.print  ( " gy:" );
    Serial.print  ( gy );
    Serial.print  ( " gz:" );
    Serial.print  ( gz );
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
   /* Serial.print  ( " gyro temp:" );
    Serial.println( gt );*/
    delay(300);
}

