// Backtrack.cpp
// 2018.01.01

/*
#include <iostream>


const int N = 8;
int pos[N];
int cnt = 0;


void printRes();
bool valid(int row);
void backTrack(int row);


int main() {
	backTrack(0);

	return 0;
}


//验证约束条件
bool valid(int row) {
	for (int i = 0; i < row; ++i) {
		if (pos[i] == pos[row] || abs(pos[i] - pos[row]) == abs(i - row)) {
			return false;
		}
	}

	return true;
}


//输出结果
void printRes() {
	++cnt;
	for (int i = 0; i < N; ++i) {
		if (i < N - 1) {
			std::cout << pos[i] + 1 << ", ";
		} else {
			std::cout << pos[i] + 1;
		}
	}
	if (cnt % 3 == 0) {
		std::cout << std::endl;
	} else {
		std::cout << "\t\t";
	}
}


//回溯求解
void backTrack(int row) {
	if (row == N) {
		printRes();
		return;
	}

	for (int col = 0; col < N; ++col) {
		pos[row] = col;
		if (valid(row)) {
			backTrack(row + 1);
		}
	}
}
*/