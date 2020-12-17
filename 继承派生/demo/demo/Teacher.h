#pragma once
/*************************************************
 *�ļ�����Teacher.h
 *��  ������ʦ����-˽�м̳�
 *��  �ߣ�����
 *ʱ  �䣺2020.12.06:18.20
 *************************************************/

#include <iostream>
#include <string>

using namespace std;

/****************************************
 * ������ʾ˽�м̳е�����һ���÷�       *
 * ʵ����Ϲ�ϵ:                        *
 * Teacher��������string���͵ĳ�Աname  *
 ****************************************/

class Teacher : private string	//˽�м̳�
{
public:
	Teacher();
	Teacher(int _salary) :salary(_salary) {}
	~Teacher();
	//string nickname;			//ʹ����Ϲ�ϵʵ�֣��Ƚϼ�  has-a

	//�ѵ�;
	const string & Getname() const {
		/*********************************************************************************************
		 *  Teacher������string��˽���������������Կ���ʹ��ǿ������ת����Teacher����ת��Ϊstring���� *
		 *  Ϊ�˱�����ù��캯�������µĶ�������ǿ��ת����string����������������                   *
		 *  ����������һ�����ã�ָ����ñ�������Teacher�����еļ̳ж�����string����                  *
		 *********************************************************************************************/
		return (const string&)*this;
	}

	//���ص�ǰ��ʦ�����������ַ�������
	using string::length;					//���ַ�����������Ϊ����Ĺ��з���
	int GetLength() {
		return string::length();
	}

	double GetSalary() { return salary; }
	void SetSalary(double salary) { this->salary = salary; }
protected:

private:
	double salary;				//����

};

