/* 
Student A:
	default constructor
    copy constructor
    c_str()
    size()
    clear()
    operator=(char)
    operator+(const string&, const char*)
*/

#include "MyString.h"

// Default constructor
MyString::MyString() {
    _size = 0;
    _capacity = 1; // Initial capacity for null terminator
    _char_array_ = new char[_capacity];
    _char_array_[0] = '\0';
}

// Copy constructor
MyString::MyString(const MyString& other) {
    _size = other._size;
    _capacity = other._capacity;
    _char_array_ = new char[_capacity];
    for (size_t i = 0; i < _size; ++i) {
        _char_array_[i] = other._char_array_[i];
    }
    _char_array_[_size] = '\0';
}

// Returns a non-modifiable C-string
const char* MyString::c_str() const {
    return _char_array_;
}

// Returns the number of characters
size_t MyString::size() const {
    return _size;
}

// Clears the contents
void MyString::clear() {
    _size = 0;
    _char_array_[0] = '\0';
}

// Assigns a character
MyString& MyString::operator=(const char c) {
    resize(1);
    _char_array_[0] = c;
    return *this;
}

// Concatenates with a C-string
MyString MyString::operator+(const char* cstr) const {
    size_t cstr_length = 0;
    while (cstr[cstr_length] != '\0') {
        cstr_length++;
    }
    size_t new_size = _size + cstr_length;
    if (new_size > _max_size) {
        throw std::overflow_error("Concatenated string exceeds maximum size");
    }
    MyString result;
    result.reserve(new_size);
    result._size = new_size;
    for (size_t i = 0; i < _size; ++i) {
        result._char_array_[i] = _char_array_[i];
    }
    for (size_t i = 0; i < cstr_length; ++i) {
        result._char_array_[_size + i] = cstr[i];
    }
    result._char_array_[new_size] = '\0';
    return result;
}