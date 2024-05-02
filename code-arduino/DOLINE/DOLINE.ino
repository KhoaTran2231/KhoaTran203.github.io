int s1 =A0;
int s2= A1;
int s3= A2;
int s4= A3;
int s5= A4;
int ENA = 6;
int in1 =7;
int in2 = 8;
int in3 = 9;
int in4 = 10;
int ENB = 11;
int L=100;
int R=100;
int gt1, gt2,gt3,gt4,gt5;
bool tgt=0;
bool tgp=0;
int i=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ENA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENB,OUTPUT);
Serial.begin(9600);
}

void loop() {
doline();
if((gt1 == 1) && (gt2 == 1) && (gt3 == 1) && (gt4 == 1) && (gt5 == 1) )
{
for(i=50;i>=R;i--){
        digitalWrite(in3, HIGH);
        digitalWrite(in1, HIGH);
        digitalWrite(in4, LOW);
        digitalWrite(in2, LOW);
        analogWrite(ENB, i); 
        analogWrite(ENA, i); 
        delay(5);
    }
}
 else if((gt1 == 0) && (gt2 == 0) && (gt3 == 0) && (gt4 == 0) && (gt5 == 0) )
{
      for(i=50;i>=R;i--){
        digitalWrite(in3, HIGH);
        digitalWrite(in1, HIGH);
        digitalWrite(in4, LOW);
        digitalWrite(in2, LOW);
        analogWrite(ENB, i); 
        analogWrite(ENA, i); 
        delay(5);
    }
}
 else if((gt1 == 0) && (gt2 == 0) && (gt3 == 1) && (gt4 == 0) && (gt5 == 0) )
{
  tien();
}
else if ((gt1 == 0) && (gt2 == 1) && (gt3 == 0) && (gt4 == 0) && (gt5 == 0) )
{
  phai_2();
  delay(30);
}
else if ((gt1 == 1) && (gt2 == 1) && (gt3 == 0) && (gt4 == 0) && (gt5 == 0) )
{
  trai_3();
  delay(70);
}
else if ((gt1 == 1) && (gt2 == 0) && (gt3 == 0) && (gt4 == 0) && (gt5 == 0) )
{
  trai_v();
  delay(70);
}
else if ((gt1 == 1) && (gt2 == 0) && (gt3 == 0) && (gt4 == 0) && (gt5 == 1) )
{
  phai_3();
  delay(50); 
}
else if ((gt1 == 0) && (gt2 == 0) && (gt3 == 0) && (gt4 == 1) && (gt5 == 1) )
{
  phai_2();
  delay(50); 
}
else if ((gt1 == 1) && (gt2 == 0) && (gt3 == 0) && (gt4 == 1) && (gt5 == 1) )
{
  phai_3();
  delay(50); 
}
else if ((gt1 == 0) && (gt2 == 1) && (gt3 == 1) && (gt4 == 0) && (gt5 == 0) )
{
  trai_1();
  delay(30);
}
else if ((gt1 == 0) && (gt2 == 1) && (gt3 == 0) && (gt4 == 1) && (gt5 == 5) )
{
  trai_1();
  delay(30);
}
else if ((gt1 == 0) && (gt2 == 1) && (gt3 == 0) && (gt4 == 0) && (gt5 == 1) )
{
  trai_1();
  delay(30);
}
else if ((gt1 == 0) && (gt2 == 0) && (gt3 == 0) && (gt4 == 1) && (gt5 == 0) )
{
 trai_1();
  delay(30);
}
else if ((gt1 == 1) && (gt2 == 1) && (gt3 == 0) && (gt4 == 0) && (gt5 == 1) )
{
 phai_2();
  delay(30);
}
else if ((gt1 == 0) && (gt2 == 1) && (gt3 == 0) && (gt4 == 1) && (gt5 == 0) )
{
 trai_2();
  delay(30);

}
else if ((gt1 == 1) && (gt2 == 1) && (gt3 == 0) && (gt4 == 1) && (gt5 == 0 ) )
{
 trai_3();
  delay(30);

}
else if ((gt1 == 0) && (gt2 == 0) && (gt3 == 1) && (gt4 == 1) && (gt5 == 0) )
{
  phai_2();
  delay(50);
 
}
else if ((gt1 == 0) && (gt2 == 0) && (gt3 == 0) && (gt4 == 0) && (gt5 == 1) )
{
  phai_v();
  delay(50);

}
else if ((gt1 == 0) && (gt2 == 1) && (gt3 == 1) && (gt4 == 1) && (gt5 == 0) )
{
 tien();
  delay(30);
  
}
else if ((gt1 == 1) && (gt2 == 1) && (gt3 == 1) && (gt4 == 0) && (gt5 == 0) )

{

     for(i=R;i>=0;i--){
        digitalWrite(in3, HIGH);
        digitalWrite(in1, HIGH);
        digitalWrite(in4, LOW);
        digitalWrite(in2, LOW);
        analogWrite(ENB, i); 
        analogWrite(ENA, i); 
        delay(1);
    }// Giảm tốc từ Max >> Min
  trai_v();
  delay(50);
}

else if ((gt1 == 1) && (gt2 == 1) && (gt3 == 1) && (gt4 == 1) && (gt5 == 0) )

{

     for(i=R;i>=0;i--){
        digitalWrite(in3, HIGH);
        digitalWrite(in1, HIGH);
        digitalWrite(in4, LOW);
        digitalWrite(in2, LOW);
        analogWrite(ENB, i); 
        analogWrite(ENA, i); 
        delay(1);
    }// Giảm tốc từ Max >> Min
  trai_v();
  delay(150);
}
else if ((gt1 == 0) && (gt2 == 0) && (gt3 == 1) && (gt4 == 1) && (gt5 == 1) )
{
     for(i=R;i>=0;i--){
        digitalWrite(in3, HIGH);
        digitalWrite(in1, HIGH);
        digitalWrite(in4, LOW);
        digitalWrite(in2, LOW);
        analogWrite(ENB, i); 
        analogWrite(ENA, i); 
        delay(1);
    }// Giảm tốc từ Max >> Min
    phai_v();
if((gt1 == 0) && (gt2 == 1) && (gt3 == 1) && (gt4 == 1) && (gt5 == 0))
{
  phai_v();
}
else if((gt1 == 1) && (gt2 == 1) && (gt3 == 1) && (gt4 == 0) && (gt5 == 0))
{
  phai_v();
}
else
{
  stop();
}
}
else if ((gt1 == 0) && (gt2 == 1) && (gt3 == 1) && (gt4 == 1) && (gt5 == 1) )

{
     for(i=R;i>=0;i--){
        digitalWrite(in3, HIGH);
        digitalWrite(in1, HIGH);
        digitalWrite(in4, LOW);
        digitalWrite(in2, LOW);
        analogWrite(ENB, i); 
        analogWrite(ENA, i); 
        delay(1);
    }// Giảm tốc từ Max >> Min
      
    phai_v();
    delay(150);
  Serial.println("1");
}
else {
  stop();
}
}
void doline()
{
  
 gt1 =digitalRead(s1);
 gt2 =digitalRead(s2);
 gt3 =digitalRead(s3);
 gt4 =digitalRead(s4);
 gt5 =digitalRead(s5);
}
void tien()
{
  analogWrite(ENB,R);
  analogWrite(ENA,L);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void stop()
{
  analogWrite(ENB,0);
  analogWrite(ENA,0);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
void phai_v()
{
  analogWrite(ENB,255);
  analogWrite(ENA,255);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void phai_1()
{
  analogWrite(ENB,R-20);
  analogWrite(ENA,L);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void phai_2()
{
  analogWrite(ENB,R-50);
  analogWrite(ENA,L+5);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void phai_3()
{
  analogWrite(ENB,R);
  analogWrite(ENA,L);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
void trai_v()
{
  analogWrite(ENB,255);
  analogWrite(ENA,255);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void trai_1()
{
  analogWrite(ENB,R-10);
  analogWrite(ENA,L-20);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void trai_2()
{
   analogWrite(ENB,R-5);
  analogWrite(ENA,L-40);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void trai_3()
{
   analogWrite(ENB,R);
  analogWrite(ENA,L);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void lui()
{
   for(i=255;i==0;i--)
   {
  analogWrite(ENB,i);
  analogWrite(ENA,i);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  delay(100);
   }
}
void back()
{
  analogWrite(ENB,R);
  analogWrite(ENA,L);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
