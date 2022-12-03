// Chapter 03. Brute Force
// BruteForceStringMatch.cpp
// 2017.10.08

/*
#include <iostream>
#include <string>

int BruteForceStringMatch(const std::string &tstr, const std::string &pstr);


int main() {
	std::string tstr = "i-love-muc-sei-cs";
	std::string pstr = "muc";

	int ret = BruteForceStringMatch(tstr, pstr);
	
	std::cout << ret << std::endl;
	if (ret != -1) {
		std::cout << tstr << std::endl;
		for (std::size_t i = 0; i < ret; ++i) {
			std::cout << " ";
		}
		std::cout << "^" << std::endl;
	}

	return 0;
}


int BruteForceStringMatch(const std::string &tstr, const std::string &pstr) {
	for (std::size_t i = 0; i <= tstr.size() - pstr.size(); ++i) {
		std::size_t j = 0;
		while (j < pstr.size() && pstr[j] == tstr[i + j]) {
			j++;
		}
		
		if (j == pstr.size()) {
			return i;
		}
	}

	return -1;
}
*/
