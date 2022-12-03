// Search anagrams set in dictionary.
// Sun Peng, 17301250
// 2018.01.11


#include <iostream>  
#include <fstream>
#include <map>      
#include <string>   
#include <vector>
#include <algorithm>

//control if print debug information
#define PRINT_DEBUG_INFO 1

bool compare(char lc, char rc) { return (lc < rc); }


int main() {
	std::string inFile = "words.txt";
	std::string outFile = "anags.txt";

	//anagram set map, key - sorted word, value - list of original word
	std::map<std::string, std::vector<std::string>> wordMap;

	std::ifstream inStr(inFile.c_str());
	if (!inStr) {
		std::cout << "Cannot open file: " + inFile << std::endl;
		return 0;
	}

	//collect anagram set
	std::string word;  //original word
	std::string keyw;  //sorted word  
	while (inStr >> word) {
		keyw = word;
		std::sort(keyw.begin(), keyw.end(), compare);

		wordMap[keyw].push_back(word);
	}
	inStr.close();

	std::ofstream outStr(outFile.c_str());
	if (!outStr) {
		std::cout << "Cannot create file: " + outFile << std::endl;
		return 0;
	}

	//output anagram set
	long long cnt = 0;
	for (auto itMap = wordMap.begin(); itMap != wordMap.end(); ++itMap) {
		if (itMap->second.size() > 1) {
			cnt++;
			std::string debugStr;
			for (auto itVec = itMap->second.begin(); itVec != itMap->second.end(); ++itVec) {
				outStr << *itVec << " ";
				debugStr += *itVec + " ";
			}
			outStr << std::endl;
#ifdef PRINT_DEBUG_INFO
			std::cout << "AnagSet[" << cnt << "]: " << debugStr << std::endl;
#endif
		}
	}
	outStr.close();

	return 0;
}

