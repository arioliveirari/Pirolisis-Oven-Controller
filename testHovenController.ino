// Sample Arduino MAX6675 Arduino Sketch

#include "max6675.h"

int ktcSO = 8;
int ktcCS = 9;
int ktcCLK = 10;
int starter  = A0;

MAX6675 ktc(ktcCLK, ktcCS, ktcSO); //library to control the temp reader

void setup() {
  Serial.begin(9600);   //set speed
  delay(1000);
  pinMode(7, OUTPUT);   // connected to S terminal of Relay
  digitalWrite(7,HIGH); // turn relay ON
}

void loop() {

  int analogValue = analogRead(starter);    //read analog value of A0 pin
  float voltage = analogValue * (5.0 / 1023.0); //convert A0 reading to voltage

  // check if starter is ON and if temperature is below 50 
  if (ktc.readCelsius() < 50 && voltage > 3.2 ){
    digitalWrite(7,LOW);// turn relay OFF
  }
  //print temperature in Celsius
  Serial.print("Deg C = "); 
  Serial.println(ktc.readCelsius());
  delay(2000);
}