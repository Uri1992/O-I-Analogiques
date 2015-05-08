const int trigger = 7;
const int echo = 6;
int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;
int led5 = 13;

void setup() {

  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
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
  
  if (cm <= 4){
    digitalWrite(led1, HIGH);
  }
    else{
      digitalWrite(led1, LOW);
    }
    
    if (cm <= 8){
    digitalWrite(led2, HIGH);
  }
    else{
      digitalWrite(led2, LOW);
    }
    
    if (cm <= 12){
    digitalWrite(led3, HIGH);
  }
    else{
      digitalWrite(led3, LOW);
    }
    
    if (cm <= 16){
    digitalWrite(led4, HIGH);
  }
    else{
      digitalWrite(led4, LOW);
    }
    
    if (cm <= 20){
    digitalWrite(led5, HIGH);
  }
    else{
      digitalWrite(led5, LOW);
    }
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(100);
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
