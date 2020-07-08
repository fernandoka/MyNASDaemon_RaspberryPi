CC=g++
PROGRAM=MyNASDaemon_RaspberryPi
SDIR=src/
ODIR=obj/
#SRC=$(wildcard *.cpp)
CFLAGS=-Wall

$(PROGRAM).elf: make_main make_DaemonFileManager
	$(CC) $(CFLAGS) -o $@ *.o

make_main: 
	$(CC) $(CFLAGS) -c $(SDIR)main.cpp 

make_DaemonFileManager: 
	$(CC) $(CFLAGS) -c $(SDIR)DaemonFileManager.cpp

clean:
	-rm -f $(ODIR)*.o
	-rm -f *.elf