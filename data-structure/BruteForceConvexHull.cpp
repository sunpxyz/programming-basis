// Chapter 03. Brute Force
// BruteForceConvexHull.cpp
// 2017.10.16

/*
#include <iostream>
#include <vector>


typedef struct Point {
	int x;
	int y;
} Point;


void BruteForceConvexHull(const std::vector<Point> &ivp, 
						  std::vector<Point> &ovp);


int main() {
	std::cout << "Input the number of points:" << std::endl;
	int n;
	std::cin >> n;

	std::vector<Point> ivp;
	Point *inp = new Point();
	for (std::size_t i = 0; i < n; ++i) {
		std::cin >> inp->x >> inp->y;
		ivp.push_back(*inp);
	}
	delete inp;

	std::vector<Point> ovp;
	BruteForceConvexHull(ivp, ovp);

	for (std::size_t i = 0; i < ovp.size(); ++i) {
		std::cout << "(" << ovp[i].x << " ," << ovp[i].y << ")  ";
	}

	return 0;
}


void BruteForceConvexHull(const std::vector<Point> &ivp,
					 	  std::vector<Point> &ovp) {
	int nPos = 0, nNeg = 0;

	int a, b, c;
	for (std::size_t i = 0; i < ivp.size() - 1; ++i) {
		for (std::size_t j = i + 1; j < ivp.size(); ++j) {
			for (std::size_t k = 0; k < ivp.size(); ++k) {
				a = ivp[j].y - ivp[i].y;
				b = ivp[i].x - ivp[j].x;
				c = ivp[i].x * ivp[j].y - ivp[i].y * ivp[j].x;

				if (a * ivp[k].x + b * ivp[k].y >= c) {
					nPos++;
				} else {
					nNeg++;
				}
			}

			if (nPos * nNeg == 0) {
				ovp.push_back(ivp[i]);
				ovp.push_back(ivp[j]);
			}

			nPos = nNeg = 0;
		}
	}

	//remove duplicated point
	for (std::size_t i = 0; i < ovp.size() - 1; ++i) {
		for (std::size_t j = i + 1; j < ovp.size(); ++j) {
			if (ovp[i].x == ovp[j].x && ovp[i].y == ovp[j].y) {
				ovp.erase(ovp.begin() + j);
			}
		}
	}
}
*/
