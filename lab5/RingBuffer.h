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

	bool full() const;

    class Iterator {
    public:
        Iterator(RingBuffer* obj, int elem_ind);

        Iterator(const Iterator& other);

        Iterator& operator=(const Iterator& other);

        friend bool operator==(const RingBuffer::Iterator& i1,
                               const RingBuffer::Iterator& i2);

        Iterator& operator++();

        Iterator& operator--();

        Iterator operator+(int num);

        Iterator operator-(int num);

        T operator*();

    private:
		RingBuffer* obj;
		int elem_ind;
		bool is_end;
    };

    Iterator begin();

    Iterator end();

private:
    bool need_shift() const;
    void shift(int& ind, int num) const;
	void increase_size_and_check_for_fullness();

    T* buffer_;
    unsigned capacity_;
	unsigned size_;
    int head_;
    int tail_;
};

template<class T>
bool operator==(typename RingBuffer<T>::Iterator& i1,
                typename RingBuffer<T>::Iterator& i2)
{
	return i2.is_end ? i1.is_end : i1.elem_ind == i2.elem_ind;
}

template<class T>
bool operator!=(typename RingBuffer<T>::Iterator& i1,
                typename RingBuffer<T>::Iterator& i2)
{
    return !(i1 == i2);
}

#include "RingBuffer.hpp"
