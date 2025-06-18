#pragma once

template <typename T>
class MyVector {
private:
    T* data;
    int size_;
    int capacity;

    void copyFrom(const MyVector& other);
    void free();
    void resize();

public:
    MyVector();
    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& other);
    ~MyVector();

    void push_back(const T& element);
    void removeAt(int index);
    void clear();

    int size() const;
    bool empty() const;

    T& operator[](int index);
    const T& operator[](int index) const;
};
