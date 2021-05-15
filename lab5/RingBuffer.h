#pragma once

#include <cstddef>

template<class T>
class RingBuffer {
public:
    explicit RingBuffer(size_t capacity);

    ~RingBuffer();

    T operator[](size_t index);

    void push_back(const T& elem);

    void push_front(const T& elem);

    T pop_back();

    T pop_front();

    void resize(size_t new_capacity);

    size_t capacity() const;

    bool full() const;

    class Iterator {
    public:
        explicit Iterator(T* elem_ptr);

        Iterator(const Iterator& other);

        Iterator& operator=(const Iterator& other);

        friend bool operator==(const RingBuffer<T>::Iterator& i1,
                               const RingBuffer<T>::Iterator& i2);

        Iterator& operator++();

        Iterator& operator--();

        Iterator operator+(int num);

        Iterator operator-(int num);

        T operator*();

    private:
        T* elem_ptr;
    };

    Iterator begin();

    Iterator end();

private:
    T* buffer_;
    size_t capacity_;
    size_t head_;
    size_t tail_;
};

template<class T>
bool operator==(const typename RingBuffer<T>::Iterator& i1,
                const typename RingBuffer<T>::Iterator& i2)
{
    return i1.elem_ptr == i2.elem_ptr;
}

template<class T>
bool operator!=(const typename RingBuffer<T>::Iterator& i1,
                const typename RingBuffer<T>::Iterator& i2)
{
    return !(i1 == i2);
}

#include "RingBuffer.hpp"