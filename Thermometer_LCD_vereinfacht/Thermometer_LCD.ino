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

#include <LiquidCrystal.h> // LCD-Bibliothek für das LCD hinzufügen
#include <DHT.h> // DHT-Bibliothek für den Sensor hinzufügen

#define DHTPIN 8 // Rückgabe Pin des DHT definieren, in diesem Fall digital IO Pin 8
#define DHTTYPE DHT11 // DHT-Typ definieren, in diesem Fall ist es der DHT11

DHT dht(DHTPIN, DHTTYPE); // neues Objekt dht der Klasse DHT initialisieren
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600); // seriellen Monitor starten
  dht.begin(); // Temperatur- und Luftfeuchtigkeitsaufnahme starten
  delay(1000); // wartet 1000ms
  Serial.println("DHT11 gestartet");
  
  lcd.begin(16, 2); // startet das LCD
}

void loop() {
  float temperature = dht.readTemperature(); // speichert die Temperatur in einer Variable "temperature"
  float humidity = dht.readHumidity(); // speichert die Luftfeuchtigkeit in einer Variable "humidity"


  if (isnan(temperature) || isnan(humidity)) { // Überprüfen ob der ausgegebene Wert eine Zahl ist
    Serial.println("Fehler beim Auslesen");
    delay(2000);
    return;
  }

  // Ausgeben der Werte im seriellen Monitor
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print(humidity);
  Serial.println(" %");

  Serial.println("----------");

  delay(2000);

  lcd.setCursor(0, 0); // der Cursor wird auf den ersten Platz in der ersten Zeile gesetzt
  lcd.print(temperature); // das LCD zeigt die Temperatur in der ersten Zeile an
  lcd.print(" C");

  lcd.setCursor(0, 1); // der Cursor wird auf den ersten Platz in der zweiten Zeile gesetzt
  lcd.print(humidity); // das LCD zeigt die Luftfeuchtigkeit in der zweiten Zeile an
  lcd.print(" %");
}
