
#include <Servo.h>     
Servo servo1; /// che nắng cho cây
Servo servo2; /// xả thức ăn cho thú
int R1 =12; //khí lạnh
int R2 = 11; //khí nóng
int R3 = 10; //máy bơm tưới cây
int R4 = 9; //máy bơm nước cho thú
int b1= 2;
int b2 = 3;
int b3 = 4;
int b4 = 5;
int b5 =6;
int b6 = 7;
int s1 = A0; /// lm35
int s2 = A1; /// cảm biến hồng nhoại
int s3 = A2; /// cảm biến độ ẩm
int s4 = A3; /// cảm biến mực nước
int s5 = A4;
boolean gt1,gt2,gt3,gt4,gt5,gt6;
float temp,voltage;
int cb1,cb2,cb3,cb4,cb5;
void setup()
{
  servo1.attach(8);
  servo2.attach(13);
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(R3,OUTPUT);
  pinMode(R4,OUTPUT);
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);
  pinMode(b4,INPUT);
  pinMode(b5,INPUT);
  pinMode(b6,INPUT);
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  pinMode(s3,INPUT);
  pinMode(s4,INPUT);
  pinMode(s5,INPUT);
  Serial.begin(9600);
}
 void loop()
 {
   read();
   gt_nut();
   delay(200);
  if (gt1 ==1)
  {
  man();
  }
   else
   	{
     auto_R();
   	}
 }
 void gt_nut()
 {
gt1 = digitalRead(b1);
    gt2 = digitalRead(b2);
    gt3 = digitalRead(b3);
    gt4 = digitalRead(b4);
    gt5 = digitalRead(b5);
    gt6 = digitalRead(b6);
 }
void read()
{
  
  //lm35
  cb1 = analogRead(s1);
 voltage = cb1 * 3.3 / 1024.0;
  temp = voltage * 100.0;
  /// hồng ngoại
    cb2 = digitalRead(s2);
  /// hồng ngoại
  cb3 = analogRead(s3);
  /// mực nước
  cb4 = analogRead(s4);
    Serial.println(cb4);
}
void man()
{
     gt2_M();
     gt3_M();
     gt4_M();
     gt5_M();
     gt6_M();  
 }
void auto_R()
{
  lm35();
  hong_ngoai();
  do_am();
  muc_nuoc();
}
void gt2_M()
{
if ( gt2 ==1)
      {
       	digitalWrite(R1,HIGH);
      	
      }
     else
      {
       	digitalWrite(R1,LOW);
    
   	  }
}
void gt3_M()
{
if ( gt3 ==1)
      {
        digitalWrite(R3,HIGH);
      }
     else
      {
        digitalWrite(R3,LOW);
   	  }
}
void gt4_M()
{
  if ( gt4 ==1)
      {
        digitalWrite(R4,HIGH);
      }
     else
      {
        digitalWrite(R4,LOW);
   	  }
}
void gt5_M()
{
if ( gt5 ==1)
      {
       servo1.write(90);
      }
     else
      {
        servo1.write(0);
   	  }
}
void gt6_M()
{
if ( gt6 ==1)
      {
        servo2.write(90);
      }
     else
      {
        servo2.write(0);
   	  }
}
void lm35()
{
///lm35
  if ( temp>=50)
  {
    digitalWrite(R1,HIGH);
    digitalWrite(R2,LOW);
}
  else if(temp <=10)
  {
    digitalWrite(R1,LOW);
    digitalWrite(R2,HIGH);
  }
  else
  {
     digitalWrite(R1,LOW);
    digitalWrite(R2,LOW);
  }
}
void hong_ngoai()
{
 /// hn
  if (cb2 ==1)
  {
    servo1.write(90);
  }
  else
  {
     servo1.write(0);
  }
}
void do_am()
{
  ///độ ẩm
  if (cb3 <=200)
  {
    digitalWrite(R3,HIGH);
  }
  else if (cb3 >= 500)
  {
    digitalWrite(R3,LOW);
  }
  else 
  {
    digitalWrite(R3,LOW);
  }
}
void muc_nuoc()
{
/// mực nước
  if (cb4 <=100)
   {
    digitalWrite(R4,HIGH);
   }
  else if (cb4 >= 400)
   {
    digitalWrite(R4,LOW);
   }
  else
  {
     digitalWrite(R4,LOW);
  }
}