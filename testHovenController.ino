// Sample Arduino MAX6675 Arduino Sketch

#include "max6675.h"

int ktcSO = 8;
int ktcCS = 9;
int ktcCLK = 10;
int status = 0;

MAX6675 ktc(ktcCLK, ktcCS, ktcSO); //library to control the temp reader

void setup() {
  Serial.begin(9600);   //set speed
  delay(1000);
  pinMode(7, OUTPUT);   // connected to S terminal of Relay
  digitalWrite(7,HIGH); // turn relay ON
}

void loop() {
  float temp = ktc.readCelsius();
  if (temp > 60) {
    status = 1;
  }

  // check if starter is ON and if temperature is below 50 
  if (temp < 50 && status == 1 ){
    digitalWrite(7,LOW);// turn relay OFF
  }
  //print temperature in Celsius
  Serial.print(status);
  Serial.print(" Deg C = "); 
  Serial.println(temp);
  delay(1000);
}