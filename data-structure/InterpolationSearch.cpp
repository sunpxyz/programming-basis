// Chapter 05. Reduce Conquer
// InterpolationSearch.cpp
// 2017.11.14

/*
#include <iostream>
#include <vector>
#include <algorithm>


int InterpolationSearch(int array[], int l, int r, int value);


int main() {
	int array[10] = {1, 12, 25, 36, 45, 57, 63, 78, 84, 99};

	int val = rand() % 100;
	std::cout << "The value you wanna search:\n\t"
		<< val << std::endl;
	std::cout << "Searching result:\n\t"
		<< InterpolationSearch(array, 0, 9, val) << std::endl;
	
	return 0;
}


int InterpolationSearch(int arr[], int l, int r, int val) {
	if (l > r) {
		return -1;
	} else if (l == r) {
		if (arr[l] == val) {
			return l;
		} else {
			return -1;
		}
	} else {
		int x = l + ((val - arr[l]) * (r - l)) / (arr[r] - arr[l]);
		//std::cout << __FILE__ << ": " << __LINE__ << ": " << x << std::endl;
		if (val < arr[x]) {
			InterpolationSearch(arr, l, x - 1, val);
		} else if (val > arr[x]) {
			InterpolationSearch(arr, x + 1, r, val);
		} else {
			return x;
		}
	}
}
*/
