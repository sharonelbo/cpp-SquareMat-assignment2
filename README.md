# System Programming 2, Exercise 2, SqareMat

## Email
`sharon4homework@gmail.com`

## Overview
This project implements a `SquareMat` class in C++ that represents a square matrix of real numbers. It demonstrates key object-oriented concepts and C++ features:

- Operator overloading
- Memory management (Rule of Three)
- Modular design with headers and source files
- Unit testing using `doctest`
- Manual memory handling without STL containers

## Project Structure
```
/SquareMatProject
├── include/
│   └── SquareMat.hpp       # Class definition
├── src/
│   └── SquareMat.cpp       # Implementation
├── tests/
│   └── test_SquareMat.cpp  # Unit tests
├── main.cpp                # Demo of all features
├── Makefile                # Build and run commands
├── README.md               # Project documentation
```

## Features Implemented
The `SquareMat` class supports:

- Addition, subtraction, unary minus
- Matrix multiplication and scalar multiplication (both sides)
- Division by scalar with error checking
- Element-wise multiplication and modulo
- Power (`^`) operator for matrix exponentiation
- Determinant computation via `!`
- Comparison operators (`==`, `!=`, `<`, `<=`, etc.)
- Increment/decrement (`++`, `--`) (pre/post)
- Transpose with `~`
- Compound assignment (`+=`, `-=`, `*=`, `/=`, `%=`)
- Safe memory handling with Rule of Three

## Build & Run
### Compile and run main demo:
```
make main
./main
```

### Run unit tests:
```
make test
```

### if not already installed, install valgrind:
```
sudo apt update
sudo apt install valgrind
```

### Run memory check with Valgrind:
```
make valgrind
```

### Cleanup:
```
make clean
```

## Testing
- 12 test cases covering all operations
- Full coverage with `doctest`
- Memory safe — verified via Valgrind

## Notes
- No STL containers used (e.g., `vector`, `stack`) as per assignment rules
- All input validity checks raise appropriate exceptions
- Matrix indices are bounds-checked for safety

