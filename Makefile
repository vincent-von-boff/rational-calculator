CC = gcc
INCLUDE_DIR = ./includes/
CFLAGS = -I $(INCLUDE_DIR) 

OBJECTS = main.o test.o utils.o decimal_integer.o
FILES = main.c test.c utils.c decimal_integer.c
BUILD_FOLDER =  build
FINAL_BIN = program

all: $(FINAL_BIN)

$(FINAL_BIN): $(OBJECTS)
	$(CC) $(foreach X, $^, $(BUILD_FOLDER)/$(X)) -o $(BUILD_FOLDER)/$@

%.o:%.c
	mkdir -p build
	$(CC) $(CFLAGS) -c -o $(BUILD_FOLDER)/$@ $^

clean:
	#rm -rf $(FINAL_BIN) *.o
	rm -rf $(BUILD_FOLDER)
