#include <Servo.h> 
 
Servo Xservo; 
Servo Yservo;  
 
void setup() 
{ 
  Xservo.attach(8);  // attaches the servo on pin 8 to the servo object 
  Yservo.attach(7);  // attaches the servo on pin 7 to the servo object 
} 
 
void go_to_pos(char* pos){
  if (pos = "btm"){
      Xservo.write(100);
      Yservo.write(92);
  }
}
 
void loop() 
{ 
  char pos[4] = "btm";
  go_to_pos(pos);
}
