// ��30����ȷ��Ŀ�������㹻��
// tips_30.cpp
//
// 2019/8/14

#include <iostream>
#include <vector>
#include <algorithm>


int trans(int x) { return 2 * x; }


int main()
{
	std::vector<int> values{1,2,3,4,5};
	std::vector<int> result;

	result.reserve(values.size());
	std::transform(values.begin(), values.end(), std::back_inserter(result), trans);

	for (auto r: result) {
		std::cout << r << std::endl;
	}

	return 0;
}
