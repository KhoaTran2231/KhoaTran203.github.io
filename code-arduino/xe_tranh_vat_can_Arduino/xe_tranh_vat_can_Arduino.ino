#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
const int trig = 6;     // chân trig của SRF-05.
const int echo = 5;     // chân echo của SRF-05.
int tien1=10;           // chân IN - A của Module L298.
int tien2=11;           // chân IN - C của Module L298.
int lui1=12;            // chân IN - D của Module L298.
int lui2=13;            // chân IN - B của Module L298.
int dongcoservo=9;      // chân Orange của Servo.
int gioihan = 60;
int i;
unsigned long thoigian; // biến đo thời gian
int khoangcach;           // biến lưu khoảng cách
int khoangcachtrai,khoangcachphai;
void dokhoangcach();
void dithang(int duongdi);
void disangtrai();
void disangphai();
void dilui();
void resetdongco();
void quaycbsangphai();
void quaycbsangtrai();
void tiensangtrai();
void tiensangphai();
void tudong();
void setup() {
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object
    pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
    pinMode(echo,INPUT);    // chân echo sẽ nhận tín hiệu  
    pinMode(tien1,OUTPUT); 
    pinMode(tien2,OUTPUT); 
    pinMode(lui1,OUTPUT); 
    pinMode(lui2,OUTPUT); 
    digitalWrite(tien1,LOW);
    digitalWrite(tien2,LOW);
    digitalWrite(lui1,LOW);
    digitalWrite(lui1,LOW);
    myservo.write(90);    
    Serial.begin(9600);
}
void loop() 
{
    tudong();
}
void dithang()
{ 
        digitalWrite(tien1,HIGH);
        digitalWrite(tien2,HIGH);
        Serial.println("đi thẳng");
}
void tiensangtrai()
{
  digitalWrite(tien1,HIGH);
    delay(200);
  digitalWrite(tien1,LOW);
}
void tiensangphai()
{
   digitalWrite(tien2,HIGH);
    delay(200);
  digitalWrite(tien2,LOW);
}
void disangtrai()
{
  resetdongco();
  digitalWrite(lui1,HIGH);
  delay(400);
  digitalWrite(lui1,LOW);
  Serial.println("trái");
}
void disangphai()
{
   resetdongco();
  digitalWrite(lui2,HIGH);
  delay(400);
  digitalWrite(lui2,LOW);
  Serial.println("phải");
}

void dilui()
{
  resetdongco();
  for(i=0;i<20;i++) 
        digitalWrite(lui1,HIGH);
        digitalWrite(lui2,HIGH);
        delay(1500);
    digitalWrite(lui1,LOW);
    digitalWrite(lui2,LOW);
    Serial.println("lùi");
}
void resetdongco()
{
  digitalWrite(tien1,LOW);
  digitalWrite(tien2,LOW);
  digitalWrite(lui1,LOW);
  digitalWrite(lui2,LOW);
}
void dokhoangcach()
{
    digitalWrite(trig,0);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig,1);   // phát xung từ chân trig
    delayMicroseconds(10);   // xung có độ dài 5 microSeconds
    digitalWrite(trig,0);   // tắt chân trig
    thoigian = pulseIn(echo,HIGH);  
    khoangcach = int(thoigian/2/29.412);
}
void quaycbsangtrai()
{
    myservo.write(180);              // tell servo to go to position in variable 'pos'
    delay(1000);
    dokhoangcach();
    myservo.write(90);              // tell servo to go to position in variable 'pos'  
}
void quaycbsangphai()
{
    myservo.write(0);              // tell servo to go to position in variable 'pos'
    delay(1000);
    dokhoangcach();
    myservo.write(90);              // tell servo to go to position in variable 'pos'
}
void resetservo()
{
   myservo.write(90);
}
void tudong()
{
  khoangcach=0;
    dokhoangcach();
       if(khoangcach>gioihan||khoangcach==0) 
        {
          dithang();   
        }   
    else
    {
      resetdongco();
      quaycbsangtrai();
      khoangcachtrai=khoangcach;
      quaycbsangphai();
      khoangcachphai=khoangcach;
      if(khoangcachphai<30&&khoangcachtrai<30){
        dilui();
      }
      else
      {
        if(khoangcachphai>khoangcachtrai) 
        {
          disangphai();
          delay(500);
        }
        if(khoangcachphai<khoangcachtrai) 
        {
          disangtrai();
          delay(500);
        }
      }
    }
}