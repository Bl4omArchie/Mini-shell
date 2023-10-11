SRC_C=shell.c StringVector.c
OBJ=${SRC_C:.c=.o}
CFLAGS= -g -std=c11 -Wall -Wextra -pedantic -D_XOPEN_SOURCE=700

all: myshell

myshell: $(OBJ) main.o
	gcc $(CFLAGS) $(OBJ) main.o -o myshell

%.o: %.c
	gcc -c $(CFLAGS) $<

clean:
	@rm -f $(OBJ) main.o myshell *~