#define in1 4
#define in2 5
#define in3 6
#define in4 7
#define trig 2
#define echo 3

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int duration=0;
int pos = 0;    // variable to store the servo position
void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
    myservo.attach(9);
}

  float distance1=0;
float distance2=0;

void loop() {
 /* digitalWrite(trig,HIGH);
  delayMicroseconds(40);
  digitalWrite(trig,LOW);
  
int duration=pulseIn(echo,HIGH);
Serial.println(duration);
float distance=.0167*duration;
Serial.print("distance is ");
Serial.println(distance);
Serial.println(" cm");
forward();
if(distance<=5)
{
  backward();
}
*/
float distance0=dist();
Serial.println(distance0);

forward();

if(distance0<=50)
{
  stopp();
  delay(1000);

for (pos = 90; pos <= 180; pos += 1) 
{ // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
     
    
   // waits 15ms for the servo to reach the position
  }distance1=dist();
  for (pos = 180; pos >= 90; pos -=1) 
{ 
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
    
   // waits 15ms for the servo to reach the position
  }distance0=dist();
  for (pos = 90; pos >= 0; pos -=1) 
{ 
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
    
   // waits 15ms for the servo to reach the position
}distance2=dist();
   for (pos = 0; pos <=90; pos+=1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
   }
  if(distance0>60)
  {
    forward();
    delay(200);
  }
else if(distance1>distance2)
   {
    left();
    delay(200);
   }
   else if(distance1<distance2)
   {
    right();
    delay(200);
   }
   
  
}
}

void forward() {
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
}
/*void backward() {
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
}*/
void left()
{
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,0);
  digitalWrite(in4,0);
}
void right()
{
  digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
}

void stopp(){

   digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,0);
  
  }
float dist()
{
  digitalWrite(trig,HIGH);
      delayMicroseconds(40);
  digitalWrite(trig,LOW);
  
 duration=pulseIn(echo,HIGH);
Serial.println(duration);
float distance=.0167*duration;
return distance;
}
