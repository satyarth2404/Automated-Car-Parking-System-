#include<Servo.h>
Servo servo1;  
int trig=7;
int echo=9;
int trig1=6;
int echo1=5;
int c=0;
int servopos=0;
void setup() {
  pinMode(7,OUTPUT);
  pinMode(9,INPUT);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,INPUT);
  Serial.begin(9600);
  servo1.attach(12);
}
void loop() {
  int u = 0;
  int v = 0;
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  int duration=pulseIn(echo,HIGH);//duration for which echo pin is high
  int distance=(duration/(2*29.1));
    if(distance<10) {
   if((u ==0) && (digitalRead(4) == LOW)){
   c=c+1;
   }
   digitalWrite(4,HIGH);
    servo1.write(110);
    delay(10);
  }
  else
   {
    digitalWrite(4,LOW);
    servo1.write(20);
    u = 0;
   }
   Serial.println(c);
  digitalWrite(trig1,HIGH);
  delay(10);
  digitalWrite(trig1,LOW);
  int duration1=pulseIn(echo1,HIGH);//duration for which echo pin is high
  int distance1=(duration1/(2*29.1));
    if(distance1<10) {
     if((v==0) && (digitalRead(4)== LOW)){
   c=c-1;
     }
   digitalWrite(4,HIGH);
    delay(10);
  }
  else
   {
    digitalWrite(4,LOW);
    v=0;
   }
  delay(1000);
}
