CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99
LDFLAGS=

all: encrypt decrypt

encrypt: encrypt.o aes.o
	$(CC) $(LDFLAGS) -o encrypt encrypt.o aes.o

decrypt: decrypt.o aes.o
	$(CC) $(LDFLAGS) -o decrypt decrypt.o aes.o

encrypt.o: encrypt.c aes.h
	$(CC) $(CFLAGS) -c encrypt.c

decrypt.o: decrypt.c aes.h
	$(CC) $(CFLAGS) -c decrypt.c

aes.o: aes.c aes.h
	$(CC) $(CFLAGS) -c aes.c

clean:
	rm -f encrypt decrypt *.o
