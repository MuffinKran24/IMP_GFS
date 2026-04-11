// Ein einfaches Beispiel, welches die auf dem Board verbaute LED blinken lässt

#include <avr/io.h> // IO Funktionen aus der avr-controller Bibliothek importieren
#include <util/delay.h> // delay macro importieren

int main(void) {
  DDRB = DDRB | (1 << DDB5); // 

  while(1) {
    PORTB = PORTB | (1 << PORTB5);
    _delay_ms(1000); // Eine Sekunde warten
    PORTB = PORTB & ~(1 << PORTB5);
    _delay_ms(1000); // Noch eine Sekunde warten
  }
}
