CC=gcc
CFLAGS=-Wall -O1 -std=c99

poet: poet.c
	$(CC) -no-pie -fno-stack-protector -D_FORTIFY_SOURCE=0 -o poet poet.c $(CFLAGS)
	cp poet distrib/poet
