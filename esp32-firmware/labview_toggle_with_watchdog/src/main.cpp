#include <Arduino.h>

const int ledPin = 2; // Internal LED

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, HIGH);
  delay(2000);
  digitalWrite(ledPin, LOW);
}

void loop() {

  // Wait until LabVIEW sends us a command
  if (Serial.available() > 0) {
    
    // Read the incoming character
    char command = Serial.read();
    
    // Drain the rest of the buffer
    while(Serial.available() > 0) { 
      Serial.read(); 
      delay(2); 
    }
    
    // Execute and Respond
    if (command == '1') {
      digitalWrite(ledPin, HIGH);
      Serial.println("ACK_1"); // Send confirmation back to LabVIEW
    } 
    else if (command == '0') {
      digitalWrite(ledPin, LOW);
      Serial.println("ACK_0"); // Send confirmation
    } 
    else if (command == '?') {
      Serial.println("ALIVE"); // Heartbeat response
    }
  }
}