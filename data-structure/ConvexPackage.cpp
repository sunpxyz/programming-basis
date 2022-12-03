// Chapter 04. Divide Conquer
// ConvexPackage.cpp
// 2017.11.18

/*
#include <iostream>
#include <vector>
#include <algorithm>


bool Compare(int a, int b) {
	return a < b;
}

void OneDimensionClosetPair(std::vector<int> &vint, double &length);


int main() {
	std::vector<int> vint;
	
	for (int i = 0; i < 10; ++i) {
		int tmp = rand() % 100;
		std::cout << tmp << " - ";
		vint.push_back(tmp);
	}
	std::sort(vint.begin(), vint.end(), Compare);

	std::cout << std::endl;
	for (auto ex : vint) {
		std::cout << ex << " - ";
	}

	double result = 0;
	OneDimensionClosetPair(vint, result);

	std::cout << "The closet distance of list is: " << result << std::endl;

	return 0;
}


void OneDimensionClosetPair(std::vector<int> &vint, double &length) {
	int midd = vint.size() / 2;
	if (midd < 2) {
		length = -1;
		return;
	}

	std::vector<int> vint1(vint.begin(),vint.begin() + midd),
					 vint2(vint.begin() + midd, vint.end());

	double length1 = 0, length2 = 0;
	OneDimensionClosetPair(vint1, length1);
	OneDimensionClosetPair(vint2, length2);

	double tmp = std::min(length1, length2);
	length = std::min(tmp, double(vint[midd] - vint[midd - 1]));

}
*/