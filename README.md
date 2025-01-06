# README

## Members Team 9
- Student A: Alondra González
- Student B: Rocío Aguirre
- Student C: Leonardo Chiaravalloti

## MyString Project
This project implements a custom string class, `MyString`, to demonstrate C++ concepts. The class provides basic string functionalities similar to `std::string` without using standard library functions like `std::strcpy` or `std::strlen`.

### File Structure
- **MyString.h**: Header file containing the `MyString` class declaration.
- **CodeA.cpp**: Implementation of the default and copy constructor, `c_str`, `size`, `clear`, and some operators.
- **CodeB.cpp**: Implementation of the constructor from a C-string, some additional methods such as `length`, `max_size`, `resize` and further operators.
- **CodeC.cpp**: Implementation of the destructor, `capacity`, `empty`, `reserve` and remaining operators.
- **string_tests.cpp**: Test file to verify the functionality of the `MyString` class.

### Compilation Instructions

#### Prerequisites
- A C++11 compatible compiler (e.g., `g++`).
- All source files (`MyString.h`, `CodeA.cpp`, `CodeB.cpp`, `CodeC.cpp`, and `string_tests.cpp`) must be in the same directory.

#### Compilation Command
Open a terminal or command prompt, navigate to the directory containing the files, and run:

```bash
 g++ -std=c++11 -o MyStringTest string_tests.cpp CodeA.cpp CodeB.cpp CodeC.cpp
```

- `-std=c++11`: Specifies the use of the C++11 standard.
- `-o MyStringTest`: Creates an executable named `MyStringTest`.

#### Running the Program
After successful compilation, run the program:

- On Linux/Mac:
  ```bash
  ./MyStringTest
  ```
- On Windows:
  ```cmd
  MyStringTest.exe
  ```

### Expected Output
When running the program, you should see output similar to the following:

```
Default constructor: "" (size: 0)
Constructor from C-string: "Hello" (size: 5)
Copy constructor: "Hello" (size: 5)
Assignment from C-string: "World" (size: 5)
Assignment from MyString: "Hello" (size: 5)
Assignment from char: "A" (size: 1)
Concatenation with C-string: "Hello World" (size: 11)
Concatenation with char: "Hello World!" (size: 12)
Concatenation with MyString: "HelloA" (size: 6)
After clear: "" (size: 0)
Is empty: true
After resize to 10 with '*': "Hello*****" (size: 10)
After resize to 3: "Hel" (size: 3)
After resize to 0: "" (size: 0)
After reserve(20): capacity: 20, size: 0
Capacity: 20
Max size: 100
```