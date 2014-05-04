
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
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
  myservo.write(60);
} 
