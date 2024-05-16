// #define DEBUG_SERIAL_OUTPUT   // Uncomment line to enable serial output for debugging

const int waterSensor = 7;    // Pin to detect water
const int relayPin1 = 8;      // Pin for relay Live wire
const int relayPin2 = 9;      // Pin for relay Neutral wire

bool pumpActive = true;

unsigned long startTime = 0;

void setup() {
  pinMode(relayPin1, OUTPUT); // Live wire pin
  pinMode(relayPin2, OUTPUT); // Neutral wire pin

  pinMode(waterSensor, INPUT_PULLUP);
  
  #ifdef DEBUG_SERIAL_OUTPUT
    Serial.begin(9600);       // Start serial communication
    Serial.println("** Started monitoring **");
  #endif
}

void loop() {
  int waterDetected = digitalRead(waterSensor);
  
  if (waterDetected == LOW) {
    
    if (!pumpActive) {
      #ifdef DEBUG_SERIAL_OUTPUT
        Serial.println("Water detected");
      #endif
      startTime = millis();
      pumpActive = true;
    }
    
    if (pumpActive && (millis() - startTime) > 2000) {
      #ifdef DEBUG_SERIAL_OUTPUT
        Serial.println("Pump activated");
      #endif
      // Activate both relays 
      digitalWrite(relayPin1, LOW);
      digitalWrite(relayPin2, LOW);
      delay(10000);                  // Pump 10 seconds
    }     
  } 
  else
  {
    #ifdef DEBUG_SERIAL_OUTPUT
      if (pumpActive)
        Serial.println("No water detected!");
    #endif   

    pumpActive = false;

    // Deactivate both relays
    digitalWrite(relayPin1, HIGH);
    digitalWrite(relayPin2, HIGH);
  }
}