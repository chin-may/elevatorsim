# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: main

main: main.o scheduler.o elevator_state.o
	gcc $(LDFLAGS) $^ -o $@

main.o: main.cpp state.h elevator_state.h
	gcc -c $(CFLAGS) $< -o $@

scheduler.o: scheduler.cpp scheduler.h event.h state.h
	gcc -c $(CFLAGS) $< -o $@

elevator_state.o: elevator_state.cpp elevator_state.h state.h \
	floor.h elevator.h state.h consts.h
	gcc -c $(CFLAGS) $< -o $@

queue.o: queue.cpp queue.h Person.h
	gcc -c $(CFLAGS) $< -o $@

elevator.o: elevator.cpp elevator.h consts.h queue.h Person.h
	gcc -c $(CFLAGS) $< -o $@

floor.o: floor.cpp floor.h queue.h Person.h
	gcc -c $(CFLAGS) $< -o $@

Person.o: Person.cpp Person.h
	gcc -c $(CFLAGS) $< -o $@

.PHONY: clean lint

clean:
	rm -rf *.o
	rm -rf main

lint:
	for f in *.cpp; do echo $$f; splint -standard $$f; done;


