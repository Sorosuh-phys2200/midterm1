
CC = clang
CFLAGS = -Wall -O0 -g
LFLAGS = -O0 -g
LIBS = -lm

main1: main1.o pi_leibniz.o pi_bbp.o
	${CC} $(LFLAGS) -o main1 main1.o pi_leibniz.o pi_bbp.o

main1.o pi_leibniz.o pi_bbp.o: pi_funs.h

clean:
	rm -f *.o
	
veryclean: clean
	rm -f main1
