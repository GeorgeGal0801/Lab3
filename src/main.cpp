#include <Arduino.h>

// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  DDRD &= 0xF0;
  PORTD |= 0xF0;

  DDRB |= 0x0F;
  PORTB &= ~0x0F;

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t value=PIND;
          value = value & 0xF0;
          value = value >> 4;
          value = ~value;
          value = value & 0x0F;
          
  PORTB=(PORTB&~0x0F)|value;
  Serial.println(value);

}

// put function definitions here:

