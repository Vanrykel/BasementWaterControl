const int relayPin1 = 8;     // Pin for relay Live wire
const int relayPin2 = 9;     // Pin for relay Neutral wire
unsigned long PumpTime = 0;  // Previous time

void setup() {
  pinMode(relayPin1, OUTPUT); // Live wire pin
  pinMode(relayPin2, OUTPUT); // Neutral wire pin
}

void loop() {
  unsigned long currentTime = millis();   // Get the current time in milliseconds
  
  if (currentTime >= PumpTime) {         // Check if an hour has passed
    PumpTime = currentTime + 3600000UL;  // Update the previous time
    
    // Activate both relays
    digitalWrite(relayPin1, LOW);
    digitalWrite(relayPin2, LOW);
    
    // Wait (pump) for 2 minutes (120000 milliseconds)
    delay(150000);
    
    // Deactivate both relays
    digitalWrite(relayPin1, HIGH);
    digitalWrite(relayPin2, HIGH);
  }
}