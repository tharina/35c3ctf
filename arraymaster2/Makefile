CC=gcc
CFLAGS=-Wall -O1

arraymaster2: arraymaster2.c
	$(CC) -Wl,-z,relro,-z,now -o arraymaster2 arraymaster2.c $(CFLAGS)
	cp arraymaster2 distrib/arraymaster2
