// servo_test.ino

#include <Servo.h> 
 
Servo servo1;  // create servo object to control a servo 
Servo servo2;  // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  servo1.attach(9);  // attaches the servo on pin 9 to the servo object 
  servo2.attach(10);
} 
 
 
void loop() 

servo1.write(90);
servo2.write(90);
//runs 1 servo while other is neutral at a time
{ 
  for(pos = 20; pos < 60; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  //want to go back to neutral
  for(pos =  60; pos>=40; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 

    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 20; pos < 60; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servo2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  //want to go back to neutral
  for(pos =  60; pos>=40; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo2.write(pos);              // tell servo to go to position in variable 'pos' 

    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
} 



