// ch02_variables_and_basic_types
// 2.4 const�޶���
// const.cpp
// 2019/3/14


#include <iostream>

const int ci = 1024;
const int &r = ci;
//int &r2 = ci; //����

int i = 42;
const int &r1 = i;
const int &r2 = 42;
const int &r3 = r1 * 2;

double dval = 3.14;
const int &rid = dval;

int errNum = 0;
int *const curErr = &errNum;
const double pi = 3.1415926;
const double *const pip = &pi; //ָ��������ĳ���ָ��


int main()
{
	int i = -1, &r = i;
	const int ict = 0, &rct = ict;

	return 0;
}
