template<class T>
RingBuffer<T>::RingBuffer(unsigned capacity)
    : capacity_(capacity)
    , buffer_(new T[capacity])
    , head_(0)
    , tail_(capacity > 1)
{}

template<class T>
RingBuffer<T>::~RingBuffer()
{
    delete buffer_;
}

template<class T>
RingBuffer<T>::RingBuffer(const RingBuffer<T>& other)
	: capacity_(other.capacity_)
	, head_(other.head_)
	, tail_(other.tail_)
{
	buffer_ = new T [capacity_];
	for (unsigned i = 0; i < capacity_; ++i)
	    buffer_[i] = other.buffer_[i];
}

template<class T>
RingBuffer<T>& RingBuffer<T>::operator=(const RingBuffer<T>& other)
{
	if (this != &other) {
		delete buffer_;
		capacity_ = other.capacity_; head_ = other.head_;
		tail_ = other.tail_;
		buffer_ = new T [capacity_];
        for (unsigned i = 0; i < capacity_; ++i)
            buffer_[i] = other.buffer_[i];
	}
	return *this;
}

template<class T>
bool RingBuffer<T>::need_shift() const
{
    return head_ == tail_ && capacity_ > 1;
}

template<class T>
void RingBuffer<T>::shift(int& ind, int num) const
{
    ind += num;
	ind %= capacity_;
    if (ind < 0)
        ind += capacity_;
}

template<class T>
T RingBuffer<T>::operator[](unsigned index)
{
    if (index >= capacity_)
        throw std::logic_error("Buffer out of bounds");
    return buffer_[index];
}

template<class T>
void RingBuffer<T>::push_back(const T& elem)
{
	if (need_shift())
        shift(head_, 1);
    buffer_[tail_] = elem;
    shift(tail_, 1);
}

template<class T>
void RingBuffer<T>::push_front(const T& elem)
{
	if (need_shift())
        shift(tail_, -1);
    shift(head_, -1);
    buffer_[head_] = elem;
}

template<class T>
T RingBuffer<T>::pop_back()
{
    if (need_shift())
        shift(head_, -1);
    shift(tail_, -1);
    return buffer_[tail_];
}

template<class T>
T RingBuffer<T>::pop_front()
{
    T* elem_ptr = buffer_ + head_;
    if (need_shift())
        shift(tail_, 1);
    shift(head_, 1);
    return *elem_ptr;
}

template<class T>
void RingBuffer<T>::resize(unsigned new_capacity)
{
    T* tmp = new T[new_capacity];
    for (unsigned i = 0; i < std::min(capacity_, new_capacity); ++i)
        tmp[i] = buffer_[i];
    capacity_ = new_capacity;
    delete buffer_;
    buffer_ = tmp;
}

template<class T>
typename RingBuffer<T>::Iterator RingBuffer<T>::begin()
{
    return RingBuffer<T>::Iterator(this, head_, false);
}

template<class T>
typename RingBuffer<T>::Iterator RingBuffer<T>::end()
{
    return RingBuffer<T>::Iterator(this, tail_, true);
}

template<class T>
RingBuffer<T>::Iterator::Iterator(RingBuffer<T>* obj, int elem_ind, bool is_end)
	: obj(obj)
	, elem_ind(elem_ind)
	, is_end(is_end)
{}

template<class T>
typename RingBuffer<T>::Iterator& RingBuffer<T>::Iterator::operator++()
{
	obj->shift(elem_ind, 1);
	cnt++;
    return *this;
}

template<class T>
typename RingBuffer<T>::Iterator& RingBuffer<T>::Iterator::operator--()
{
    obj->shift(elem_ind, -1);
	cnt--;
    return *this;
}

template<class T>
typename RingBuffer<T>::Iterator RingBuffer<T>::Iterator::operator+(int num)
{
    int new_iter_elem_ind = elem_ind;
    obj->shift(new_iter_elem_ind, num);
    return Iterator(obj, new_iter_elem_ind);
}

template<class T>
typename RingBuffer<T>::Iterator RingBuffer<T>::Iterator::operator-(int num)
{
    return *this + -num;
}

template<class T>
T RingBuffer<T>::Iterator::operator*()
{
    return (*obj)[elem_ind];
}

template<class T>
RingBuffer<T>::Iterator::Iterator(const RingBuffer<T>::Iterator& other)
	: obj(other.obj)
	, elem_ind(other.elem_ind)
	, cnt(other.cnt)
	, is_end(other.is_end)
{}

template<class T>
typename RingBuffer<T>::Iterator&
RingBuffer<T>::Iterator::operator=(const RingBuffer<T>::Iterator& other)
{
    if (this != &other) {
		obj = other.obj;
        elem_ind = other.elem_ind;
		cnt = other.cnt;
		is_end = other.is_end;
	}
    return *this;
}
