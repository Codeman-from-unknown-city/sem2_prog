#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

#include "algorithm.h"

template<class Result>
void test(Result right, Result my, int num) {
	if (right != my) {
		std::cerr << "Test " << num << " failed" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	std::cout << "Test " << num << " passed" << std::endl;
}

template<class T>
bool cmp(const T& first, const T& second) {
	return first == second;
}

bool is_even(int num) {
	return num % 2 == 0;
}

int main() {
	std::vector<int> nums = {2, 6, 4, 2, 3, 9};
	std::string str = "testset";

	test(galgs::all_of(nums.begin(), nums.end(), is_even), std::all_of(nums.begin(), nums.end(), is_even), 1);
	test(galgs::any_of(nums.begin(), nums.end(), is_even), std::any_of(nums.begin(), nums.end(), is_even), 2);
	test(galgs::none_of(nums.begin(), nums.end(), is_even), std::none_of(nums.begin(), nums.end(), is_even), 3);
	test(galgs::one_of(nums.begin(), nums.end(), is_even), false, 4);
	test(galgs::is_sorted(nums.begin(), nums.end(), cmp<int>), std::is_sorted(nums.begin(), nums.end(), cmp<int>), 5);
	test(galgs::is_partitioned(nums.begin(), nums.end(), is_even), std::is_partitioned(nums.begin(), nums.end(), is_even), 6);
	test(galgs::find_not(nums.begin(), nums.end(), 3), std::vector<int>::iterator(nums.begin()), 7);
	test(galgs::find_backward(nums.begin(), nums.end(), 3), std::vector<int>::iterator(nums.end() - 2), 8);
	test(galgs::is_palindrome(str.begin(), str.end(), cmp<char>), true, 9);

	std::cout << "All tests passed" << std::endl;
	return 0;
}
