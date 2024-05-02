
#include <Servo.h>
int cb1 = 2;
int cb2 = 3;
int servo = 6; // Khai báo chân tín hiệu chân 6

Servo myServo; // Khai báo tên biến cho động cơ Servo

void setup()
{
  myServo.attach(servo); // khai báo động cơ Servo tương tự lệnh Pinmode()
}

void loop()
{
  int gt1 = digitalRead(cb1);
  int gt2 = digitalRead(cb2);
   delay(500);
  if (gt1 == 0)
  {
      myServo.write(90); //Điều khiển Servo đến góc 0 độ.
    goc = myServo.read(); // Đọc góc hiện tại của Servo
   
    
  }
  else if (gt2 ==0)
  {
    myServo.write(90); //Điều khiển Servo đến góc 0 độ.
    goc = myServo.read(); // Đọc góc hiện tại của Servo

    
  }
  else 
  {
    myServo.write(180);//Điều khiển Servo đến góc 180 độ.
    goc = myServo.read();
  }
  
}
