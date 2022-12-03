// ch11_associative_containers
// intro_associative_container.cpp
// 2019.05.02


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>


int main()
{
	std::map<std::string, std::string> authors = {
			{"Joyce", "James"}, {"Austen", "Jane"}, {"Dickens", "Charles"}};

	std::vector<int> ivec;
	for (std::vector<int>::size_type i = 0; i != 10; ++i) {
		ivec.push_back(i);
		ivec.push_back(i);
	}

	std::set<int> iset(ivec.cbegin(), ivec.cend());
	std::multiset<int> miset(ivec.cbegin(), ivec.cend());

	std::cout << ivec.size() << std::endl;
	std::cout << iset.size() << std::endl;
	std::cout << miset.size() << std::endl;

	std::pair<std::string, std::string> anon{"James", "Jopyce"};

	std::set<std::string>::value_type v1;
	std::set<std::string>::key_type v2;
	std::map<std::string, int>::value_type v3;
	std::map<std::string, int>::key_type v4;
	std::map<std::string, int>::mapped_type v5;

	return 0;
}
