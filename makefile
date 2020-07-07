CC=g++
PROGRAM=MyNASDaemon_RaspberryPi
#SRC=$(wildcard *.cpp)
CFLAGS=-Wall

$(PROGRAM).elf: $(PROGRAM).o
	$(CC) $(CFLAGS) -o $@ $(PROGRAM).o

$(PROGRAM)_debug.elf: $(PROGRAM).o
	$(CC) $(CFLAGS) -g -o $@ $(PROGRAM).o

clean:
	-rm -f *.o
	-rm -f *.elf