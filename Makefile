CC = gcc
CFLAGS = -g -Wall -Wextra -std=c11
LDFLAGS = -lrt -lpthread
EXEC = pwcheck

all: $(EXEC)

$(EXEC): pwcheck.c
	$(CC) $(CFLAGS) pwcheck.c -o $(EXEC) $(LDFLAGS)

clean:
	rm -f $(EXEC) *.o

install:
	$(CC) $(CFLAGS) pwcheck.c -o $(EXEC) $(LDFLAGS)

.PHONY: all clean install
