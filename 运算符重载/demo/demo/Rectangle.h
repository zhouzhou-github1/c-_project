#pragma once
#include <iostream>
#include <cstring>
#include "Circle.h"
using namespace std;

//自定义的矩形类
class Rectangle
{
public:
	Rectangle();							//无参构造,可由编译器自定义生成
	Rectangle(float width,float height);	//带参构造
	Rectangle(const Rectangle & rect);		//拷贝构造
	Rectangle(float width);					//转换构造---把其他类型转换为当前类型使用

	operator float() const {				//将矩形转换成float类型，给宽。并且要求不改变当前对象，所以const
		return width;
	}
	operator Circle() const {				//矩形转换为圆  以宽为直径
		return Circle(width / 2);
	}
	//将几个构造融合在一起的写法
	//Rectangle(float width = 0, float height = 0) :width(width), height(height)
	//{
	//}
	void display() {
		cout << "width:" << width << ",heigth:" << height << endl;
	}
//	Rectangle(String str);
//	~Rectangle();							//因为没有指针，所以就不用析构函数了
protected:

private:
	float width;
	float height;

};

