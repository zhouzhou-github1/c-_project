#pragma once
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


class Circle
{
public:
//	Circle();
	Circle(float radius = 0) :radius(radius) {
		area = float(M_PI * pow(double(radius), 2));
	}

	friend ostream & operator<<(ostream & out, const  Circle & circle);
//	~Circle();
protected:


private:
	float radius;		//°ë¾¶
	float area;			//Ãæ»ý
};

