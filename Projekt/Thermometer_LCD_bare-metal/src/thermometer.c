// Das Thermometer mit so wenigen Bibliotheken und so direkt wie möglich

#include <stdio.h>
#include <stdbool.h>
#include <avr/io.h> // IO Funktionen aus der avr-controller Bibliothek importieren
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {

DDRB |= (1<<PB5);
    
  while(1) {
    PORTB |= (1<<PB5);


  }
}
