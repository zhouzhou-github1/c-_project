/*************************************************
 *�ļ�����main.cpp
 *��  ��������ѧϰ�麯����ԭ��
 *��  �ߣ�����
 *ʱ  �䣺2020.12.15��20:30
 *************************************************/

#include <iostream>
#include "VirtualPoint.h"		//�麯������
#include "Employee.h"
#include "Admin.h"

using namespace std;

void VirtualPointTest();
void EmployeeTest();
int main()
{
	cout << "haha" <<endl;
	VirtualPointTest();
//	EmployeeTest();
	return 0;
}

void VirtualPointTest()
{
	Base base;		//�������
	int* baseAddress = (int*)&base;		//ת���ɵ�ַΪ������ָ�룬����ָ���ƶ���ת��
	cout << "��������ַ��" << baseAddress << endl;
//	cout << "��������ַ��" << &base << endl;

	/*������ָ���ַ*/
	int* virTablePtr = (int*)*(baseAddress + 0);		//����������������Ԫ�ص�ַ��˼��ͬ
	cout << "���س�Ա���麯�����ָ���ַ��" << virTablePtr << endl;

	/*�൱��virTablePtrΪ�麯����ĵ�ַ��Ȼ���ټ�һ��*��ʾȡ�麯�������麯���ĵ�ַ **/
	int* virFunctionPtr1 = (int*)*(virTablePtr + 0);
	cout << "�麯�����е�һ���麯���ĵ�ַ��" << virFunctionPtr1 << endl;
	int* virFunctionPtr2 = (int*)*(virTablePtr + 1);		//VS20XX�汾+1���ɣ�������������ͬgcc+2
	cout << "�麯�����еڶ����麯���ĵ�ַ��" << virFunctionPtr2 << endl;
	int* virFunctionPtr3 = (int*)*(virTablePtr + 2);
	cout << "�麯�����е������麯���ĵ�ַ��" << virFunctionPtr3 << endl;

	//ǿ��ת���ɺ���������
	void(*BaseVirtual1)() = (void(*)())virFunctionPtr1;
	BaseVirtual1();
	void(*BaseVirtual2)() = (void(*)())virFunctionPtr2;
	BaseVirtual2();

	//ȡ����һ��˽�г�Ա
	int* memberPtr = (int*)(baseAddress + 1);
	cout << "��һ��˽�г�Աmember��ֵ��" << *memberPtr << endl;
//	cout << "��һ��˽�г�Աmember��ֵ��" << (int)*(baseAddress + 1) << endl;
	int* memberPtr2 = (int*)(baseAddress + 2);
	cout << "�ڶ���˽�г�Աmember��ֵ��" << *memberPtr2 << endl;

	//�������ж�����ڴ���Ϣ
	cout << "-------�������ж�����ڴ���Ϣ-------" << endl;
	Son son;
	int* sonAddress = (int*)&son;
	cout << "���������ĵ�ַ��" << sonAddress << endl;

	virTablePtr = (int*)*(sonAddress + 0);
	cout << "����������麯�����ָ���ַ��" << virTablePtr << endl;
	virFunctionPtr1 = (int*)*(virTablePtr + 0);
	cout << "����������麯�����е�һ���麯���ĵ�ַ��" << virFunctionPtr1 << endl;
	virFunctionPtr2 = (int*)*(virTablePtr + 1);		//VS20XX�汾+1���ɣ�������������ͬgcc+2
	cout << "����������麯�����еڶ����麯���ĵ�ַ��" << virFunctionPtr2 << endl;
	virFunctionPtr3 = (int*)*(virTablePtr + 2);
	cout << "����������麯�����е������麯���ĵ�ַ��" << virFunctionPtr3 << endl;

	void(*SonVirtual2)() = (void(*)())virFunctionPtr2;
	SonVirtual2();

	//delete baseAddress;
	//delete virTablePtr;
	//delete virFunctionPtr1;
	//delete virFunctionPtr2;
	//delete virFunctionPtr3;
	//delete memberPtr;
	//delete memberPtr2;
	//delete sonAddress;

}

void EmployeeTest()
{
	Employee* emm = new Employee;
	delete emm;
	cout << "---------------------" << endl;
	Admin* admin = new Admin;
	delete admin;
	cout << "----------��̬������ָ��ָ��������-----------" << endl;
	Employee* emm1 = new Admin;		//ģ�⴫��ʱ���Զ�����ת��������ת��
	//��������Ƿ���������������ͷ��������ʱ��ֻ����ø������������������������
	//���������������������Ϊ������    
	delete emm1;
}