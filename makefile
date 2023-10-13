CC = gcc
SRC_DIR = src
INCLUDE_DIR = includes
CMD_DIR = cmd

CFLAGS = -I$(INCLUDE_DIR)

SOURCES = $(wildcard $(SRC_DIR)/*.c $(CMD_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.o=%.o)

EXECUTABLE = myshell
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) main.o
	$(CC) $(OBJECTS) main.o -o $(EXECUTABLE)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) *.o