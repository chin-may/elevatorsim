# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: main

main: main.o scheduler.o queue.o elevator.o floor.o Person.o elevator_state.o\
	enter_event.o line_event.o new_entry_event.o alight_event.o move_event.o
	g++ $(LDFLAGS) $^ -o $@

alight_event.o: alight_event.cpp alight_event.h event.h elevator_state.h
	g++ -c $(CFLAGS) $< -o $@

new_entry_event.o: new_entry_event.cpp new_entry_event.h consts.h event.h elevator_state.h
	g++ -c $(CFLAGS) $< -o $@

move_event.o: move_event.cpp move_event.h consts.h enter_event.h alight_event.h elevator_state.h
	g++ -c $(CFLAGS) $< -o $@

line_event.o: line_event.cpp line_event.h event.h consts.h elevator_state.h
	g++ -c $(CFLAGS) $< -o $@

enter_event.o: enter_event.cpp enter_event.h event.h consts.h Person.h elevator_state.h
	g++ -c $(CFLAGS) $< -o $@

elevator_state.o: elevator_state.cpp floor.h elevator.h state.h consts.h elevator_state.h
	g++ -c $(CFLAGS) $< -o $@

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


