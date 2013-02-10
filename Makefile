# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: main

main: main.o queue.o Person.o floor.o elevator.o
	gcc $(LDFLAGS) $^ -o $@

main.o: main.c queue.h Person.h floor.h consts.h elevator.h
	gcc -c $(CFLAGS) $< -o $@

queue.o: queue.c queue.h Person.h
	gcc -c $(CFLAGS) $< -o $@

elevator.o: elevator.c elevator.h consts.h queue.h
	gcc -c $(CFLAGS) $< -o $@

floor.o: floor.c floor.h queue.h
	gcc -c $(CFLAGS) $< -o $@

Person.o: Person.c Person.h
	gcc -c $(CFLAGS) $< -o $@

.PHONY: clean lint

clean:
	rm -rf *.o
	rm -rf main

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;


