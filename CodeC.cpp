/*
Student C:
    destructor
    capacity()
    empty()
    reserve(size_t)
    operator=(const char*)
    operator+(const string&, const string&)
*/

#include "MyString.h"

// Destructor
MyString::~MyString() {
    delete[] _char_array_;
}

// Returns the allocated storage capacity
size_t MyString::capacity() const {
    return _capacity;
}

// Checks whether the string is empty
bool MyString::empty() const {
    return _size == 0;
}

// Reserves storage for at least new_capacity characters
void MyString::reserve(size_t new_capacity) {
    if (new_capacity > _max_size) {
        throw std::overflow_error("New capacity exceeds maximum size");
    }
    if (new_capacity > _capacity) {
        char* new_array = new char[new_capacity];
        for (size_t i = 0; i < _size; ++i) {
            new_array[i] = _char_array_[i];
        }
        new_array[_size] = '\0';
        delete[] _char_array_;
        _char_array_ = new_array;
        _capacity = new_capacity;
    }
}

// Assigns a C-string
MyString& MyString::operator=(const char* cstr) {
    size_t cstr_length = 0;
    while (cstr[cstr_length] != '\0') {
        cstr_length++;
    }
    if (cstr_length > _max_size) {
        throw std::overflow_error("C-string exceeds maximum size");
    }
    resize(cstr_length);
    for (size_t i = 0; i < cstr_length; ++i) {
        _char_array_[i] = cstr[i];
    }
    return *this;
}

// Concatenates two MyStrings
MyString MyString::operator+(const MyString& other) const {
    size_t new_size = _size + other._size;
    if (new_size > _max_size) {
        throw std::overflow_error("Concatenated string exceeds maximum size");
    }
    MyString result;
    result.reserve(new_size);
    result._size = new_size;
    for (size_t i = 0; i < _size; ++i) {
        result._char_array_[i] = _char_array_[i];
    }
    for (size_t i = 0; i < other._size; ++i) {
        result._char_array_[_size + i] = other._char_array_[i];
    }
    result._char_array_[new_size] = '\0';
    return result;
}
