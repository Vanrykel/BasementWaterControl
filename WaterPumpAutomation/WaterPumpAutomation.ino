// #define DEBUG_SERIAL_OUTPUT   // Uncomment line to enable serial output for debugging

const int Power = 6;          // Pin to source the pull-up resistor
const int waterSensor = 7;    // Pin to detect water
const int relayPin1 = 8;      // Pin for relay Live wire
const int relayPin2 = 9;      // Pin for relay Neutral wire

void setup() {
  pinMode(relayPin1, OUTPUT); // Live wire pin
  pinMode(relayPin2, OUTPUT); // Neutral wire pin

  pinMode(waterSensor, INPUT);
  
  pinMode(Power, OUTPUT);
  digitalWrite(Power, HIGH);  // Provide constant voltage
  
  #ifdef DEBUG_SERIAL_OUTPUT
    Serial.begin(9600);       // Start serial communication
    Serial.println("** Started monitoring **");
  #endif
}

void loop() {
  int waterDetected = digitalRead(waterSensor);
  
  if (waterDetected == LOW) {
    #ifdef DEBUG_SERIAL_OUTPUT
      Serial.println("Water detected!");
    #endif
    // Activate both relays 
    digitalWrite(relayPin1, LOW);
    digitalWrite(relayPin2, LOW);
    delay(8000);                  // Pump 8 seconds     
  } 
  else
  {
    #ifdef DEBUG_SERIAL_OUTPUT
      Serial.println("No water detected!");
    #endif   

    // Deactivate both relays
    digitalWrite(relayPin1, HIGH);
    digitalWrite(relayPin2, HIGH);
  }
}