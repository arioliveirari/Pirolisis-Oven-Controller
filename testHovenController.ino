// Sample Arduino MAX6675 Arduino Sketch

#include "max6675.h"

int button = 3;
int ktcSO = 8;
int ktcCS = 9;
int ktcCLK = 10;
int status = 0;
int allowed = 0;


MAX6675 ktc(ktcCLK, ktcCS, ktcSO); //library to control the temp reader

void setup() {
  Serial.begin(9600);   //set speed
  delay(1000);
  pinMode(7, OUTPUT);   // connected to S terminal of Relay
  digitalWrite(7,LOW); // turn relay ON
  pinMode(button, INPUT); //reads digital pin 3 as input of button
}

void loop() {
  float temp = ktc.readCelsius();
  if (temp > 100) {
    status = 1;
  } 
  // read the state of the pushbutton value:
  int buttonState = digitalRead(button);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    allowed = 1;
    digitalWrite(7, HIGH);
    Serial.print("realy prendido");
  }

  // check if starter is ON and if temperature is below 50 
  if (temp < 50 && status == 1 ){
    digitalWrite(7,LOW);// turn relay OFF
    Serial.print(temp);
    Serial.print("TERMINO!");
  }
  //print temperature in Celsius
  Serial.print(status);
  Serial.print(" Deg C = "); 
  Serial.println(temp);
  Serial.print(allowed);
  delay(1000);
}
