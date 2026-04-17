// Ein einfaches Beispiel, welches die auf dem Board verbaute LED blinken lässt

#include <avr/io.h> // IO Funktionen aus der avr-controller Bibliothek importieren
#include <util/delay.h> // delay macro importieren

int main(void) {
  DDRB |= (1 << DDB5); // Eingebaute LED auf Output setzen

  while(1) {
    PORTB |= (1 << PORTB5); // Eingebaute LED high setzen
    _delay_ms(500); // Eine halbe Sekunde warten
    PORTB &= ~(1 << PORTB5); // Eingebaute LED low setzen
    _delay_ms(500); // Noch eine halbe Sekunde warten
  }
}
