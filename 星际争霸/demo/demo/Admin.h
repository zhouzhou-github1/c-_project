#pragma once
#include "Employee.h"
class Admin :public Employee
{
public:
	Admin() {
		//隐式调用父类的默认构造
		cout << "派生类对象的构造" << endl;
	}
	~Admin() {
		cout << "派生类对象的析构 ~Admin()" << endl;
	}
protected:

private:

};

