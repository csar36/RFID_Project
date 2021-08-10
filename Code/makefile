all: rfid

rfid: main.o MFRC522.o
	gcc main.o MFRC522.o -lwiringPi -o rfid

main.o: main.c
	gcc -c main.c 
	
MFRC522.o: MFRC522.c
	gcc -c MFRC522.c

clean:
	rm -f main
	rm -f main.o MFRC522.o

