#include <Servo.h>

//Sensori
#define echoPin 10 // Echo Pin 
#define trigPin 9 // Trigger Pin 
#define jannite 8 
#define maa 11 

//Servo
Servo myservo; 

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int pos = 0;
int minimumRange = 15; // Sensorin minimietäisyys
long duration, distance, distance1, distance2; // Aika, joka käytetään etäisyyden mittaamiseen 
long aikaleima = 0; 

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void setup() { 
 Serial.begin (9600); 
 pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT); 
 pinMode(jannite, OUTPUT) ; 
 pinMode(maa, OUTPUT) ; 
 pinMode(LED_BUILTIN, OUTPUT);
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
    Suunta();
    delay(50);
    break;
  }
 }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Alarm (){

  myservo.write(pos=0);
  delay(1000);
  distance = distance1;
  delay(100);
  
  myservo.write(pos=180);
  delay(1000);
  distance = distance2;
  delay(100);

  myservo.write(pos=90);

  if (distance1 > distance2){
    
  }
  else{
    
  }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Sensor(){

    /* The following trigPin/echoPin cycle is used to determine the 
 distance of the nearest object by bouncing soundwaves off of it. */ 
  
 while(!Serial.available()==0) {} 
  
 digitalWrite(jannite, HIGH); 
 delayMicroseconds(2); 
  
 digitalWrite(maa, LOW); 
 delayMicroseconds(2); 
  
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
  
 digitalWrite(trigPin, HIGH); 
 delayMicroseconds(10); 
  
 digitalWrite(trigPin, LOW); 
 duration = pulseIn(echoPin, HIGH); 
  
 //Laskee etäisyyden (cm) äänennopeuden avulla 
 distance = duration/58.2; 
 
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Suunta(){
    if (pos < 90) {digitalWrite(LED_BUILTIN, HIGH);}
    if (pos > 90) {digitalWrite(LED_BUILTIN, HIGH);}
}

//MAIN LOOP-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void loop(){ 
  
  Drive();
  
}
