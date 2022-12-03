// Chapter 04. Divide Conquer
// BinarySearch.cpp
// 2017.10.22

/*
#include <iostream>
#include <vector>


int BinarySearch(const std::vector<int> &iv, const int x);


int main() {
	std::vector<int> ivt = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	std::cout << BinarySearch(ivt, 76) << std::endl;

	return 0;
}


int BinarySearch(const std::vector<int> &iv, const int x) {
	int l = 0, r = iv.size() - 1;
	
	while (l <= r) {
		int m = (l + r) / 2;
	
		if (x == iv[m]) {
			return m;
		} else if (x > iv[m]) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}

	return -1;
}
*/
