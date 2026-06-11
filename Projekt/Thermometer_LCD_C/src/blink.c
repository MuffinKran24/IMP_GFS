// ein einfaches Beispiel, welches die auf dem Board verbaute LED blinken lässt

#include <avr/io.h> // IO Funktionen aus der avr-controller Bibliothek importieren
#include <util/delay.h> // delay macro importieren

int main(void) {
  DDRB |= (1 << DDB5); // eingebaute LED auf Output setzen

  while(1) {
    PORTB |= (1 << PORTB5); // eingebaute LED high setzen
    _delay_ms(500); // eine halbe Sekunde warten
    PORTB &= ~(1 << PORTB5); // eingebaute LED low setzen
    _delay_ms(500); // noch eine halbe Sekunde warten
  }
}
