#pragma once
/*************************************************
 *文件名：Employee.h
 *描  述：学习虚函数 析构函数应该是虚函数	雇员：父类   用来讲解为什么要虚析构函数
 *作  者：冯洲
 *时  间：2020.12.15.22:00
 *************************************************/
#include <iostream>

using namespace std;

class Employee
{
public:
	Employee() { 
		name = new char[20]; 
		cout << "分配20个char元素空间" << endl;
	}
	virtual ~Employee() {
		delete name;
		cout << "释放分配的数组空间 ~Employee()" << endl;
	}
protected:
	char* name;			//员工姓名
private:

};

