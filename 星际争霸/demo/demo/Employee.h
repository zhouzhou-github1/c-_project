#pragma once
/*************************************************
 *�ļ�����Employee.h
 *��  ����ѧϰ�麯�� ��������Ӧ�����麯��	��Ա������   ��������ΪʲôҪ����������
 *��  �ߣ�����
 *ʱ  �䣺2020.12.15.22:00
 *************************************************/
#include <iostream>

using namespace std;

class Employee
{
public:
	Employee() { 
		name = new char[20]; 
		cout << "����20��charԪ�ؿռ�" << endl;
	}
	virtual ~Employee() {
		delete name;
		cout << "�ͷŷ��������ռ� ~Employee()" << endl;
	}
protected:
	char* name;			//Ա������
private:

};

