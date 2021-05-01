#pragma once 

namespace galgs {

template<class InputIterator, class UnaryPredicate>
bool all_of(InputIterator first, InputIterator last, UnaryPredicate upred);

template<class InputIterator, class UnaryPredicate>
bool any_of(InputIterator first, InputIterator last, UnaryPredicate upred);

template<class InputIterator, class UnaryPredicate>
bool none_of(InputIterator first, InputIterator last, UnaryPredicate upred);

template<class InputIterator, class UnaryPredicate>
bool one_of(InputIterator first, InputIterator last, UnaryPredicate upred);

template<class InputIterator, class BinaryPredicate>
bool is_sorted(InputIterator first, InputIterator last, BinaryPredicate bpred);

template<class InputIterator, class UnaryPredicate>
bool is_partitioned(InputIterator first, InputIterator last, UnaryPredicate upred);

template<class InputIterator, class Elem>
std::pair<bool, InputIterator> find_not(InputIterator first, InputIterator last, Elem elem);

template<class InputIterator, class Elem>
std::pair<bool, InputIterator> find_backward(InputIterator first, InputIterator last, Elem elem);

template<class InputIterator, class BinaryPredicate>
bool is_palindrome(InputIterator first, InputIterator last, BinaryPredicate bpred);

};

#include "algorithm.hpp"
