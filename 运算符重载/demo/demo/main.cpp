#include <iostream>
#include "integer.h"
#include "MyString.h"
#include "Array.h"
#include "MyVector.h"
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

void TestInteger();
void TestString();
void TestArray();
void TestVector();
void TestRectangle();
int main()
{
	cout << "测试"  << endl;
//	TestString();
//	TestArray();
//	TestVector();
	TestRectangle();
}
void TestInteger()
{
/*	integer int1(1000), int2(2000), int3;
	int3 = int1 + int2;
	cout << "int3 = int1 + int2" << int3.IntValue() << endl;*/
}
void TestString()
{
	String str1;
	String str2("abc");
	String str3("显示中文");
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str2 = str3;			//如果不进行 = 的运算符重置就会产生错误，因为他幅值的是指针(指向同一空间)，而不是数组元素
	cout << str2 << endl;
	cout << str3 << endl;

	String str4(str2);		//拷贝构造
	cout << str4 << endl;
}
void TestArray()
{
	Array arr1(10);			//默认幅值
	arr1[0] = 1234;
//	arr1[11] = 1234;		//越界
	cout << arr1 << endl;
}

void TestVector()
{
	MyVector<int> vec1;
	MyVector<double> vec2(10,99.9);
	cout << "vec1:" << vec1 << endl;
	cout << "vec2:" << vec2 << endl;

/*	MyVector<String> vec3(5,String("abc"));			//有问题输出乱码了
	cout << "vec3:" << vec3 << endl;*/

	vec2.push_back(123);
	cout << "vec2:" << vec2 << endl;
}

void TestRectangle()
{
	Rectangle rect1;				//调用默认构造
	Rectangle rect2(25.0,25.2);		//带参构造
	Rectangle rect3(rect2);			//拷贝构造
	//*********能否与基本类型进行互相转换*******
	Rectangle rect4 = 55;			//正方形   会调用一个参数的构造，称之为转换构造
	Rectangle rect5(55);			//会调用唯一参数的构造
	rect4.display();
	rect3.display();

	float rect4_width = float(rect4);		//类型转换函数  
	cout << "rect4_width:" << rect4_width << endl;

	Circle circle1 = rect4;
	cout << "圆信息circle1:" << circle1 << endl;
}