// Das Thermometer mit so wenigen Bibliotheken und so direkt wie möglich

/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void lcd_init(void) {
  
}

int main(void) {
  DDRB |= (1<<PB5);
  while(1) {
    PORTB |= (1<<PB5);
    _delay_ms(1000);
    PORTB &= ~(1<<PB5);
    _delay_ms(1000);
  }
}

/*
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h> // Für itoa

// LCD Definitionen
#define LCD_PORT_CONTROL PORTB
#define LCD_DDR_CONTROL  DDRB
#define RS_PIN           PB4
#define EN_PIN           PB3
#define LCD_PORT_DATA    PORTD
#define LCD_DDR_DATA     DDRD

// DHT11 Definition
#define DHT_PIN          PB0
#define DHT_DDR          DDRB
#define DHT_PIN_INPUT    PINB
#define DHT_PORT         PORTB

// --- LCD FUNKTIONEN ---
void lcd_strobe(void) {
    LCD_PORT_CONTROL |= (1<<EN_PIN);
    _delay_us(1);
    LCD_PORT_CONTROL &= ~(1<<EN_PIN);
    _delay_us(100);
}
void lcd_write_4bit(uint8_t val) {
    LCD_PORT_DATA &= ~((1<<PD2)|(1<<PD3)|(1<<PD4)|(1<<PD5));
    if(val & 0x08) LCD_PORT_DATA |= (1<<PD2);
    if(val & 0x04) LCD_PORT_DATA |= (1<<PD3);
    if(val & 0x02) LCD_PORT_DATA |= (1<<PD4);
    if(val & 0x01) LCD_PORT_DATA |= (1<<PD5);
    lcd_strobe();
}
void lcd_send(uint8_t data, uint8_t rs) {
    if(rs) LCD_PORT_CONTROL |= (1<<RS_PIN);
    else LCD_PORT_CONTROL &= ~(1<<RS_PIN);
    lcd_write_4bit(data >> 4);
    lcd_write_4bit(data & 0x0F);
    _delay_us(50);
}
void lcd_init(void) {
    LCD_DDR_CONTROL |= (1<<RS_PIN)|(1<<EN_PIN);
    LCD_DDR_DATA |= (1<<PD2)|(1<<PD3)|(1<<PD4)|(1<<PD5);
    _delay_ms(50);
    lcd_write_4bit(0x03);
    _delay_ms(5);
    lcd_write_4bit(0x03);
    _delay_us(150);
    lcd_write_4bit(0x03);
    lcd_write_4bit(0x02);
    lcd_send(0x28,0);
    lcd_send(0x0C,0);
    lcd_send(0x01,0);
    _delay_ms(2);
}
void lcd_print(char *s) {
    while(*s) lcd_send(*s++, 1);
}

// --- DHT11 LOGIK ---
uint8_t dht11_read(uint8_t *humidity, uint8_t *temperature) {
    uint8_t data[5] = {0,0,0,0,0};
    uint8_t i, j = 0;

    // 1. Start Signal
    DHT_DDR |= (1 << DHT_PIN);  // Output
    DHT_PORT &= ~(1 << DHT_PIN); // Low
    _delay_ms(18);
    DHT_PORT |= (1 << DHT_PIN);  // High
    _delay_us(30);
    DHT_DDR &= ~(1 << DHT_PIN); // Input

    // 2. Response abwarten
    _delay_us(40);
    if (!(DHT_PIN_INPUT & (1 << DHT_PIN))) {
        while (!(DHT_PIN_INPUT & (1 << DHT_PIN))); // Wait for high
        while (DHT_PIN_INPUT & (1 << DHT_PIN));    // Wait for low
        
        // 3. 40 Bits lesen
        for (i = 0; i < 40; i++) {
            while (!(DHT_PIN_INPUT & (1 << DHT_PIN))); // Bit startet
            _delay_us(30);
            if (DHT_PIN_INPUT & (1 << DHT_PIN)) 
                data[i/8] |= (1 << (7 - (i%8)));
            while (DHT_PIN_INPUT & (1 << DHT_PIN));    // Bit endet
        }
        
        // Checksumme prüfen
        if (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF)) {
            *humidity = data[0];
            *temperature = data[2];
            return 1; // Erfolg
        }
    }
    return 0; // Fehler
}

int main(void) {
    char buffer[5];
    uint8_t hum, temp;
    
    lcd_init();

    while (1) {
        if (dht11_read(&hum, &temp)) {
            lcd_send(0x80, 0); // Zeile 1
            lcd_print("Temp: ");
            itoa(temp, buffer, 10);
            lcd_print(buffer);
            lcd_print(" C  ");

            lcd_send(0xC0, 0); // Zeile 2
            lcd_print("Hum:  ");
            itoa(hum, buffer, 10);
            lcd_print(buffer);
            lcd_print(" %  ");
        } else {
            lcd_send(0x80, 0);
            lcd_print("Error reading ");
        }
        _delay_ms(2000); // DHT11 braucht Zeit zwischen Messungen
    }
}
*/
