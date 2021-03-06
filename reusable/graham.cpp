#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

pair<double, double> centroid;

pair<double, double> getCentroid(vector<pair<double, double> > pts) {
	pair<double, double> centroid;
	for (int i = 0; i < pts.size(); i++) {
		centroid.first += pts[i].first;
		centroid.second += pts[i].second;
	}
	if (pts.size() > 0) {
		centroid.first /= pts.size();
		centroid.second /= pts.size();
	}
	return centroid;
}

double getAngle(pair<double, double> centroid, pair<double, double> p) {
	double angle = atan2(p.second - centroid.second, p.first - centroid.first);
	return angle;
}

int cmpByAngle(pair<double, double> p1, pair<double, double> p2) {
	return getAngle(centroid, p1) < getAngle(centroid, p2);
}

double crossProd(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3) {
    return (p2.first - p1.first) * (p3.second - p1.second)
    		- (p2.second - p1.second) * (p3.first - p1.first);
}

vector<pair<double, double> > graham(vector<pair<double, double> > pts) {
	vector<pair<double, double> > hull;
	if (pts.size() >= 3) {
		centroid = getCentroid(pts);
		sort(pts.begin(), pts.end(), &cmpByAngle);
		//start scanning
		hull.push_back(pts[0]);
		hull.push_back(pts[1]);
		for (int i = 2; i < pts.size() - 1; i++) {
			while (hull.size() >= 2 && crossProd(hull[hull.size() - 2]
					, hull[hull.size() - 1], pts[i]) <= 0) {
				hull.pop_back();
			}
			hull.push_back(pts[i]);
		}
		pair<double, double> p = pts[pts.size() - 1];
		while (hull.size() >= 2 && crossProd(hull[hull.size() - 2]
				, hull[hull.size() - 1], p) <= 0) {
			hull.pop_back();
		}
		bool done = false;
		int start = 0;
		while (!done) {
			done = true;
			if (hull.size() - start >= 2) {
				if (crossProd(hull[hull.size() - 1], p, hull[start]) <= 0) {
					p = hull[hull.size() - 1];
					hull.pop_back();
					done = false;
				}
				if (crossProd(p, hull[start], hull[start + 1]) <= 0) {
					//remove starting point
					start++;
					done = false;
				}
			}
		}
		hull.push_back(p);
		//copy hull into a new vector that doesn't contain the starting points that were removed
		vector<pair<double, double> > temp(hull.size() - start);
		for (int i = 0; i < hull.size() - start; i++) {
			temp[i] = hull[start + i];
		}
		hull = temp;
	}
	return hull;
}