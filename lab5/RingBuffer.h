#pragma once

#include <memory>

template<class T, class Alloc = std::allocator<T>>
class RingBuffer {
public:
    explicit RingBuffer(unsigned capacity, Alloc alloc = Alloc());

    RingBuffer(const RingBuffer& other);

    RingBuffer& operator=(const RingBuffer& other);

    ~RingBuffer();

    T& operator[](unsigned index);
    T operator[](unsigned index) const;

    void push_back(const T& elem);

    void push_front(const T& elem);

    T pop_back();

    T pop_front();

    void resize(unsigned new_capacity);

    bool full() const;

    class Iterator {
    public:
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::random_access_iterator_tag;
        friend RingBuffer;

        Iterator(RingBuffer* obj, int elem_ind, bool is_end);

        Iterator(const Iterator& other);

        Iterator& operator=(const Iterator& other);

        template<class T1, class Alloc1>
        friend bool operator==(const typename RingBuffer<T1, Alloc1>::Iterator& i1,
                               const typename RingBuffer<T1, Alloc1>::Iterator& i2);

        Iterator& operator++();

        Iterator& operator--();

        Iterator operator+(int num);

        Iterator operator-(int num);

        int operator-(const Iterator& other);

        T& operator*();

    private:
        RingBuffer* obj_ptr;
        int elem_ind;
        bool is_end;
    };

    class ConstIterator {
    public:
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::random_access_iterator_tag;
        friend RingBuffer;

        ConstIterator(const RingBuffer* obj, int elem_ind, bool is_end);

        ConstIterator(const ConstIterator& other);

        ConstIterator& operator=(const ConstIterator& other);

        template<class T1, class Alloc1>
        friend bool operator==(const typename RingBuffer<T1, Alloc1>::ConstIterator& i1,
                               const typename RingBuffer<T1, Alloc1>::ConstIterator& i2);

        ConstIterator& operator++();

        ConstIterator& operator--();

        ConstIterator operator+(int num);

        ConstIterator operator-(int num);

        int operator-(const ConstIterator& other);

        T operator*();

    private:
        const RingBuffer* obj_ptr;
        int elem_ind;
        bool is_end;
    };

    Iterator begin();

    Iterator end();

    ConstIterator cbegin() const;

    ConstIterator cend() const;

private:
    void allocate_buf();

    void destruct_buf();

    void copy_buf(const RingBuffer& other);

    bool need_shift() const;

    void shift(int& ind, int num) const;

    void increase_size_and_check_for_fullness();

    Alloc alloc_;
    T* buffer_;
    unsigned capacity_;
    unsigned size_;
    int head_;
    int tail_;
};

#include "RingBuffer.hpp"
#include "RingBufferIterators.hpp"
