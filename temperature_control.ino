// Hw7 Darui Zhang
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0;
const int controllerPin = A1;
const int redPin = 6;
const int bluePin = 7;

int formerTemperature;
int counter;
int temperature;
int tempSum;
boolean  heater;


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  counter=0;
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  tempSum=0;
  temperature=70;
  
}

void loop() {
  
      // UPDATE PARAMETERS
      
      int sensorVal = analogRead(sensorPin);
      
      float voltage = (sensorVal/1024.0) * 5.0;
      float temperatureC = (voltage - .5) * 100;
      int temperatureF = temperatureC*9/5 +32;
      tempSum=tempSum+temperatureF;
       // eliminate sensing value fluctuation
      if (counter==10){ 
      temperature = tempSum/10;
      counter=0;
      tempSum=0;
      }
      counter=counter+1;

      int controllerVal = analogRead(controllerPin);
      int desiredTemperature = map(controllerVal, 0, 1023, 90, 60);
      
      if (desiredTemperature>temperature){
      heater=true;
      }
      else{
      heater=false;
      }
      
      
  
      // RENDER    
      lcd.setCursor(0, 0);
      lcd.print("current:" );
      lcd.setCursor(10, 0);      
      lcd.print(temperature);
      lcd.setCursor(0, 1);
      lcd.print("desired:");
      lcd.setCursor(10, 1);
      lcd.print(desiredTemperature);
    
      if (heater==true){ 
       digitalWrite(redPin, HIGH);
       digitalWrite(bluePin, LOW);
      }
      else{
       digitalWrite(bluePin, HIGH);
       digitalWrite(redPin, LOW);
      }

       delay(50);
      
      }

