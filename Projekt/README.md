# Ein einfaches Thermometer, das die Temperatur und Luftfeuchtigkeit auf einer Flüssigkristallanzeige anzeigt
## Bauteile:
- [Arduino UNO R3](https://www.conrad.de/de/p/arduino-a000066-board-uno-rev3-dil-core-atmega328-1275279.html)
- [LCD-1602A](https://www.amazon.de/AZDelivery-HD44780-Display-Zeichen-Arduino/dp/B08216WMDJ?tag=bingshoppin0b-21&linkCode=df0&hvadid=80127118566260&hvnetw=s&hvqmt=e&hvbmt=be&hvdev=c&hvlocint=undefined&hvlocphy=127417&hvtargid=pla-4583726587973319&th=1)
- [DHT11 Humidity & Temperature Sensor](https://www.conrad.de/de/p/joy-it-sen-ky015tf-temperatur-feuchtigkeitssensor-1-st-passend-fuer-entwicklungskits-arduino-1695379.html)
- [10K Potenziometer](https://www.conrad.de/de/p/piher-pt15nv02-103a2020-s-pt15nv02-103a2020-s-trimmer-linear-0-25-w-10-k-270-1-st-432024.html)

## Abhängigkeiten:
- ### Arduino IDE
- DHT sensor library (DHT Bibliothek)
- LiquidCrystal library (LCD Bibliothek)

- ### bare metal
- libc (C Standardbibliothek)
- avrdude (Programm zum flashen des AVR-Chips auf dem Arduino)
- avr-gcc (C Compiler für den AVR-Chip)
- avr-libc (Standardbibliothek für den AVR-Chip)
- avr-binutils (Assembler für den AVR-Chip)
- make [(GNU/Linux exklusiv)](https://archlinux.org/download/)
