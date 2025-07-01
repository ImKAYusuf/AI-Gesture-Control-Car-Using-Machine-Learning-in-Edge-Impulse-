#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); 
char tiltDirection;
int motorInput1 = 5;
int motorInput2 = 6;
int motorInput3 = 7;
int motorInput4 = 8;
void setup() {
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(motorInput3, OUTPUT);
  pinMode(motorInput4, OUTPUT);
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);

  Serial.begin(115200);      
  BTSerial.begin(9600);    
}
void loop() {
  if (BTSerial.available()) {   
    tiltDirection = BTSerial.read();
    if(tiltDirection == 'F'){
      Serial.println(" reverse");
       reverse();
    }else if(tiltDirection == 'B'){
      Serial.println("Forward");
      forward();
    }else if(tiltDirection == 'R'){
      Serial.println("Left");
      left();
    }else if(tiltDirection == 'L'){
      Serial.println("Right");
      right();
    }else if(tiltDirection == 'S'){
      Serial.println("Stop");
      stopCar();
    }else if(tiltDirection == 'C'){
      Serial.println("Rotate");
      Rotate();
    }else if(tiltDirection == 'K'){
      Serial.println("Square");
      Square();
    }
  }
}
void forward()
{
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}
void reverse()
{
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
}
void right()
{
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
}
void left()
{
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}

void stopCar() {
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
}
void Rotate() {
  left();
  delay(5000);
}
void Square() {
  left();
  delay(2000);
left();
  delay(2000);
left();
  delay(2000);
left();
  delay(2000);  
}
