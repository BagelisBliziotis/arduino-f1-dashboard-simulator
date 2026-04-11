#include <Servo.h>
int buzzpin = 9;
int buttonpin = 7;
int bluepin = 5;
int greenpin = 3;
int redpin = 6;
int poten = A2;
int potval;
int butval;
int brake;
int xaxis = A0;
int yaxis = A1;
int sw = 8;
int xval;
int yval;
Servo myservo;
int throtle;
int position;
int steering;
int warning = 0;
int servopin =2 ;
int dt =80;
void setup() {
 
 pinMode(buzzpin,OUTPUT);
 pinMode(buttonpin,INPUT);
 pinMode(poten,INPUT);
 pinMode(bluepin,OUTPUT);
 pinMode(redpin,OUTPUT);
 pinMode(greenpin,OUTPUT);
 myservo.attach(servopin);
 pinMode(xaxis,INPUT);
 pinMode(yaxis,INPUT);
 digitalWrite(buttonpin,HIGH);
 Serial.begin(9600);
}

void loop() {

  butval = digitalRead(buttonpin);
  
  potval = analogRead(poten);
  brake = (100.0/1023)*potval;
  
  xval = analogRead(xaxis);
  yval = 1023 - analogRead(yaxis);
  throtle = (100.0/1023)*yval;
  steering = (100.0/1023)*xval;
  Serial.print("Throttle: ");
  Serial.print(throtle);
  Serial.print("%");
  Serial.print(" Brake: ");
  Serial.print(brake);
  Serial.print("%");
  position = (180.0/100)*throtle;
  myservo.write(position);
  if(throtle<30){
    warning = 0;
    analogWrite(greenpin,255);
    analogWrite(redpin,0);
    analogWrite(bluepin,0);
  }
  else if(throtle>75){
    if(warning==0){
      digitalWrite(buzzpin,HIGH);
      delay(dt);
      warning =1;
    }
    analogWrite(redpin,255);
    analogWrite(bluepin,0);
    analogWrite(greenpin,0);
  }

  else{
    warning=0;
    analogWrite(greenpin,120);
    analogWrite(redpin,250);
    analogWrite(bluepin,0);
  }
  digitalWrite(buzzpin,LOW);
  Serial.print(" Steering: ");
  if(steering>65)
    Serial.println("Right");
  else if(steering<35)
    Serial.println("Left");
  else 
    Serial.println("Center");
  
  if(butval ==0){
    Serial.println("RESET");
    warning =0;
    delay(dt);
    while(butval!=1){
      butval = digitalRead(buttonpin);
    }
    }

  delay(dt);
  
  
  
  
  

}
