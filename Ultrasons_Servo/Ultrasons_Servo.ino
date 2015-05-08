#include <Servo.h>

const int trigger = 7;
const int echo = 6;
int val;
Servo servo;

void setup()
  {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  servo.attach(8);
  Serial.begin(9600);
  }
void loop()
  {
    long duration, cm;

  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger, LOW);

  duration = pulseIn(echo, HIGH);
  
  cm = microsecondsToCentimeters(duration);
  
  if(cm > 50)
    {
      servo.write(180);
    }
    
      val = map(cm, 0, 50, 0, 180);            
      servo.write(val);
   
  Serial.print(cm);
  Serial.print(" cm ");
  Serial.println(val);
}
  
  long microsecondsToCentimeters(long microseconds)
  {
  return microseconds / 29 / 2;
  }
  
  
  
