TEST = test
TEST_BIN = test/bin/image_test
TEST_PICTURES = test/pics
TEST_SOURCE = src/image.cpp src/image_test.cpp
SOURCE = src/image.cpp src/imageops.cpp
BIN = $(SOURCE:.cpp=.o)
PICTURES = pics
EXECUTABLE = imageops
CC = g++
FLAGS = --std=c++11
WARNING = -w

# link files and send to bin
default: $(BIN)
	$(CC) $(SOURCE) -o bin/$(EXECUTABLE) $(FLAGS) $(WARNING)


.cpp.o:
	$(CC) -c $< -o bin/image.o $(FLAGS) $(WARNING)

# link all test files and send to test/bin
test: $(TEST_SOURCE)
	$(CC) $(TEST_SOURCE) -o $(TEST_BIN) $(FLAGS) $(WARNING)

# run imageops with no command line entries
run: default
	cd ./bin && ./$(EXECUTABLE) $(WARNING)

# run all tests
run_test: test
	cd ./test/bin && ./image_test

# remove all .o and .exe files
clean:
	rm -f bin/image.o bin/$(EXECUTABLE) $(TEST_BIN)
