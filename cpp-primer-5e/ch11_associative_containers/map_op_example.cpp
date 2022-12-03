// ch11_associative_containers
// map_op_example.cpp
// 2019.05.04


#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <fstream>


void word_transform(std::ifstream &map_file, std::ifstream &input);
std::map<std::string, std::string> buildMap(std::ifstream &map_file);
const std::string& transform(const std::string &s,
		const std::map<std::string, std::string> &m);

//
//
void word_transform(std::ifstream &map_file, std::ifstream &input) {
	auto trans_map = buildMap(map_file);
	std::string text;
	while (getline(input, text)) {
		std::istringstream stream(text);
		std::string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword) {
				firstword = false;
			} else {
				std::cout << " ";
			}
			std::cout << transform(word, trans_map);
		}
		std::cout << std::endl;
	}
}


//
//
std::map<std::string, std::string> buildMap(std::ifstream &map_file) {
	std::map<std::string, std::string> trans_map;
	std::string key, value;
	while (map_file >> key && getline(map_file, value)) {
		if (value.size() > 1) {
			trans_map[key] = value.substr(1);
		} else {
			throw std::runtime_error("no rule for " + key);
		}
	}
	return trans_map;
}


//
//
const std::string& transform(const std::string &s,
		const std::map<std::string, std::string> &m) {
	auto map_it = m.find(s);
	if (map_it != m.cend()) {
		return map_it->second;
	} else {
		return s;
	}
}


int main()
{
	std::ifstream ifs1("file1.txt");
	std::ifstream ifs2("file2.txt");

	word_transform(ifs1, ifs2);

	return 0;
}
