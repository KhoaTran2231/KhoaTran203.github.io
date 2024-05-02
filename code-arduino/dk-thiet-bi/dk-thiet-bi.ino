#include <IRremote.h>
const int RECV_PIN = 2;
const int pinLed1 = 4;
const int pinLed2 = 5;
const int pinLed3 = 6;
const int pinLed4 = 7;
int button1 = 3;
int button2 = 8;
int button3 = 9;
int button4 = 10;
int button5 = 11;
int TT1, TT2, TT3, TT4, TTT =0;
int BT = A0;
void setup() {
  Serial.begin(9600);
   pinMode( 3, INPUT_PULLUP);
   pinMode( 8, INPUT_PULLUP);
   pinMode( 9, INPUT_PULLUP);
   pinMode( 10, INPUT_PULLUP);
   pinMode( 11, INPUT_PULLUP);
   pinMode( A0, INPUT);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);
  IrReceiver.begin(RECV_PIN, true, 13); 
}

void loop() {
  /// giá trị độ nhạy của nút nhấn 1
  int h = analogRead(A0);
  h = map(h, 0, 1023, 0, 100);
  Serial.print("GIÁ TRỊ");
  Serial.println(h);
  // nút nhấn 1
  int NUTNHAN1 = digitalRead(button1);
 Serial.println(NUTNHAN1);
 delay(h);
 if (NUTNHAN1 == 1) // Có nhấn nút
  {
  if (TT1 == 0)
    {
      digitalWrite(pinLed1,HIGH);
      TT1 =1;
    }
  else 
  {
    digitalWrite(pinLed1,LOW);
     TT1 =0;
    }
  }
  /// giá trị đọ nhạy của nút nhấn 2
  int h2 =h-(h/2);
  ///nút nhấn 2
  int NUTNHAN2 = digitalRead(button2);
 Serial.println(NUTNHAN2);
 delay(h2);
 if (NUTNHAN2 == 1) // Có nhấn nút
  {
  if (TT2 == 0)
    {
      digitalWrite(pinLed2,HIGH);
      TT2 =1;
    }
  else 
  {
    digitalWrite(pinLed2,LOW);
     TT2 =0;
    }
  }
  /// giá trị đọ nhạy của nút nhấn 3
  int h3 =h-(h/3);
  ///nút nhấn 3
  int NUTNHAN3 = digitalRead(button3);
 Serial.println(NUTNHAN3);
 delay(h3);
 if (NUTNHAN3 == 1) // Có nhấn nút
  {
  if (TT3 == 0)
    {
      digitalWrite(pinLed3,HIGH);
      TT3 =1;
    }
  else 
  {
    digitalWrite(pinLed3,LOW);
     TT3 =0;
    }
  }
   /// giá trị đọ nhạy của nút nhấn 4
  int h4 =h-(h/4);
  ///nút nhấn 4
    int NUTNHAN4 = digitalRead(button4);
 Serial.println(NUTNHAN4);
 delay(h4);
 if (NUTNHAN4 == 1) // Có nhấn nút
  {
  if (TT4 == 0)
    {
      digitalWrite(pinLed4,HIGH);
      TT4 =1;
    }
  else 
  {
    digitalWrite(pinLed4,LOW);
     TT4 =0;
    }
  }
  ///nút nhấn tổng
     int NUTNHANT = digitalRead(button5);
 Serial.println(NUTNHANT);
delayMicroseconds(5);
 if (NUTNHANT == 1) // Có nhấn nút
  {
  if (TTT == 0)
    { 
      digitalWrite(pinLed1,HIGH);
      digitalWrite(pinLed2,HIGH);
      digitalWrite(pinLed3,HIGH);
      digitalWrite(pinLed4,HIGH);
      TTT =1;
    }
  else 
  { 
    digitalWrite(pinLed1,LOW);
    digitalWrite(pinLed2,LOW);
    digitalWrite(pinLed3,LOW);
    digitalWrite(pinLed4,LOW);
     TTT =0;
    }
  }
  /// điều khiển bằng remote
   if (IrReceiver.decode()) 
   {
    uint32_t dataRemote = IrReceiver.decodedIRData.decodedRawData;
      Serial.println(dataRemote);
      if (dataRemote>0) 
      {
        switch(dataRemote)
        {
          case 4077715200://so1
            digitalWrite(pinLed1, !digitalRead(pinLed1));
          break;
          case 3877175040://so2
            digitalWrite(pinLed2, !digitalRead(pinLed2));
          break;
          case 2707357440://so3
            digitalWrite(pinLed3, !digitalRead(pinLed3));
          break;
          case 4144561920://so4
            digitalWrite(pinLed4, !digitalRead(pinLed4));
          break;
          case 3108437760:// CH
          digitalWrite(pinLed1, !digitalRead(pinLed1));
          digitalWrite(pinLed2, !digitalRead(pinLed2));
          digitalWrite(pinLed3, !digitalRead(pinLed3));
          digitalWrite(pinLed4, !digitalRead(pinLed4));
          break;
        }
      }
      IrReceiver.resume(); // Cho phép nhận giá trị tiếp theo
   }    
}
