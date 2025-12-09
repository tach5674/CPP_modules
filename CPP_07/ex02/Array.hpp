#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
    T *arr;
    unsigned int len;

public:
    Array() : arr(NULL), len(0) {}

    Array(unsigned int n) : arr(new T[n]()), len(n) {}

    Array(const Array &other) : arr(new T[other.len]()), len(other.len)
    {
        for (unsigned int i = 0; i < len; i++)
            arr[i] = other.arr[i];
    }

    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] arr;
            len = other.len;
            arr = new T[len];
            for (unsigned int i = 0; i < len; i++)
                arr[i] = other.arr[i];
        }
        return *this;
    }

    ~Array() { delete[] arr; }

    unsigned int size() const { return len; }

    T &operator[](unsigned int index)
    {
        if (index >= len)
            throw std::exception();
        return arr[index];
    }
};
#endif