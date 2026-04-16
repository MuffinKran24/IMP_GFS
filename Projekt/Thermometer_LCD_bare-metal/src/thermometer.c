// Das Thermometer mit so wenigen Bibliotheken und so direkt wie möglich

#include <avr/io.h> // IO Funktionen aus der avr-controller Bibliothek importieren
#include <util/delay.h>

int main(void) {
  DDRB = DDRB | (1 << DDB5); 

  while(1) {
    PORTB = PORTB | (1 << PORTB5);
    _delay_ms(500);    
    PORTB = PORTB & ~(1 << PORTB5);
    _delay_ms(500);
  }
}
