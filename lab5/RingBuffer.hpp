#include <algorithm>

template<class T, class Alloc>
void RingBuffer<T, Alloc>::allocate_buf()
{
	buffer_ = alloc_.allocate(capacity_);
}

template<class T, class Alloc>
void RingBuffer<T, Alloc>::destruct_buf()
{
	for (unsigned i = 0; i < capacity_; i++)
		alloc_.destroy(buffer_ + i);
	alloc_.deallocate(buffer_, capacity_);
}

template<class T, class Alloc>
RingBuffer<T, Alloc>::RingBuffer(unsigned capacity, Alloc alloc)
        : capacity_(capacity)
		  , alloc_(alloc)
          , size_(0)
          , head_(0)
          , tail_(capacity > 1)
{
	allocate_buf();
}

template<class T, class Alloc>
RingBuffer<T, Alloc>::~RingBuffer()
{
	destruct_buf();
}

template<class T, class Alloc>
RingBuffer<T, Alloc>::RingBuffer(const RingBuffer<T, Alloc>& other)
        : capacity_(other.capacity_)
		  , alloc_(other.alloc_)
          , size_(other.size_)
          , head_(other.head_)
          , tail_(other.tail_)
{
	allocate_buf();
	std::copy(other.cbegin(), other.cend(), begin());
}

template<class T, class Alloc>
RingBuffer<T, Alloc>& RingBuffer<T, Alloc>::operator=(const RingBuffer<T, Alloc>& other)
{
    if (this != &other) {
		destruct_buf();
        capacity_ = other.capacity_;
        size_ = other.size_;
        head_ = other.head_;
        tail_ = other.tail_;
		allocate_buf();
        std::copy(other.begin(), other.end(), begin());
    }
    return *this;
}

template<class T, class Alloc>
bool RingBuffer<T, Alloc>::need_shift() const
{
    return head_ == tail_ && capacity_ > 1;
}

template<class T, class Alloc>
void RingBuffer<T, Alloc>::shift(int& ind, int num) const
{
    ind += num;
    ind %= capacity_;
    if (ind < 0)
        ind += capacity_;
}

template<class T, class Alloc>
void RingBuffer<T, Alloc>::increase_size_and_check_for_fullness()
{
    if (head_ == tail_)
        size_ = capacity_;
    else
        size_++;
}

template<class T, class Alloc>
T& RingBuffer<T, Alloc>::operator[](unsigned index)
{
    if (index >= capacity_)
        throw std::logic_error("Buffer out of bounds");
    return buffer_[index];
}

template<class T, class Alloc>
T RingBuffer<T, Alloc>::operator[](unsigned int index) const
{
    if (index >= capacity_)
        throw std::logic_error("Buffer out of bounds");
    return buffer_[index];
}

template<class T, class Alloc>
void RingBuffer<T, Alloc>::push_back(const T& elem)
{
    if (need_shift())
        shift(head_, 1);
    buffer_[tail_] = elem;
    shift(tail_, 1);
    increase_size_and_check_for_fullness();
}

template<class T, class Alloc>
void RingBuffer<T, Alloc>::push_front(const T& elem)
{
    if (need_shift())
        shift(tail_, -1);
    shift(head_, -1);
    buffer_[head_] = elem;
    increase_size_and_check_for_fullness();
}

template<class T, class Alloc>
T RingBuffer<T, Alloc>::pop_back()
{
    size_--;
    if (need_shift())
        shift(head_, -1);
    shift(tail_, -1);
    return buffer_[tail_];
}

template<class T, class Alloc>
T RingBuffer<T, Alloc>::pop_front()
{
    size_--;
    T* elem_ptr = buffer_ + head_;
    if (need_shift())
        shift(tail_, 1);
    shift(head_, 1);
    return *elem_ptr;
}

template<class T, class Alloc>
void RingBuffer<T, Alloc>::resize(unsigned new_capacity)
{
    T* tmp = alloc_.allocate(new_capacity);
    for (unsigned i = 0; i < std::min(capacity_, new_capacity); ++i)
        tmp[i] = buffer_[i];
    capacity_ = new_capacity;    
    if (size_ > capacity_)
        size_ = capacity_;
	destruct_buf();
    buffer_ = tmp;
}

template<class T, class Alloc>
bool RingBuffer<T, Alloc>::full() const
{
    return size_ == capacity_;
}

template<class T, class Alloc>
typename RingBuffer<T, Alloc>::Iterator RingBuffer<T, Alloc>::begin()
{
    return RingBuffer<T, Alloc>::Iterator(this, head_, size_ > 0);
}

template<class T, class Alloc>
typename RingBuffer<T, Alloc>::Iterator RingBuffer<T, Alloc>::end()
{
    return RingBuffer<T, Alloc>::Iterator(this, tail_, true);
}

template<class T, class Alloc>
typename RingBuffer<T, Alloc>::ConstIterator RingBuffer<T, Alloc>::cbegin() const
{
    return RingBuffer::ConstIterator(static_cast<const RingBuffer<T, Alloc>*>(this), 0, size_ > 0);
}

template<class T, class Alloc>
typename RingBuffer<T, Alloc>::ConstIterator RingBuffer<T, Alloc>::cend() const
{
    return RingBuffer<T, Alloc>::ConstIterator(static_cast<const RingBuffer<T, Alloc>*>(this), tail_, true);
}
