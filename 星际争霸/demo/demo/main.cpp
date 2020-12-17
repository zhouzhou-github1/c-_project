/*************************************************
 *文件名：main.cpp
 *描  述：用来学习虚函数的原理
 *作  者：冯洲
 *时  间：2020.12.15：20:30
 *************************************************/

#include <iostream>
#include "VirtualPoint.h"		//虚函数测试
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
	Base base;		//基类对象
	int* baseAddress = (int*)&base;		//转换成地址为长整型指针，方便指针移动和转换
	cout << "基类对象地址：" << baseAddress << endl;
//	cout << "基类对象地址：" << &base << endl;

	/*虚拟表的指针地址*/
	int* virTablePtr = (int*)*(baseAddress + 0);		//与数组名是数组首元素地址意思相同
	cout << "隐藏成员：虚函数表的指针地址：" << virTablePtr << endl;

	/*相当于virTablePtr为虚函数表的地址，然后再加一个*表示取虚函数表中虚函数的地址 **/
	int* virFunctionPtr1 = (int*)*(virTablePtr + 0);
	cout << "虚函数表中第一个虚函数的地址：" << virFunctionPtr1 << endl;
	int* virFunctionPtr2 = (int*)*(virTablePtr + 1);		//VS20XX版本+1即可，其他编译器不同gcc+2
	cout << "虚函数表中第二个虚函数的地址：" << virFunctionPtr2 << endl;
	int* virFunctionPtr3 = (int*)*(virTablePtr + 2);
	cout << "虚函数表中第三个虚函数的地址：" << virFunctionPtr3 << endl;

	//强制转换成函数来调用
	void(*BaseVirtual1)() = (void(*)())virFunctionPtr1;
	BaseVirtual1();
	void(*BaseVirtual2)() = (void(*)())virFunctionPtr2;
	BaseVirtual2();

	//取出第一个私有成员
	int* memberPtr = (int*)(baseAddress + 1);
	cout << "第一个私有成员member的值：" << *memberPtr << endl;
//	cout << "第一个私有成员member的值：" << (int)*(baseAddress + 1) << endl;
	int* memberPtr2 = (int*)(baseAddress + 2);
	cout << "第二个私有成员member的值：" << *memberPtr2 << endl;

	//派生类中对象的内存信息
	cout << "-------派生类中对象的内存信息-------" << endl;
	Son son;
	int* sonAddress = (int*)&son;
	cout << "派生类对象的地址：" << sonAddress << endl;

	virTablePtr = (int*)*(sonAddress + 0);
	cout << "派生类对象虚函数表的指针地址：" << virTablePtr << endl;
	virFunctionPtr1 = (int*)*(virTablePtr + 0);
	cout << "派生类对象虚函数表中第一个虚函数的地址：" << virFunctionPtr1 << endl;
	virFunctionPtr2 = (int*)*(virTablePtr + 1);		//VS20XX版本+1即可，其他编译器不同gcc+2
	cout << "派生类对象虚函数表中第二个虚函数的地址：" << virFunctionPtr2 << endl;
	virFunctionPtr3 = (int*)*(virTablePtr + 2);
	cout << "派生类对象虚函数表中第三个虚函数的地址：" << virFunctionPtr3 << endl;

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
	cout << "----------多态：基类指针指向派生类-----------" << endl;
	Employee* emm1 = new Admin;		//模拟传参时的自动类型转换：向上转型
	//如果父类是非虚的析构函数，释放子类对象时就只会调用父类析构，不会调用子类析构
	//解决方案：将父类析构变为虚析构    
	delete emm1;
}