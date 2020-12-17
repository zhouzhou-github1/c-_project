#pragma once
/*************************************************
 *文件名：ViatualPoint.h
 *描  述：学习虚函数原理，实现原理   主要理解虚函数表中地址表
 *作  者：冯洲
 *时  间：2020.12.15.20:30
 *************************************************/

#include <iostream>

using namespace std;

class Base {		//主类
private:
	int member;
	int member2;
public:
	Base() { member = 9527; member2 = 6666; }

	virtual void baseVirtual1() {
		cout << "基类中的虚函数版本1" << endl;
	}
	virtual void baseVirtual2() {
		cout << "基类中的虚函数版本2" << endl;
	}
	virtual void baseVirtual3() {
		cout << "基类中的虚函数版本3" << endl;
	}

};

class Son :public Base {		//子类
private:

public:
	void baseVirtual2() override{
		cout << "派生类中唯一实现的2号版本基类虚函数" << endl;
	}

};