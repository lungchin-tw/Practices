# This make file is a test rule file
# Version 0.2 2009/06/11
LIBS = -lm
OBJS = main.o haha.o sin_value.o cos_value.o
main: ${OBJS}
	gcc -o main ${OBJS} ${LIBS}
clean:
	rm -f main ${OBJS}
install:
	cp -a main /usr/local/bin
uninstall:
	rm -f /usr/local/bin/main
