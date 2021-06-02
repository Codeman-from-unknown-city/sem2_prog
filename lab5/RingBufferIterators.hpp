/*
 *
 *
 * ITERATOR
 *
 *
 */

template<class T, class Alloc>
RingBuffer<T, Alloc>::Iterator::Iterator(RingBuffer* obj, int elem_ind, bool is_end)
        : obj_ptr(obj)
          , elem_ind(elem_ind)
          , is_end(is_end)
{}

template<class T, class Alloc>
typename RingBuffer<T, Alloc>::Iterator& RingBuffer<T, Alloc>::Iterator::operator++()
{
    obj_ptr->shift(elem_ind, 1);
    is_end = obj_ptr->full() && elem_ind == obj_ptr->head_;
    return *this;
}

template<class T, class Alloc>
typename RingBuffer<T, Alloc>::Iterator& RingBuffer<T, Alloc>::Iterator::operator--()
{
    obj_ptr->shift(elem_ind, -1);
    return *this;
}

template<class T, class Alloc>
typename RingBuffer<T, Alloc>::Iterator RingBuffer<T, Alloc>::Iterator::operator+(int num)
{
    int new_iter_elem_ind = elem_ind;
    obj_ptr->shift(new_iter_elem_ind, num);
    // "(num || is_end)" to avoid + 0 influence
    bool is_new_iter_point_to_end = obj_ptr->full() && elem_ind == obj_ptr->head_ && (num || is_end);
    return Iterator(obj_ptr, new_iter_elem_ind, is_new_iter_point_to_end);
}

template<class T, class Alloc>
typename RingBuffer<T, Alloc>::Iterator RingBuffer<T, Alloc>::Iterator::operator-(int num)
{
    return *this + -num;
}

template<class T, class Alloc>
int RingBuffer<T, Alloc>::Iterator::operator-(const RingBuffer::Iterator& other)
{
    return elem_ind - other.elem_ind;
}

template<class T, class Alloc>
int RingBuffer<T, Alloc>::ConstIterator::operator-(const RingBuffer::ConstIterator& other)
{
    return elem_ind - other.elem_ind;
}

template<class T, class Alloc>
T& RingBuffer<T, Alloc>::Iterator::operator*()
{
    return obj_ptr->buffer_[elem_ind];
}

template<class T, class Alloc>
RingBuffer<T, Alloc>::Iterator::Iterator(const RingBuffer<T, Alloc>::Iterator& other)
        : obj_ptr(other.obj_ptr)
          , elem_ind(other.elem_ind)
          , is_end(other.is_end)
{
}

template<class T, class Alloc>
typename RingBuffer<T, Alloc>::Iterator&
RingBuffer<T, Alloc>::Iterator::operator=(const RingBuffer<T, Alloc>::Iterator& other)
{
    if (this != &other) {
        obj_ptr = other.obj_ptr;
        elem_ind = other.elem_ind;
        is_end = other.is_end;
    }
    return *this;
}

template<class T1, class Alloc1>
bool operator==(const typename RingBuffer<T1, Alloc1>::Iterator& i1,
                const typename RingBuffer<T1, Alloc1>::Iterator& i2)
{
    return i2.is_end ? i1.is_end : i1.elem_ind == i2.elem_ind;
}

template<class T1, class Alloc1>
bool operator!=(typename RingBuffer<T1, Alloc1>::Iterator& i1,
                typename RingBuffer<T1, Alloc1>::Iterator& i2)
{
    return !(i1 == i2);
}

/*
 *
 *
 * CONST ITERATOR
 *
 *
 */

template<class T, class Alloc>
RingBuffer<T, Alloc>::ConstIterator::ConstIterator(const RingBuffer* obj, int elem_ind, bool is_end)
        : obj_ptr(obj)
          , elem_ind(elem_ind)
          , is_end(is_end)
{}

template<class T, class Alloc>
typename RingBuffer<T, Alloc>::ConstIterator& RingBuffer<T, Alloc>::ConstIterator::operator++()
{
    obj_ptr->shift(elem_ind, 1);
    is_end = obj_ptr->full() && elem_ind == obj_ptr->head_;
    return *this;
}

template<class T, class Alloc>
typename RingBuffer<T, Alloc>::ConstIterator& RingBuffer<T, Alloc>::ConstIterator::operator--()
{
    obj_ptr->shift(elem_ind, -1);
    return *this;
}

template<class T, class Alloc>
typename RingBuffer<T, Alloc>::ConstIterator RingBuffer<T, Alloc>::ConstIterator::operator+(int num)
{
    int new_iter_elem_ind = elem_ind;
    obj_ptr->shift(new_iter_elem_ind, num);
    // "(num || is_end)" to avoid + 0 influence
    bool is_new_iter_point_to_end = obj_ptr->full() && elem_ind == obj_ptr->head_ && (num || is_end);
    return ConstIterator(obj_ptr, new_iter_elem_ind, is_new_iter_point_to_end);
}

template<class T, class Alloc>
typename RingBuffer<T, Alloc>::ConstIterator RingBuffer<T, Alloc>::ConstIterator::operator-(int num)
{
    return *this + -num;
}

template<class T, class Alloc>
T RingBuffer<T, Alloc>::ConstIterator::operator*()
{
    return obj_ptr->buffer_[elem_ind];
}

template<class T, class Alloc>
RingBuffer<T, Alloc>::ConstIterator::ConstIterator(const RingBuffer<T, Alloc>::ConstIterator& other)
        : obj_ptr(other.obj_ptr)
          , elem_ind(other.elem_ind)
          , is_end(other.is_end)
{
}

template<class T, class Alloc>
typename RingBuffer<T, Alloc>::ConstIterator&
RingBuffer<T, Alloc>::ConstIterator::operator=(const RingBuffer<T, Alloc>::ConstIterator& other)
{
    if (this != &other) {
        obj_ptr = other.obj_ptr;
        elem_ind = other.elem_ind;
        is_end = other.is_end;
    }
    return *this;
}

template<class T1, class Alloc1>
bool operator==(const typename RingBuffer<T1, Alloc1>::ConstIterator& i1,
                const typename RingBuffer<T1, Alloc1>::ConstIterator& i2)
{
    return i2.is_end ? i1.is_end : i1.elem_ind == i2.elem_ind;
}

template<class T1, class Alloc1>
bool operator!=(typename RingBuffer<T1, Alloc1>::ConstIterator& i1,
                typename RingBuffer<T1, Alloc1>::ConstIterator& i2)
{
    return !(i1 == i2);
}

/*
 *
 *
 * GENERAL THINGS
 *
 *
 */

template<class T1, class Alloc1>
bool operator==(const typename RingBuffer<T1, Alloc1>::Iterator& i1,
                const typename RingBuffer<T1, Alloc1>::ConstIterator& i2)
{
    return i2.is_end ? i1.is_end : i1.elem_ind == i2.elem_ind;
}

template<class T1, class Alloc1>
bool operator!=(typename RingBuffer<T1, Alloc1>::ConstIterator& i1,
                typename RingBuffer<T1, Alloc1>::Iterator& i2)
{
    return !(i1 == i2);
}
