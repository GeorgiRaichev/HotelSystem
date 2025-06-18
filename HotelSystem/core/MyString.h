#pragma once

class MyString {
private:
    char* data;
    int length;

    void copyFrom(const MyString& other);
    void free();

public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    ~MyString();

    int size() const;
    const char* c_str() const;
    char& operator[](int index);
    const char& operator[](int index) const;

    bool operator==(const MyString& other) const;
    bool operator<(const MyString& other) const;
};
