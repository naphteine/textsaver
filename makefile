all: textsaver.o
	cc textsaver.o -o textsaver -L/usr/X11R6/lib -lX11

textsaver.o: textsaver.c
	cc -c textsaver.c -o textsaver.o -I/usr/X11R6/include

clean:
	rm textsaver.o textsaver
