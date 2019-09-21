#include <Joystick.h>

Joystick_ Joystick;
int xAxis = 0;
int xVal = 0;
int yAxis = 0;
int yVal = 0;

void setup() {
  // put your setup code here, to run once:
  // Initialize Button Pins
  pinMode(9, INPUT_PULLUP);
  Joystick.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  xAxis = analogRead(A1);
  // xVal = map(xAxis, 0, 1023, 255, 0);
  xVal = xAxis;
  Joystick.setXAxis(xVal);

  yAxis = analogRead(A2);
  // yVal = map(yAxis, 0, 1023, 255, 0);
  yVal = yAxis;
  Joystick.setYAxis(yVal);

  if (digitalRead(9) == LOW) {
    Joystick.pressButton(0);
  } else {
    Joystick.releaseButton(0);
  }

  delay(10);
}
