// plottingdata_and_movingservos.ino

#include <Servo.h> 

Servo servo1;  // create servo object to control a servo 
Servo servo2;  // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() {
//init serial comms
Serial.begin(9600);
// attaches the servos on pin 9 and 10 to the servo object 
  servo2.attach(10);
  servo1.attach(9);  
}

void loop() {
//read A0
int val1 = analogRead(0);
int val2 = analogRead(1);

Serial.print(val1);
Serial.print(" ");
Serial.print(val2);
Serial.print("\n");
//wait
delay(50);

for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 
    servo2.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 
    servo2.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 

}

