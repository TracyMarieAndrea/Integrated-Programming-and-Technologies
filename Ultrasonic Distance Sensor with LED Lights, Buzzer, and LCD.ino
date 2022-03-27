#include <LiquidCrystal.h>
LiquidCrystal lcd = LiquidCrystal(7,6,2,3,4,5); // Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):
const int trigPin = 9;
const int echoPin = 8;
const int red=13;
const int yellow=12;
int green=11;
int pink=10;

void setup() 
{
    lcd.begin(16, 2); // Specify the LCD's number of columns and rows. Change to (20, 4) for a 20x4 LCD
    pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
	Serial.begin(9600);
  
  	pinMode(red,OUTPUT);
  	pinMode(yellow,OUTPUT);
  	pinMode(green,OUTPUT);
  	pinMode(pink,OUTPUT);
}

void loop() 
{
  long duration;
  float inches, cm;
  
digitalWrite(trigPin, LOW);  
delayMicroseconds(2);  
digitalWrite(trigPin, HIGH);  
delayMicroseconds(10);  
digitalWrite(trigPin, LOW);  

duration = pulseIn(echoPin, HIGH);  

 // convert the time into a distance
 inches = microsecondsToInches(duration);
 cm = microsecondsToCentimeters(duration);
  
  // For Serial Monitor
  Serial.print("Distance: ");
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

 // For LCD Display
lcd.setCursor(0,0);
lcd.print("Distance in CM");
lcd.setCursor(0,1);
lcd.print(cm);
lcd.print(" cm");
  
 if(cm<10){
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(yellow,LOW);
    tone(pink, 400, 100);
  }
  else if (cm>11 && cm<20){
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(yellow,HIGH); 
  }
  
  else if(cm>20){ 
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(yellow,LOW); 
  }
  
}
float microsecondsToInches(float microseconds) {

  return microseconds / 74 / 2;
}

float microsecondsToCentimeters(float microseconds) {

  return microseconds / 29 / 2;
}  
  

  
  

