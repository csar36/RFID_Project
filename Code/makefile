CC=g++
FLAGS=-Wall -Wextra -Wno-unused -std=c++11 -pedantic
OBJS=spi.o gpio.o timer.o MFRC522.o
OUT=rfid

$(OUT): $(OBJS) main.cpp
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp %.h
	$(CC) $(FLAGS) -c $<  -o $@

clean:
	rm -f $(OUT)
	rm -f *.o

.PHONY: clean