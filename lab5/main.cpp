#include <iostream>
#include <cassert>

#include "RingBuffer.h"

int main()
{
    RingBuffer<int> rbuf(10);
    RingBuffer<int> rbuf2 = rbuf;
    rbuf2.resize(200);
    RingBuffer<int> rbuf3(rbuf2);
    rbuf.push_back(4);
    rbuf.push_back(2);
    rbuf.push_back(3);
    assert(*(rbuf.end() - 2) == 2);
    return 0;
}

