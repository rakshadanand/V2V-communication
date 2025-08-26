#include <LiquidCrystal.h> //library for LCD
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 12, 8, 9, 10, 11);
 //LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


int sensorPin = A0;    // select the input pin for the potentiometer
int relay1 = 4;      // select the pin for the LED
int relay2 = 5;
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {

   Serial.begin(9600); 
  // declare the ledPin as an OUTPUT:
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on

  Serial.print("sensorValue ===: ");
  Serial.println(sensorValue);
 delay(500);


lcd.clear();//clearing the LCD display
  lcd.display();//Turning on the display again

 
 
 lcd.setCursor(1,1);//Setting cursor on LCD
 lcd.print("V2V com - LiFi");//Prints on the LCD
     
  delay(500);
  
  if( sensorValue<1000)
  {
     digitalWrite(relay1, HIGH);
     digitalWrite(relay2, LOW);

      Serial.print("Object Detected");
      delay(500);

     lcd.clear();//clearing the LCD display
     lcd.display();//Turning on the display again
     lcd.setCursor(1,0);//Setting cursor on LCD
     lcd.print("Object Not Detected");//prints on LCD
     
     delay(1000);
  }
  else
  {
    Serial.print("Object NOT Detected");
    digitalWrite(relay1, LOW);
     digitalWrite(relay2, HIGH);
  lcd.clear();//clearing the LCD display
     lcd.display();//Turning on the display again
     lcd.setCursor(1,0);//Setting cursor on LCD
     lcd.print("Object Detected");//prints on LCD
     
     delay(1000);
      delay(500);
  }
  
  
}
