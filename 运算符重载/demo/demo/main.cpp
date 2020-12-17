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
	cout << "����"  << endl;
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
	String str3("��ʾ����");
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str2 = str3;			//��������� = ����������þͻ����������Ϊ����ֵ����ָ��(ָ��ͬһ�ռ�)������������Ԫ��
	cout << str2 << endl;
	cout << str3 << endl;

	String str4(str2);		//��������
	cout << str4 << endl;
}
void TestArray()
{
	Array arr1(10);			//Ĭ�Ϸ�ֵ
	arr1[0] = 1234;
//	arr1[11] = 1234;		//Խ��
	cout << arr1 << endl;
}

void TestVector()
{
	MyVector<int> vec1;
	MyVector<double> vec2(10,99.9);
	cout << "vec1:" << vec1 << endl;
	cout << "vec2:" << vec2 << endl;

/*	MyVector<String> vec3(5,String("abc"));			//���������������
	cout << "vec3:" << vec3 << endl;*/

	vec2.push_back(123);
	cout << "vec2:" << vec2 << endl;
}

void TestRectangle()
{
	Rectangle rect1;				//����Ĭ�Ϲ���
	Rectangle rect2(25.0,25.2);		//���ι���
	Rectangle rect3(rect2);			//��������
	//*********�ܷ���������ͽ��л���ת��*******
	Rectangle rect4 = 55;			//������   �����һ�������Ĺ��죬��֮Ϊת������
	Rectangle rect5(55);			//�����Ψһ�����Ĺ���
	rect4.display();
	rect3.display();

	float rect4_width = float(rect4);		//����ת������  
	cout << "rect4_width:" << rect4_width << endl;

	Circle circle1 = rect4;
	cout << "Բ��Ϣcircle1:" << circle1 << endl;
}