#pragma once
/*************************************************
 *文件名：Teacher.h
 *描  述：老师子类-私有继承
 *作  者：冯洲
 *时  间：2020.12.06:18.20
 *************************************************/

#include <iostream>
#include <string>

using namespace std;

/****************************************
 * 用来演示私有继承的其中一种用法       *
 * 实现组合关系:                        *
 * Teacher类中用于string类型的成员name  *
 ****************************************/

class Teacher : private string	//私有继承
{
public:
	Teacher();
	Teacher(int _salary) :salary(_salary) {}
	~Teacher();
	//string nickname;			//使用组合关系实现，比较简单  has-a

	//难点;
	const string & Getname() const {
		/*********************************************************************************************
		 *  Teacher类是由string类私有派生而来，所以可以使用强制类型转换将Teacher类型转换为string类型 *
		 *  为了编码调用构造函数创建新的对象，所以强制转换成string的引用类型来返回                   *
		 *  本方法返回一个引用，指向调用本方法的Teacher对象中的继承而来的string对象                  *
		 *********************************************************************************************/
		return (const string&)*this;
	}

	//返回当前教师对象姓名的字符串长度
	using string::length;					//将字符串方法声明为本类的公有方法
	int GetLength() {
		return string::length();
	}

	double GetSalary() { return salary; }
	void SetSalary(double salary) { this->salary = salary; }
protected:

private:
	double salary;				//工资

};

