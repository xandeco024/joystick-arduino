#include <Arduino.h>
#include <Joystick.h>

// Create the Joystick object
Joystick_ Joystick;

// Define pins
const int X_AXIS_PIN = A0;
const int Y_AXIS_PIN = A1;
const int BUTTON_PIN = 2;

void setup() {
  // Initialize the joystick
  Joystick.begin();
  
  // Set up the button pin as input with pull-up resistor
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // Read button state (inverted because of pull-up)
  bool buttonState = !digitalRead(BUTTON_PIN);
  
  // Update joystick values
  Joystick.setXAxis(analogRead(X_AXIS_PIN));
  Joystick.setYAxis(analogRead(Y_AXIS_PIN));
  Joystick.setButton(0, buttonState);

  // Small delay to prevent too rapid updates
  delay(10);
}
