#pragma once
/*************************************************
 *�ļ�����ViatualPoint.h
 *��  ����ѧϰ�麯��ԭ��ʵ��ԭ��   ��Ҫ����麯�����е�ַ��
 *��  �ߣ�����
 *ʱ  �䣺2020.12.15.20:30
 *************************************************/

#include <iostream>

using namespace std;

class Base {		//����
private:
	int member;
	int member2;
public:
	Base() { member = 9527; member2 = 6666; }

	virtual void baseVirtual1() {
		cout << "�����е��麯���汾1" << endl;
	}
	virtual void baseVirtual2() {
		cout << "�����е��麯���汾2" << endl;
	}
	virtual void baseVirtual3() {
		cout << "�����е��麯���汾3" << endl;
	}

};

class Son :public Base {		//����
private:

public:
	void baseVirtual2() override{
		cout << "��������Ψһʵ�ֵ�2�Ű汾�����麯��" << endl;
	}

};