CC = gcc
INCLUDE_DIR = ./includes/
CFLAGS = -I $(INCLUDE_DIR) 

OBJECTS = main.o test.o utils.o
FILES = main.c test.c utils.c
FINAL_BIN = program

all: $(FINAL_BIN)

$(FINAL_BIN): $(OBJECTS)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(FINAL_BIN) *.o
