/*
 Line Follower code by ROBOJUNKIES
 Edited by-Akhil Isac Mathew
*/

#include <SparkFun_TB6612.h>

#define AIN1 8
#define BIN1 5
#define AIN2 7
#define BIN2 4
#define PWMA 9
#define PWMB 3
#define STBY 6

// these constants are used to allow you to make your motor configuration
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = 1;
const int offsetB = 1;

// Initializing motors.  The library will allow you to initialize as many
// motors as you have memory for.  If you are using functions like forward
// that take 2 motors as arguements you can either write new functions or
// call the function more than once.

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);


int P, D, I, previousError, PIDvalue, error;
int lsp, rsp;
int lfspeed = 250;
int i=1;

float Kp = 0;
float Kd = 0;
float Ki = 0 ;


int minValues[8], maxValues[8], threshold[8];

void setup()
{
  Serial.begin(9600);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
}

void loop()
{
  while (digitalRead(11)) {
  delay(1000);
  calibrate();
  }
  while (digitalRead(12)) {
  delay(1000);

  while (1)
  {if (analogRead(1) < threshold[1] && analogRead(2) < threshold[2] && analogRead(3) > threshold[3] && analogRead(4) > threshold[4] && analogRead(5) > threshold[5] && analogRead(6) < threshold[6] && analogRead(7) > threshold[7] )
    {//w w b b b w b
     /*for acute angles adjust the iteration to increase or decrease the time
     this is right acutes*/
      lsp = lfspeed; rsp = -50;
      for(int i=0;i<7000;i++)
      {
      motor1.drive(lfspeed);
      motor2.drive(-50);
      }
    }
   else if (analogRead(1) > threshold[1] && analogRead(2) < threshold[2] && analogRead(3) > threshold[3] && analogRead(4) > threshold[4] && analogRead(5) > threshold[5] && analogRead(6) < threshold[6] && analogRead(7) < threshold[7] )
    {//b w b b b w w
     /*for acute angles adjust the iteration to increase or decrease the time
     this is left acutes*/
      lsp = -50; rsp = lfspeed;
      for(int i=0;i<7000;i++)
      {
      motor1.drive(-50);
      motor2.drive(lfspeed);
      }
    }
   else if (analogRead(1) < threshold[1] && analogRead(2) < threshold[2] && analogRead(3) > threshold[3] && analogRead(4) > threshold[4] && analogRead(5) < threshold[5] && analogRead(6) > threshold[6] && analogRead(7) > threshold[7])
    {//w w b b w b b 
      lsp = lfspeed; rsp = 0;
      motor1.drive(lfspeed);
      motor2.drive(0);
    }
    else if (analogRead(1) > threshold[1] && analogRead(2) > threshold[2] && analogRead(3) < threshold[3] && analogRead(4) > threshold[4] && analogRead(5) > threshold[5] && analogRead(6) < threshold[6] && analogRead(7) < threshold[7])
    {//b b w b b w w
      lsp = 0; rsp = lfspeed;
      motor1.drive(0);
      motor2.drive(lfspeed);
    }
    else if (analogRead(1) < threshold[1] && analogRead(2) > threshold[2] && analogRead(3) > threshold[3] && analogRead(4) > threshold[4] && analogRead(5) > threshold[5] && analogRead(6) < threshold[6] && analogRead(7) < threshold[7])
    {//w b b b b w w
      lsp = 0; rsp = lfspeed;
      motor1.drive(0);
      motor2.drive(lfspeed);  
    }
    else if (analogRead(1) < threshold[1] && analogRead(2) < threshold[2] && analogRead(3) > threshold[3] && analogRead(4) > threshold[4] && analogRead(5) > threshold[5] && analogRead(6) > threshold[6] && analogRead(7) < threshold[7])
    {//w w b b b b w
      lsp = lfspeed; rsp = 0;
      motor1.drive(lfspeed);
      motor2.drive(0);
    }
   else if (analogRead(1) < threshold[1] && analogRead(2) > threshold[2] && analogRead(3) > threshold[3] && analogRead(4) > threshold[4] && analogRead(5) > threshold[5] && analogRead(6) > threshold[6] && analogRead(7) > threshold[7])
    {//w b b b b b b
      lsp = lfspeed; rsp = 0;
      motor1.drive(lfspeed);
      motor2.drive(0);
    }
   else if (analogRead(1) < threshold[1] && analogRead(2) < threshold[2] && analogRead(3) > threshold[3] && analogRead(4) > threshold[4] && analogRead(5) > threshold[5] && analogRead(6) > threshold[6] && analogRead(7) > threshold[7])
    {//w w b b b b b
      lsp = lfspeed; rsp = lfspeed;
      motor1.drive(lfspeed);
      motor2.drive(lfspeed);
    }
    
   else if (analogRead(1) < threshold[1] && analogRead(2) < threshold[2] && analogRead(3) < threshold[3] && analogRead(4) > threshold[4] && analogRead(5) > threshold[5] && analogRead(6) > threshold[6] && analogRead(7) > threshold[7])
    {//w w w b b b b
      lsp = lfspeed; rsp = 0;
      motor1.drive(lfspeed);
      motor2.drive(0);
    }
   else if (analogRead(1) < threshold[1] && analogRead(2) < threshold[2] && analogRead(3) < threshold[3] && analogRead(4) < threshold[4] && analogRead(5) > threshold[5] && analogRead(6) > threshold[6] && analogRead(7) > threshold[7])
    {//w w w w b b b
      lsp = lfspeed; rsp = 0;
      motor1.drive(lfspeed);
      motor2.drive(0);
    }
   else if (analogRead(1) < threshold[1] && analogRead(2) < threshold[2] && analogRead(3) < threshold[3] && analogRead(4) < threshold[4] && analogRead(5) < threshold[5] && analogRead(6) > threshold[6] && analogRead(7) > threshold[7])
    {//w w w w w b b
      lsp = lfspeed; rsp = 0;
      motor1.drive(lfspeed);
      motor2.drive(0);
    }
   else if (analogRead(1) < threshold[1] && analogRead(2) < threshold[2] && analogRead(3) < threshold[3] && analogRead(4) < threshold[4] && analogRead(5) < threshold[5] && analogRead(6) < threshold[6] && analogRead(7) > threshold[7])
    {//w w w w w w b
      lsp = lfspeed; rsp = 0;
      motor1.drive(lfspeed);
      motor2.drive(0);
    }    
    else if (analogRead(1) > threshold[1] && analogRead(2) > threshold[2] && analogRead(3) > threshold[3] && analogRead(4) > threshold[4] && analogRead(5) > threshold[5] && analogRead(6) > threshold[6] && analogRead(7) < threshold[7])
    {//b b b b b b w
      lsp = 0; rsp = lfspeed;
      motor1.drive(0);
      motor2.drive(lfspeed);    
    }
    else if (analogRead(1) > threshold[1] && analogRead(2) > threshold[2] && analogRead(3) > threshold[3] && analogRead(4) > threshold[4] && analogRead(5) > threshold[5] && analogRead(6) < threshold[6] && analogRead(7) < threshold[7])
    {//b b b b b w w
      lsp = 0; rsp = lfspeed;
      motor1.drive(0);
      motor2.drive(lfspeed); 
    }
    else if (analogRead(1) > threshold[1] && analogRead(2) > threshold[2] && analogRead(3) > threshold[3] && analogRead(4) > threshold[4] && analogRead(5) < threshold[5] && analogRead(6) < threshold[6] && analogRead(7) < threshold[7])
    {//b b b b w w w
      lsp = 0; rsp = lfspeed;
      motor1.drive(0);
      motor2.drive(lfspeed);    
    }
    else if (analogRead(1) > threshold[1] && analogRead(2) > threshold[2] && analogRead(3) > threshold[3] && analogRead(4) < threshold[4] && analogRead(5) < threshold[5] && analogRead(6) < threshold[6] && analogRead(7) < threshold[7])
    {//b b b w w w w
      lsp = 0; rsp = lfspeed;
      motor1.drive(0);
      motor2.drive(lfspeed);    
    }
    else if (analogRead(1) > threshold[1] && analogRead(2) > threshold[2] && analogRead(3) < threshold[3] && analogRead(4) < threshold[4] && analogRead(5) < threshold[5] && analogRead(6) < threshold[6] && analogRead(7) < threshold[7])
    {//b b w w w w w
      lsp = 0; rsp = lfspeed;
      motor1.drive(0);
      motor2.drive(lfspeed);    
    }
    else if (analogRead(1) > threshold[1] && analogRead(2) < threshold[2] && analogRead(3) < threshold[3] && analogRead(4) < threshold[4] && analogRead(5) < threshold[5] && analogRead(6) < threshold[6] && analogRead(7) < threshold[7])
    {//b w w w w w w
      lsp = 0; rsp = lfspeed;
      motor1.drive(0);
      motor2.drive(lfspeed);    
    }
    else if (analogRead(4) > threshold[4])
    {
      Kp = 0.0006 * (1000 - analogRead(4));
      Kd = 10 * Kp;
      //Ki = 0.0001;
      linefollow();
    }    
  }
}
}


void linefollow()
{
  int error = (analogRead(3) - analogRead(5));

  P = error;
  I = I + error;
  D = error - previousError;

  PIDvalue = (Kp * P) + (Ki * I) + (Kd * D);
  previousError = error;

  lsp = lfspeed - PIDvalue;
  rsp = lfspeed + PIDvalue;

  if (lsp > 255) {
    lsp = 255;
  }
  if (lsp < 0) {
    lsp = 0;
  }
  if (rsp > 255) {
    rsp = 255;
  }
  if (rsp < 0) {
    rsp = 0;
  }
  motor1.drive(lsp);
  motor2.drive(rsp);

}

void calibrate()
{
  for ( int i = 1; i < 8; i++)
  {
    minValues[i] = analogRead(i);
    maxValues[i] = analogRead(i);
  }
  
  for (int i = 0; i < 10000; i++)
  {
    motor1.drive(55);
    motor2.drive(-55);

    for ( int i = 1; i < 8; i++)
    {
      if (analogRead(i) < minValues[i])
      {
        minValues[i] = analogRead(i);
      }
      if (analogRead(i) > maxValues[i])
      {
        maxValues[i] = analogRead(i);
      }
    }
  }

  for ( int i = 1; i < 8; i++)
  {
    threshold[i] = (minValues[i] + maxValues[i]) / 2;
    Serial.print(threshold[i]);
    Serial.print("   ");
  }
  Serial.println();
  
  motor1.drive(0);
  motor2.drive(0);
}