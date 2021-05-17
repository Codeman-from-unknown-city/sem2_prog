#pragma once

template<class T>
class RingBuffer {
public:
    explicit RingBuffer(unsigned capacity);

	RingBuffer(const RingBuffer<T>& other);
	RingBuffer<T>& operator=(const RingBuffer<T>& other);

    ~RingBuffer();

    T operator[](unsigned index);

    void push_back(const T& elem);

    void push_front(const T& elem);

    T pop_back();

    T pop_front();

    void resize(unsigned new_capacity);

    class Iterator {
    public:
        Iterator(RingBuffer<T>* obj, int elem_ind);

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
		RingBuffer* obj;
		int elem_ind;
    };

    Iterator begin();

    Iterator end();

private:
    [[nodiscard]] bool need_shift() const;
    void change_index_val(int& ind, int num) const;

    T* buffer_;
    unsigned capacity_;
    int head_;
    int tail_;
};

template<class T>
bool operator==(const typename RingBuffer<T>::Iterator& i1,
                const typename RingBuffer<T>::Iterator& i2)
{
    return i1.elem_ind == i2.elem_ind;
}

template<class T>
bool operator!=(const typename RingBuffer<T>::Iterator& i1,
                const typename RingBuffer<T>::Iterator& i2)
{
    return !(i1 == i2);
}

#include "RingBuffer.hpp"