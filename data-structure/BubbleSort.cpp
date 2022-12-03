// Chapter 03. Brute Force
// BubbleSort.cpp
// 2017.09.30

/*
#include <iostream>
#include <algorithm>


template<typename T>
void BubbleSort(T t[], std::size_t n);


int main() {
	int test[] = { 1, 5, 7, 9, 2, 5, 3, 4, 8 };
	int len = sizeof(test) / sizeof(test[0]);

	std::cout << "before sorting:" << std::endl;
	for (int i = 0; i < len; ++i) {
		std::cout << test[i] << " ";
	}
	std::cout << std::endl;

	BubbleSort<int>(test, len);

	std::cout << "\nafter sorting:" << std::endl;
	for (int i = 0; i < len; ++i) {
		std::cout << test[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}


template<typename T>
void BubbleSort(T t[], std::size_t n) {
	for (std::size_t i = 0; i < n - 1; ++i) {
		for (std::size_t j = 0; j < n - 1 - i; ++j) {
			if (t[j] > t[j + 1]) {
				std::swap(t[j], t[j + 1]);
			}
		}
	}
}
*/
