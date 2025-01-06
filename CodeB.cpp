/*
Student B:
    constructor from a c-string
    length()
    max_size()
    resize(size_t, char)
    operator=(const string&)
    operator+(const string&, char)
*/

#include "MyString.h"

// Constructor from C-string
MyString::MyString(const char* cstr) {
    _size = 0;
    while (cstr[_size] != '\0') {
        _size++;
    }
    if (_size > _max_size) {
        throw std::overflow_error("String exceeds maximum size");
    }
    _capacity = _size + 1; // Include space for null terminator
    _char_array_ = new char[_capacity];
    for (size_t i = 0; i < _size; ++i) {
        _char_array_[i] = cstr[i];
    }
    _char_array_[_size] = '\0';
}

// Alias for size()
size_t MyString::length() const {
    return _size;
}

// Returns the maximum number of characters
size_t MyString::max_size() const {
    return _max_size;
}

// Changes the number of characters stored
void MyString::resize(size_t new_size, char c) {
    if (new_size > _max_size) {
        throw std::overflow_error("New size exceeds maximum size");
    }
    if (new_size > _capacity) {
        reserve(new_size);
    }
    for (size_t i = _size; i < new_size; ++i) {
        _char_array_[i] = c;
    }
    _size = new_size;
    _char_array_[_size] = '\0';
}

// Assigns another MyString
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        reserve(other._capacity);
        _size = other._size;
        for (size_t i = 0; i < _size; ++i) {
            _char_array_[i] = other._char_array_[i];
        }
        _char_array_[_size] = '\0';
    }
    return *this;
}

// Concatenates with a character
MyString MyString::operator+(char c) const {
    if (_size + 1 > _max_size) {
        throw std::overflow_error("Concatenated string exceeds maximum size");
    }
    MyString result;
    result.reserve(_size + 1);
    result._size = _size + 1;
    for (size_t i = 0; i < _size; ++i) {
        result._char_array_[i] = _char_array_[i];
    }
    result._char_array_[_size] = c;
    result._char_array_[_size + 1] = '\0';
    return result;
}