#include<Servo.h>
Servo myServo;
const int switchPin=2;
const int tiltPin=4;
boolean locked = false;
boolean alarmed = false;
int switchVal=0;
int tiltVal=0;
int yello = 3;
int red = 6;
int green = 5;

void setup(){
myServo.attach(9);
pinMode(switchPin,INPUT);
pinMode(tiltPin,INPUT);
pinMode(green,OUTPUT);
pinMode(red,OUTPUT);
pinMode(yello,OUTPUT);
digitalWrite(red,LOW);
Serial.begin(9600);
}

void loop(){
switchVal=digitalRead(switchPin);
if(switchVal==HIGH){
  locked=~locked;
  delay(300); // filter button noise
}

if(locked==false){
  myServo.write(0);
  digitalWrite(yello,LOW);
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  alarmed=LOW;
  }else{
   myServo.write(90);
   digitalWrite(yello,HIGH);    // lock is active
   tiltVal=digitalRead(tiltPin);
   //digitalWrite(green,HIGH);
   Serial.println(tiltVal);
     if(tiltVal==LOW){
       delay(30); // filter tilt senser noise
       tiltVal=digitalRead(tiltPin);
       if(tiltVal==LOW){
         alarmed=HIGH;
       }
      }
      if(alarmed==HIGH){
      digitalWrite(red,HIGH);
      digitalWrite(green,LOW);
      }
      else{
      digitalWrite(green,HIGH);
      digitalWrite(red,LOW);
      }
      
 }
  

}
