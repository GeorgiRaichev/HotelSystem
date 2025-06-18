#include "MyString.h"
#include <cstring>

void MyString::copyFrom(const MyString& other) {
    length = other.length;
    data = new char[length + 1];
    std::strcpy(data, other.data);
}

void MyString::free() {
    delete[] data;
}

MyString::MyString() {
    length = 0;
    data = new char[1];
    data[0] = '\0';
}

MyString::MyString(const char* str) {
    length = std::strlen(str);
    data = new char[length + 1];
    std::strcpy(data, str);
}

MyString::MyString(const MyString& other) {
    copyFrom(other);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

MyString::~MyString() {
    free();
}

int MyString::size() const {
    return length;
}

const char* MyString::c_str() const {
    return data;
}

char& MyString::operator[](int index) {
    return data[index];
}

const char& MyString::operator[](int index) const {
    return data[index];
}

bool MyString::operator==(const MyString& other) const {
    return std::strcmp(data, other.data) == 0;
}

bool MyString::operator<(const MyString& other) const {
    return std::strcmp(data, other.data) < 0;
}

