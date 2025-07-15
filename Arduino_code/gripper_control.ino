/*
  Servo Control via Serial Monitor
  
  Description:
  This code allows you to control a servo motor connected to an Arduino Uno.
  - The servo is attached to pin 9.
  - By opening the Serial Monitor and typing "open", the servo rotates to 180 degrees.
  - By typing "close", the servo rotates to 0 degrees.

  Hardware:
  - Arduino Uno
  - Servo Motor
  - Jumper Wires

  Wiring:
  - Servo Signal Pin -> Arduino Pin 9
  - Servo VCC Pin    -> Arduino 5V
  - Servo GND Pin    -> Arduino GND
*/

// Include the standard Servo library
#include <Servo.h>

// Create a servo object to control the servo
Servo myServo;

// Define the pin the servo's signal wire is connected to
const int servoPin = 9;

// Define the angles for the "open" and "close" positions
// Standard servos have a range from 0 to 180 degrees.
const int openPosition = 180;
const int closePosition = 0;

void setup() {
  // Start the serial communication at a 9600 baud rate.
  // This is how the Arduino communicates with your computer.
  Serial.begin(9600);

  // Attach the servo object to the pin
  myServo.attach(servoPin);

  // Set the servo to the initial "close" position when the Arduino starts
  myServo.write(closePosition);
  
  // Print instructions to the Serial Monitor for the user
  Serial.println("Servo Control Initialized");
  Serial.println("-------------------------");
  Serial.println("Type 'open' to move to 180 degrees.");
  Serial.println("Type 'close' to move to 0 degrees.");
  Serial.println("-------------------------");
}

void loop() {
  // Check if there is any data available to read from the serial port
  if (Serial.available() > 0) {
    
    // Read the incoming command as a String until a newline character is received
    // (This happens when you press Enter in the Serial Monitor)
    String command = Serial.readStringUntil('\n');

    // Remove any leading/trailing whitespace from the command
    command.trim();

    // Use equalsIgnoreCase to make the command case-insensitive (e.g., "Open" or "OPEN" will also work)
    if (command.equalsIgnoreCase("open")) {
      Serial.println("Command received: open. Moving servo.");
      myServo.write(openPosition); // Tell the servo to go to the 'open' position (180 degrees)
    } 
    else if (command.equalsIgnoreCase("close")) {
      Serial.println("Command received: close. Moving servo.");
      myServo.write(closePosition); // Tell the servo to go to the 'close' position (0 degrees)
    } 
    else {
      // If the command is not recognized, print an error message
      Serial.print("Unknown command: '");
      Serial.print(command);
      Serial.println("'. Please use 'open' or 'close'.");
    }
  }
}
