namespace galgs {
template<class InputIterator, class UnaryPredicate>
bool all_of(InputIterator first, InputIterator last, UnaryPredicate upred) {
	while (first != last) {
		if (!upred(*first))
			return false;
		++first;
	}
	return true;
}

template<class InputIterator, class UnaryPredicate>
bool any_of(InputIterator first, InputIterator last, UnaryPredicate upred) {
	while (first != last) {
		if (upred(*first))
			return true;
		++first;
	}
	return false;
}

template<class InputIterator, class UnaryPredicate>
bool none_of(InputIterator first, InputIterator last, UnaryPredicate upred) {
	while (first != last) {
		if (upred(*first))
			return false;
		++first;
	}
	return true;
}

template<class InputIterator, class UnaryPredicate>
bool one_of(InputIterator first, InputIterator last, UnaryPredicate upred) {
	bool one_found = false;
	while (first != last) {
		if (upred(*first)) {
			if (one_found) 
				return false;
			one_found = true;	
		}
		++first;
	}
	return one_found;
}

template<class InputIterator, class BinaryPredicate>
bool is_sorted(InputIterator first, InputIterator last, BinaryPredicate bpred) {
	while (first != last - 1) 
		if (!bpred(*first, *++first))
				return false;
	return true;
}

template<class InputIterator, class UnaryPredicate>
bool is_partitioned(InputIterator first, InputIterator last, UnaryPredicate upred) {
    for ( ; first != last; ++first)
        if (!upred(*first))
            break;
    for ( ; first != last; ++first)
        if (upred(*first))
            return false;
    return true;
}

template<class InputIterator, class Elem>
InputIterator find_not(InputIterator first, InputIterator last, Elem elem) {
	while (first != last) {
		if (*first != elem) 
			return first;
		++first;
	}
	return last;
}

template<class InputIterator, class Elem>
InputIterator find_backward(InputIterator first, InputIterator last, Elem elem) {
	InputIterator not_found(last);
	--last;
	while (first - 1 != last) {
		if (*last == elem) 
			return last;
		--last;
	}
	return not_found;
}

template<class InputIterator, class BinaryPredicate>
bool is_palindrome(InputIterator first, InputIterator last, BinaryPredicate bpred) {
	last--;
	while (first != last) {
		if (!bpred(*first, *last))
			return false;
		first++;
		last--;
	}
	return true;
}
};
