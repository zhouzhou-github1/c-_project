#pragma once
#include "Employee.h"
class Admin :public Employee
{
public:
	Admin() {
		//��ʽ���ø����Ĭ�Ϲ���
		cout << "���������Ĺ���" << endl;
	}
	~Admin() {
		cout << "�������������� ~Admin()" << endl;
	}
protected:

private:

};

