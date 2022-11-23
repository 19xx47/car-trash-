#include<Servo.h>
Servo servo;
long cm = 0;

int m1a = 9;
int m1b = 10;
int m2a = 11;
int m2b = 12;
int sound = 7;
int st = 0;
int cont = 0;

char val;

long Distance(int TRIG_PIN, int ECHO_PIN)
{
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  pinMode(ECHO_PIN, INPUT);
  return (pulseIn(ECHO_PIN, HIGH)*0.01732);
  
}

void setup() 
{  
 pinMode(m1a, OUTPUT);  // Digital pin 10 set as output Pin
 pinMode(m1b, OUTPUT);  // Digital pin 11 set as output Pin
 pinMode(m2a, OUTPUT);  // Digital pin 12 set as output Pin
 pinMode(m2b, OUTPUT);  // Digital pin 13 set as output Pin
 pinMode(sound, INPUT);
 servo.attach(2);
 Serial.begin(9600);
}
void stop()
{
 digitalWrite(m1a, LOW);
 digitalWrite(m1b, LOW);
 digitalWrite(m2a, LOW);
 digitalWrite(m2b, LOW);  
 delay(1500);
}

void Forward()
{
 digitalWrite(m1a, HIGH);
 digitalWrite(m1b, LOW);
 digitalWrite(m2a, HIGH);
 digitalWrite(m2b, LOW);  
 delay(1500);
}
void Backward()
{
digitalWrite(m1a, LOW);
digitalWrite(m1b, HIGH);
digitalWrite(m2a, LOW);
digitalWrite(m2b, HIGH); 
delay(1500);

}
void Left()
{
 digitalWrite(m1a, LOW);
 digitalWrite(m1b, LOW);
 digitalWrite(m2a, HIGH);
 digitalWrite(m2b, LOW);
 delay(500);
}
void Right()
{
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    delay(500);

}

void loop()
{
  cm = Distance(4,3);
  if (cm < 15 ) {
    servo.write(90);
    delay(2000);
    servo.write(0);
    delay(1000);
  }
  else {
    servo.write(0);
  }
//put your main code here,to run repeatedly;
 if(digitalRead(sound) == HIGH)
 {
   
   Forward();
   delay(1000);
   stop();
   
 }else{
   
 stop();
   
 }
}
