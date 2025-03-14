CC = gcc
INCLUDE_DIR = ./includes/
CFLAGS = -I $(INCLUDE_DIR) 

OBJECTS = utils.o decimal_integer.o
FILES = utils.c decimal_integer.c
MAIN_FILE = main.c
MAIN_OBJ = main.o
BUILD_FOLDER =  build/
FINAL_BIN = program
TEST_FOLDER = build/tests/
TEST_FILE = tests/test.c
TEST_OBJ = test.o
TEST_BIN = test

all: $(FINAL_BIN)

run: $(FINAL_BIN)
	echo "\n\n"; ./$(BUILD_FOLDER)$^

build-test: $(TEST_BIN)
	
run-test: $(TEST_BIN)
	echo "\n\n"
	./$(TEST_FOLDER)$^

$(FINAL_BIN): $(OBJECTS) $(MAIN_OBJ)
	$(CC) $(foreach X, $^, $(BUILD_FOLDER)$(X)) -o $(BUILD_FOLDER)$@

$(TEST_BIN): $(OBJECTS) $(TEST_OBJ)
	$(CC) $(TEST_FOLDER)$(TEST_OBJ) $(foreach X, $(OBJECTS), $(BUILD_FOLDER)$(X)) -o $(TEST_FOLDER)$@

$(TEST_OBJ): $(TEST_FILE)
	$(CC) $(CFLAGS) -c -o $(TEST_FOLDER)$@ $^

%.o:%.c
	mkdir -p $(TEST_FOLDER)
	$(CC) $(CFLAGS) -c -o $(BUILD_FOLDER)$@ $^

clean:
	#rm -rf $(FINAL_BIN) *.o
	rm -rf $(BUILD_FOLDER)
