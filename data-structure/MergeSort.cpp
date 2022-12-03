// Chapter 04. Divide Conquer
// MergeSort.cpp
// 2017.10.22

/*
#include <iostream>
#include <vector>
#include <algorithm>


void MergeSort(std::vector<int> &intv);
void Merge(const std::vector<int> &iva, const std::vector<int> &ivb, std::vector<int> &ivc);


int main() {
	std::vector<int> ivt = { 17, 55, 49, 67, 24, 33, 98, 102, 76 };
	std::cout << "before sorting..." << std::endl;
	for (std::size_t i = 0; i < ivt.size(); ++i) {
		std::cout << ivt[i] << " ";
	}

	MergeSort(ivt);

	std::cout << "\n\nafter sorting..." << std::endl;
	for (std::size_t i = 0; i < ivt.size(); ++i) {
		std::cout << ivt[i] << " ";
	}

	return 0;
}


void MergeSort(std::vector<int> &intv) {
	std::size_t left = intv.size() / 2;
	std::size_t right = intv.size() - left;

	std::vector<int> ivb(left), ivc(right);
	if (intv.size() > 1) {
		std::copy(intv.begin(), intv.begin() + left, ivb.begin());
		std::copy(intv.begin() + left, intv.end(), ivc.begin());

		MergeSort(ivb);
		MergeSort(ivc);
		Merge(ivb, ivc, intv);
	}
}


void Merge(const std::vector<int> &iva, const std::vector<int> &ivb, std::vector<int> &ivc) {
	std::size_t ia = 0, ib = 0;

	ivc.clear();
	while (ia < iva.size() && ib < ivb.size()) {
		if (iva[ia] <= ivb[ib]) {
			ivc.push_back(iva[ia]);
			ia++;
		} else {
			ivc.push_back(ivb[ib]);
			ib++;
		}
	}

	if (ia < iva.size()) {
		for (auto it = iva.begin() + ia; it != iva.end(); ++it) {
			ivc.push_back(*it);
		}
	} else {
		for (auto it = ivb.begin() + ib; it != ivb.end(); ++it) {
			ivc.push_back(*it);
		}
	}
}
*/
