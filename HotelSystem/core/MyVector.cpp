#include "MyVector.h"
#include <stdexcept>

template <typename T>
void MyVector<T>::copyFrom(const MyVector& other) {
    size_ = other.size_;
    capacity = other.capacity;
    data = new T[capacity];
    for (int i = 0; i < size_; ++i)
        data[i] = other.data[i];
}

template <typename T>
void MyVector<T>::free() {
    delete[] data;
}

template <typename T>
void MyVector<T>::resize() {
    capacity *= 2;
    T* newData = new T[capacity];
    for (int i = 0; i < size_; ++i)
        newData[i] = data[i];
    delete[] data;
    data = newData;
}

template <typename T>
MyVector<T>::MyVector() : data(nullptr), size_(0), capacity(8) {
    data = new T[capacity];
}

template <typename T>
MyVector<T>::MyVector(const MyVector& other) {
    copyFrom(other);
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
MyVector<T>::~MyVector() {
    free();
}

template <typename T>
void MyVector<T>::push_back(const T& element) {
    if (size_ >= capacity)
        resize();
    data[size_++] = element;
}

template <typename T>
void MyVector<T>::removeAt(int index) {
    if (index < 0 || index >= size_)
        throw std::out_of_range("Invalid index");
    for (int i = index; i < size_ - 1; ++i)
        data[i] = data[i + 1];
    --size_;
}

template <typename T>
void MyVector<T>::clear() {
    size_ = 0;
}

template <typename T>
int MyVector<T>::size() const {
    return size_;
}

template <typename T>
bool MyVector<T>::empty() const {
    return size_ == 0;
}

template <typename T>
T& MyVector<T>::operator[](int index) {
    return data[index];
}

template <typename T>
const T& MyVector<T>::operator[](int index) const {
    return data[index];
}