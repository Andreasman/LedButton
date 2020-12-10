#include <Arduino.h>
#include<Bounce2.h>
#define LEDPIN 8
#define BUTTONPIN 9
  Bounce myButton;
    boolean buttonState = 0;
    long saveTime = 0;
    long delayTime = 5000;
void setup() {
  pinMode(LEDPIN, OUTPUT);
  myButton.attach(BUTTONPIN, INPUT_PULLUP);
  myButton.interval(5);
  
  Serial.begin(9600);

}
void loop() {
  myButton.update();
  if(myButton.fell()){
saveTime= millis();
    buttonState = !buttonState;
    Serial.println(buttonState);
  }

  digitalWrite(LEDPIN,buttonState);
  if(millis() >= saveTime + delayTime){
    buttonState = LOW;
  }
}