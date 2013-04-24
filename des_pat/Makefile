# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: main

main: main.o scheduler.o queue.o elevator.o floor.o Person.o
	g++ $(LDFLAGS) $^ -o $@

main.o: main.cpp state.h elevator_state.h consts.h new_entry_event.h enter_event.h move_event.h scheduler.h line_event.h
	g++ -c $(CFLAGS) $< -o $@

scheduler.o: scheduler.cpp scheduler.h event.h state.h
	g++ -c $(CFLAGS) $< -o $@

queue.o: queue.cpp queue.h Person.h
	g++ -c $(CFLAGS) $< -o $@

elevator.o: elevator.cpp elevator.h consts.h queue.h Person.h
	g++ -c $(CFLAGS) $< -o $@

floor.o: floor.cpp floor.h queue.h Person.h
	g++ -c $(CFLAGS) $< -o $@

Person.o: Person.cpp Person.h
	g++ -c $(CFLAGS) $< -o $@

.PHONY: clean lint

clean:
	rm -rf *.o
	rm -rf main

lint:
	for f in *.cpp; do echo $$f; splint -standard $$f; done;


