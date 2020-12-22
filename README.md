# Arduino-DUE-Four-Motor-Control
使用Arduino DUE控制四顆具有編碼器的有刷馬達，同時搭載九軸感測器GY-85與用於遠端遙控的藍芽模組HC-06

請注意四顆馬達的位置與編號，接下來都會依照以下編號進行解說

                   front
            -----------------
          ｜                  ｜
           C                  B
          ｜                  ｜
          ｜                  ｜
           D                  A
          ｜                  ｜
            -----------------
            
## ArduinoDUEtest.cpp內部涵式功能

### 四顆麥克納姆輪八方向控制、旋轉、停止
```C
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
```
#### 要特別注意的地方
##### 四顆馬達的前進涵式

A、B馬達的前進是使用lib裡面`motor.h`的`spin();`，後退是使用`backspin();`

C、D馬達的前進是使用lib裡面`motor.h`的`backspin();`，後退是使用`spin();`

兩組馬達的前進涵式是不同的，這點要特別注意
##### 兩組不同減速比的馬達
A、D馬達的齒輪箱減速比是1/55，B、C馬達的齒輪箱減速比是1/100

因此在下達PWM方面有特別為兩組不同的馬達做不同的PWM下達
    <br/> 
    <br/> 
    <br/> 
    <br/> 
    <br/> 

### 編碼器值讀取與顯示
```C
    int ReturnEncoderValue(int encoder);
    void PrintEncoder(); 
```
`void ReturnEncoderValue(int encoder); `會依照使用者輸入的值進行四顆編碼器其中一顆值的回傳

`void PrintEncoder(); `則是會在序列埠視窗顯示四顆編碼器的數值
#### 腳位的注意
要特別注意編碼器的AVout與BVout是需要使用具有中斷功能的腳位，不然會因為轉速過快造成數值回傳方面有缺失
    <br/> 
    <br/> 
    <br/> 
    <br/> 
    <br/> 

### 馬達轉一圈控制
```C
void Run_A_Circle();
```
使用編碼器進行馬達旋轉一圈後停止的控制，要注意的是目前使用的編碼器一圈是有700個pulse，因此此程式進行控制時是做700~710數值後停止的控制
    <br/> 
    <br/> 
    <br/> 
    <br/> 
    <br/> 
### 九軸感測器GY-85數值回傳
```C
void Get_IMU_Value();
```
回傳GY-85九軸感測的數值，要注意這些數值是**未經過校正的數值**
