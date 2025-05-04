# Email: sharon4homework@gmail.com

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
INCLUDES = -Iinclude
SRC = src/SquareMat.cpp
MAIN = main.cpp
TEST = tests/test_SquareMat.cpp

# compile and run the main file
main: $(MAIN) $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o main $(MAIN) $(SRC)
	./main

# compile and run the test file
test: $(TEST) $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o test $(TEST) $(SRC)
	./test

# Run valgrind on the main file
valgrind: test
	valgrind --leak-check=full ./main

# Clean up generated files
clean:
	rm -f main test
