#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString {
    private:
        char* _char_array_;                     // Pointer to dynamically allocated memory
        size_t _size;                           // Current size of the string
        size_t _capacity;                       // Current capacity of the allocated memory
        const static size_t _max_size = 100;    // Maximum size allowed

    public:
        MyString();                             // Default constructor
        MyString(const MyString& other);        // Copy constructor
        MyString(const char* cstr);             // Constructor from C-string
        ~MyString();                            // Destructor

        const char* c_str() const;                      // Returns a non-modifiable C-string
        size_t size() const;                            // Returns the number of characters
        size_t length() const;                          // Alias for size()
        size_t max_size() const;                        // Returns the maximum number of characters
        size_t capacity() const;                        // Returns the allocated storage capacity
        bool empty() const;                             // Checks whether the string is empty
        void clear();                                   // Clears the contents
        void resize(size_t new_size, char c = '\0');    // Changes the number of characters stored
        void reserve(size_t new_capacity);              // Reserves storage for at least new_capacity characters

        MyString& operator=(const char c);                  // Assigns a character
        MyString& operator=(const MyString& other);         // Assigns another MyString
        MyString& operator=(const char* cstr);              // Assigns a C-string
        MyString operator+(char c) const;                   // Concatenates with a character
        MyString operator+(const MyString& other) const;    // Concatenates two MyStrings
        MyString operator+(const char* cstr) const;         // Concatenates with a C-string
};

#endif
