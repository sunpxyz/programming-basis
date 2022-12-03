// Chapter 03. Brute Force
// BruteForceClosestPoints.cpp
// 2017.09.30

/*
#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>


typedef struct {
	double x;
	double y;
} Point;

void BruteForceClosestPoints(const std::vector<Point> &ps);


int main() {
	std::cout << "The number of points that you want to input:";

	std::size_t n;
	std::cin >> n;
	
	Point point;
	std::vector<Point> vp;
	for (std::size_t i = 0; i < n; ++i) {
		std::cin >> point.x >> point.y;
		
		vp.push_back(point);
	}
	
	BruteForceClosestPoints(vp);

	return 0;
}


void BruteForceClosestPoints(const std::vector<Point> &ps) {
	double minDist = DBL_MAX;
	Point point1, point2;
	
	for (std::size_t i = 0; i < ps.size() - 1; ++i) {
		for (std::size_t j = i + 1; j < ps.size(); ++j) {
			double dist = std::sqrt(std::pow(ps[i].x - ps[j].x, 2) 
									+ std::pow(ps[i].y - ps[j].y, 2));
			if (dist < minDist) {
				minDist = dist;

				point1.x = ps[i].x;
				point1.y = ps[i].y;
				point2.x = ps[j].x;
				point2.y = ps[j].y;
			}
		}
	}

	std::cout << "The shortest distance between two points is: "
              << minDist << "\n\tthe two points are"
              << " (" << point1.x << "," << point1.y << "), "
              << " (" << point2.x << "," << point2.y << ")" << std::endl;
}
*/
