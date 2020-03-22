#include<Servo.h>
#define trigpin D6
#define echopin D5


int dist;
int durat;
Servo servo1;

void setup() {
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
servo1.attach(4); //D2
Serial.begin(9600);
}

void loop() {
digitalWrite(trigpin,LOW);
delay(2);
digitalWrite(trigpin,HIGH);
delay(10);
digitalWrite(trigpin,LOW);
durat=pulseIn(echopin,HIGH);
dist=durat*0.0342/2;
Serial.print("Distance=");
Serial.println(dist);

if(dist<20)
{

 servo1.write(120);
 delay(100);
}
else
{
  servo1.write(0);

}
}

