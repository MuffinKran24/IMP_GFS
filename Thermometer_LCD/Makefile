default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o main.o src/main.c
	avr-gcc -DF_CPU=16000000UL -mmcu=atmega328p -o main.bin main.o
	avr-objcopy -O ihex -R .eeprom main.bin main.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex
