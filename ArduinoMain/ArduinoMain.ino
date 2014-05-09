
/*Notes on user interface:

prefix letter: c -- servo command (int)
               s -- sensor values (,float,float....)
*/

#include <Servo.h> 
 
Servo Xservo; 
Servo Yservo; 
Servo motor;

int sensor_ports[6] = {A0,A1,A2,A3,A4,A5};
float m[6] = {17.868,29.429,48.02,26.061,22.507,26.336};         //slope of line to map from voltage to length = 
float b[6] = {-30.39,-61.68,-115.58,-51.49,-45.66,-57.77};       //mm
float k[6] = {.2467,.322,.2764,.2783,.2618,.246};                //mm
float sensor_length_orig[6] = {13.8,15.2,13,11.48,12.79,15.12};  //mm
float sensor_voltage;
float sensor_length;
float data_collect_time = 10;
float data_start_time;
int i;
float length;
float force;
int pos = 0;
int xpos;
int ypos;

void setup() 
{ 
  Xservo.attach(8);
  Yservo.attach(7); 
  motor.attach(9);
  delay(1000);
  //initialization sequence for motor to work
  motor.write(40);
  for(pos = 44;pos <  50; pos += 1)   
  {                                  
    motor.write(pos); 
    delay(100);    
  } 
  motor.write(44);
  
  Serial.begin(9600);

  delay(1000);
} 

//Calculates lengh of stretch sensor
float calculate_length(int sensor){
  sensor_voltage = (5.0 / 1023.0) * analogRead(sensor_ports[sensor]);
  sensor_length = m[sensor] * sensor_voltage + b[sensor];
  return sensor_length;
}

void go_to_pos(int posit){
  Serial.println();
  Serial.print("c");
  Serial.print(posit);
  if (posit == 1 || posit == 2 || posit == 3){ //x extreem high
    xpos = 126;
  }
  if (posit == 4 || posit == 5){ // x extreem low
    xpos = 74;
  }
  if (posit == 6 || posit == 7 || posit == 0){ //x neutral
    xpos = 100;
  }
  if (posit == 1 || posit == 6){//y extreem high
    ypos = 118;
  }
  if (posit == 2 || posit == 4 || posit == 7){//y extreem low
    ypos = 65;
  }
  if (posit == 3 || posit == 5 || posit == 0){//y neutral
    ypos = 92;
  }
  Xservo.write(xpos);
  Yservo.write(ypos);
    
}

//Collects analog in values and calculates the force
//based of thee length and k constant
void collect_data(){
  data_start_time = millis();
  while(millis()-data_start_time < data_collect_time*1000){
    Serial.println();
    Serial.print("s");
    for (i = 0; i < 6; i++){
      length = calculate_length(i);
      force = -k[i]*(sensor_length_orig[i]- length) / 2;   // converts the k from N/mm to N/m then calcs force
      Serial.print(",");
      Serial.print(force);
    }
  }
}
 
void loop() 
{ 
  motor.write(50);
  
  go_to_pos(pos);
  
  collect_data();
  
  go_to_pos(pos);

  collect_data();

  pos++;
  
  go_to_pos(0);
  
  collect_data();

  if (pos >6){
    pos = 0;
  }
  
}
