
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
Servo Xservo;                // a maximum of eight servo objects can be created 
Servo Yservo;
 
int pos;    // variable to store the servo position 
int pos2;
int curve = 3;
int start = 80;
int final = 100;
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Xservo.attach(8);
  Yservo.attach(7);
  Serial.begin(9600);
  myservo.write(40);
  for(pos = 44;pos <  50; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos); 
    Serial.println(pos) ;    // tell servo to go to position in variable 'pos' 
    delay(1000);    
  } 
} 
 
 
void loop() 
{
  for(pos = start; pos<final; pos+=1){
    if (pos == 80){
       pos2 = 93; 
    }
    if (pos == 83){
       pos2 = 92; 
    }
    if (pos == 86){
       pos2 = 91; 
    }
    if (pos == 90){
       pos2 = 90; 
    }
    Xservo.write(pos);
    Serial.println(pos2);
    Yservo.write(pos2);
    delay(50);
  }
  for(int pos = final; pos>start; pos-=1){
    if (pos == 90){
       pos2 = 90; 
    }
    if (pos == 93){
       pos2 = 91; 
    }
    if (pos == 96){
       pos2 = 92; 
    }
    if (pos == 100){
       pos2 = 93; 
    }
    Xservo.write(pos);
    Yservo.write(pos2);
    Serial.println(pos2);
    delay(50);
  }
  myservo.write(80);
  
} 
