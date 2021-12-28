CC = gcc
CFLAGS = -I.

rule110make: rule110.c
	$(CC) -o rule110 rule110.c
