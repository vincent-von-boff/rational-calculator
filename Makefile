CC = gcc
INCLUDE_DIR = ./include/
CFLAGS = -g -Wall -Werror -I$(INCLUDE_DIR) 

# Math
MATH_FOLDER = ./math/
MATH_OBJ = decimal_integer.o
MATH_FILES =  decimal_integer.c
RAW_MATH_OBJ =  decimal_integer

OBJECTS = #utils.o 
FILES = #utils.c 
RAW_OBJECTS = #utils

# Main
MAIN_FILE = main.c
MAIN_OBJ = main.o
BUILD_FOLDER =  ./build/
FINAL_BIN = main.bin

# Tests
TEST_INCLUDE_DIR = ./tests/include/
TEST_FOLDER = ./tests/
TEST_BUILD_FOLDER = ./build/tests/
TEST_FILES = decimal_integer_test.c
TEST_OBJECTS = decimal_integer_test.o
RAW_TEST_OBJECTS = decimal_integer_test
MAIN_TEST_FILE = test_main.c
MAIN_TEST_OBJ = test_main.o
TEST_BIN = test.bin

all: $(FINAL_BIN)

run: $(FINAL_BIN)
	echo "\n\n"; $(BUILD_FOLDER)$^

build-test: $(TEST_BIN)
	
run-test: $(TEST_BIN)
	echo "\n";$(TEST_BUILD_FOLDER)$^;

$(FINAL_BIN): $(OBJECTS) $(MAIN_OBJ) $(MATH_OBJ)
	$(CC) -g $(BUILD_FOLDER)$(MAIN_OBJ) $(foreach X, $(MATH_OBJ), $(BUILD_FOLDER)$(X)) $(foreach X, $(OBJECTS), $(BUILD_FOLDER)$(X)) -o $(BUILD_FOLDER)$@

$(TEST_BIN): $(OBJECTS) $(MAIN_TEST_OBJ) $(TEST_OBJECTS) $(MATH_OBJ)
	$(CC) -g  $(TEST_BUILD_FOLDER)$(MAIN_TEST_OBJ) $(foreach X, $(MATH_OBJ), $(BUILD_FOLDER)$(X)) $(foreach X, $(TEST_OBJECTS), $(TEST_BUILD_FOLDER)$(X)) $(foreach X, $(OBJECTS), $(BUILD_FOLDER)$(X)) -o $(TEST_BUILD_FOLDER)$@

$(MAIN_OBJ): 
	$(CC) $(CFLAGS) -c $(MAIN_FILE) -o $(BUILD_FOLDER)$@
	
$(MAIN_TEST_OBJ):
	$(CC) $(CFLAGS) -c $(TEST_FOLDER)$(MAIN_TEST_FILE) -o $(TEST_BUILD_FOLDER)$@

$(TEST_OBJECTS):
	mkdir -p $(TEST_BUILD_FOLDER)
	$(foreach X, $(RAW_TEST_OBJECTS), $(CC) $(CFLAGS) -c $(TEST_FOLDER)$(X).c -o $(TEST_BUILD_FOLDER)$(X).o; )

$(OBJECTS): 
	mkdir -p $(TEST_BUILD_FOLDER)
	$(foreach X, $(RAW_OBJECTS), $(CC) $(CFLAGS) -c $(X).c -o $(BUILD_FOLDER)$(X).o; )

$(MATH_OBJ): 
	mkdir -p $(TEST_BUILD_FOLDER)
	$(foreach X, $(RAW_MATH_OBJ), $(CC) $(CFLAGS) -c $(MATH_FOLDER)$(X).c -o $(BUILD_FOLDER)$(X).o; )

clean:
	#rm -rf $(FINAL_BIN) *.o
	rm -rf $(BUILD_FOLDER)
