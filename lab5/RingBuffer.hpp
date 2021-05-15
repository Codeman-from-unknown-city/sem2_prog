#include <cstring>
#include <cstdlib>

#define __INCREASE_RB_POINTER(ptr, capacity) ptr = (ptr + 1) % capacity

#define __DECREASE_RB_POINTER(ptr, capacity) \
    ptr = (ptr == 0 ? capacity_ : ptr) - 1

template<class T>
RingBuffer<T>::RingBuffer(size_t capacity)
        : capacity_(capacity)
          , buffer_(new T[capacity])
          , head_(0)
          , tail_(0)
{
}

template<class T>
RingBuffer<T>::~RingBuffer()
{
    delete buffer_;
}

template<class T>
T RingBuffer<T>::operator[](size_t index)
{
    if (index >= capacity_)
        throw std::runtime_error("Buffer out of bounds");
    return buffer_[index];
}

template<class T>
void RingBuffer<T>::push_back(const T& elem)
{
    buffer_[tail_] = elem;
    __INCREASE_RB_POINTER(tail_, capacity_);
}

template<class T>
void RingBuffer<T>::push_front(const T& elem)
{
    __DECREASE_RB_POINTER(head_, capacity_);
    buffer_[head_] = elem;
}

template<class T>
T RingBuffer<T>::pop_back()
{
    __DECREASE_RB_POINTER(tail_, capacity_);
    return buffer_[tail_];
}

template<class T>
T RingBuffer<T>::pop_front()
{
    T* elem_ptr = buffer_ + head_;
    __INCREASE_RB_POINTER(head_, capacity_);
    return *elem_ptr;
}

template<class T>
void RingBuffer<T>::resize(size_t new_capacity)
{
    T* tmp = new T[new_capacity];
    memcpy(tmp, buffer_,
           sizeof(T) * (new_capacity < capacity_ ? new_capacity : capacity_));
    capacity_ = new_capacity;
    delete buffer_;
    buffer_ = tmp;
}

template<class T>
size_t RingBuffer<T>::capacity() const
{
    return capacity_;
}

template<class T>
bool RingBuffer<T>::full() const
{
    return tail_ == head_;
}

template<class T>
typename RingBuffer<T>::Iterator RingBuffer<T>::begin()
{
    return RingBuffer::Iterator(buffer_ + head_);
}

template<class T>
typename RingBuffer<T>::Iterator RingBuffer<T>::end()
{
    return RingBuffer::Iterator(buffer_ + tail_);
}

template<class T>
RingBuffer<T>::Iterator::Iterator(T* elem_ptr)
        : elem_ptr(elem_ptr)
{
}

template<class T>
typename RingBuffer<T>::Iterator& RingBuffer<T>::Iterator::operator++()
{
    elem_ptr++;
    return *this;
}

template<class T>
typename RingBuffer<T>::Iterator& RingBuffer<T>::Iterator::operator--()
{
    elem_ptr--;
    return *this;
}

template<class T>
typename RingBuffer<T>::Iterator RingBuffer<T>::Iterator::operator+(int num)
{
    return Iterator(elem_ptr + num);
}

template<class T>
typename RingBuffer<T>::Iterator RingBuffer<T>::Iterator::operator-(int num)
{
    return *this + -num;
}

template<class T>
T RingBuffer<T>::Iterator::operator*()
{
    return *elem_ptr;
}

template<class T>
RingBuffer<T>::Iterator::Iterator(const RingBuffer<T>::Iterator& other)
        : elem_ptr(other.elem_ptr)
{
}

template<class T>
typename RingBuffer<T>::Iterator&
RingBuffer<T>::Iterator::operator=(const RingBuffer<T>::Iterator& other)
{
    if (this != &other)
        elem_ptr = other.elem_ptr;
    return *this;
}
