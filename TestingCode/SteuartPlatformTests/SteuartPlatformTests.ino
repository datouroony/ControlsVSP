#include <Servo.h>

// What pin to connect the sensor to
#define SENSOR0 A0
#define SENSOR1 A1
#define SENSOR2 A2

Servo motor;
int motorSpeed;

float S0Length0 = 17.9; //mm
float S1Length0 = 17.8;
float S2Length0 = 17.4;
float S0Resistance0 = 70; //ohm 77
float S1Resistance0 = 71;
float S2Resistance0 = 77;
float Resistor = 76.8;
float SensorResistance0;
float SensorResistance1;
float SensorResistance2 ;
float S0V;
float S1V;
float S2V;
float S0Length;
float S1Length;
float S2Length;

void setup(void) {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
}

void loop(void) {

  S0V = (1023.0 / analogRead(SENSOR0)) - 1.0;
  S1V = (1023.0 / analogRead(SENSOR1)) - 1.0;
  S2V = (1023.0 / analogRead(SENSOR2)) - 1.0;

  // convert the value to resistance
  SensorResistance0 =  Resistor / S0V;
  SensorResistance1 =  Resistor / S1V;
  SensorResistance2 =  Resistor / S2V;
  S0Length = (SensorResistance0 / S0Resistance0) * S0Length0;
  S1Length = (SensorResistance1 / S1Resistance0) * S1Length0;
  S2Length = (SensorResistance2 / S2Resistance0) * S2Length0;

  Serial.print("S0 :   ");
  Serial.println(S0Length);
  Serial.print("S1 :   ");
  Serial.println(S1Length);
  Serial.print("S1 :   ");
  Serial.println(S1Length);
  //Serial.print("SENSOR LENGHT");
  //Serial.println(S0Length);
  //length = (.0356 * resistance) - 2.627; //2.727
  
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(50);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(50);                       // waits 15ms for the servo to reach the position 
  }

}
