#pragma once
#include <iostream>
#include <cstring>
#include "Circle.h"
using namespace std;

//�Զ���ľ�����
class Rectangle
{
public:
	Rectangle();							//�޲ι���,���ɱ������Զ�������
	Rectangle(float width,float height);	//���ι���
	Rectangle(const Rectangle & rect);		//��������
	Rectangle(float width);					//ת������---����������ת��Ϊ��ǰ����ʹ��

	operator float() const {				//������ת����float���ͣ���������Ҫ�󲻸ı䵱ǰ��������const
		return width;
	}
	operator Circle() const {				//����ת��ΪԲ  �Կ�Ϊֱ��
		return Circle(width / 2);
	}
	//�����������ں���һ���д��
	//Rectangle(float width = 0, float height = 0) :width(width), height(height)
	//{
	//}
	void display() {
		cout << "width:" << width << ",heigth:" << height << endl;
	}
//	Rectangle(String str);
//	~Rectangle();							//��Ϊû��ָ�룬���ԾͲ�������������
protected:

private:
	float width;
	float height;

};

