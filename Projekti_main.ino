//Libraries
#include <Servo.h>

//Sensor
#define echoPin 10 // Echo Pin 
#define trigPin 9 // Trigger Pin 
#define vcc 8 
#define gnd 11 

//Servo
Servo myservo;

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int pos = 0;
int minimumRange = 15; // Minimum range needed 
long duration, distance; // Duration used to calculate distance 

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void setup() { 
 Serial.begin (9600); 
 pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT); 
 pinMode(vcc, OUTPUT) ; 
 pinMode(gnd, OUTPUT) ; 
 myservo.attach(6);
 
} 

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------  

void Drive(){
  myservo.write(144); // set servo to face left 54-degrees from forward
  delay(120); // wait 120milliseconds for servo to reach position
  for(pos = 144; pos >= 36; pos-=18)     // loop to sweep the servo (& sensor) from 144-degrees left to 36-degrees right at 18-degree intervals. 
  {
    myservo.write(pos);  // tell servo to go to position in variable 'pos' 
    delay(90); // wait 90ms for servo to get to position
    Sensor();

  if (distance <= minimumRange){
    Path();
    break;
  }
 }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void motorRight(){
  
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void motorLeft(){
  
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Sensor(){
  
//The following trigPin/echoPin cycle is used to determine the distance of the nearest object by bouncing soundwaves off of it. 
  
 while(!Serial.available()==0) {} 
  
 digitalWrite(vcc, HIGH); 
 delayMicroseconds(2); 
  
 digitalWrite(gnd, LOW); 
 delayMicroseconds(2); 
  
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
  
 digitalWrite(trigPin, HIGH); 
 delayMicroseconds(10); 
  
 digitalWrite(trigPin, LOW); 
 duration = pulseIn(echoPin, HIGH); 
  
 //Calculates distance (cm) based on the speed of sound
 distance = duration/58.2; 
 
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Path(){
    if (pos < 90) {
      motorRight();
      delay(500);
      }
    if (pos > 90) {
      motorLeft;
      delay(500);}
}

//MAIN LOOP-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void loop(){ 
  
  Drive();
  
}
