all: rfid

rfid: main.o pispi.o
	gcc main.o pispi.o -lwiringPi -o rfid

main.o: main.c
	gcc -c main.c 
	
pispi.o: pispi.c
	gcc -c pispi.c	

