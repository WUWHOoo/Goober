#include <Arduino.h>

#if !defined(STM32H723xx)
#error Select an STM32H723 target in the STM32duino board menu.
#endif

// USB-only board check. The sketch never configures actuator outputs.
void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() && Serial.read() == '?') {
    Serial.print("Goober STM32H723 | uptime (ms) ");
    Serial.println(millis());
  }
}
