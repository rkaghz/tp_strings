/*
Expected output:
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
*/

#include <iostream>
#include "MyString.h"

int main() {
    // Testing default constructor
    MyString str1;
    std::cout << "Default constructor: \"" << str1.c_str() << "\" (size: " << str1.size() << ")" << std::endl;

    // Testing constructor from C-string
    MyString str2("Hello");
    std::cout << "Constructor from C-string: \"" << str2.c_str() << "\" (size: " << str2.size() << ")" << std::endl;

    // Testing copy constructor
    MyString str3(str2);
    std::cout << "Copy constructor: \"" << str3.c_str() << "\" (size: " << str3.size() << ")" << std::endl;

    // Testing operator=
    str1 = "World";
    std::cout << "Assignment from C-string: \"" << str1.c_str() << "\" (size: " << str1.size() << ")" << std::endl;

    str1 = str3;
    std::cout << "Assignment from MyString: \"" << str1.c_str() << "\" (size: " << str1.size() << ")" << std::endl;

    str1 = 'A';
    std::cout << "Assignment from char: \"" << str1.c_str() << "\" (size: " << str1.size() << ")" << std::endl;

    // Testing concatenation
    MyString str4 = str2 + " World";
    std::cout << "Concatenation with C-string: \"" << str4.c_str() << "\" (size: " << str4.size() << ")" << std::endl;

    MyString str5 = str4 + '!';
    std::cout << "Concatenation with char: \"" << str5.c_str() << "\" (size: " << str5.size() << ")" << std::endl;

    MyString str6 = str2 + str1;
    std::cout << "Concatenation with MyString: \"" << str6.c_str() << "\" (size: " << str6.size() << ")" << std::endl;

    // Testing clear
    str1.clear();
    std::cout << "After clear: \"" << str1.c_str() << "\" (size: " << str1.size() << ")" << std::endl;

    // Testing empty
    std::cout << "Is empty: " << (str1.empty() ? "true" : "false") << std::endl;

    // Testing resize
    str2.resize(10, '*');
    std::cout << "After resize to 10 with '*': \"" << str2.c_str() << "\" (size: " << str2.size() << ")" << std::endl;

    str2.resize(3);
    std::cout << "After resize to 3: \"" << str2.c_str() << "\" (size: " << str2.size() << ")" << std::endl;

    str2.resize(0);
    std::cout << "After resize to 0: \"" << str2.c_str() << "\" (size: " << str2.size() << ")" << std::endl;

    // Testing reserve
    str2.reserve(20);
    std::cout << "After reserve(20): capacity: " << str2.capacity() << ", size: " << str2.size() << std::endl;

    // Testing capacity
    std::cout << "Capacity: " << str2.capacity() << std::endl;

    // Testing max_size
    std::cout << "Max size: " << str2.max_size() << std::endl;

    return 0;
}

