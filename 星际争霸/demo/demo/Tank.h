#pragma once
/*************************************************
 *�ļ�����Tank.h
 *��  ����ѧϰ�麯����̹���൥Ԫ  ����
 *��  �ߣ�����
 *ʱ  �䣺2020.12.15.20:30
 *************************************************/

#include "BattleUnit.h"
#include <iostream>

using namespace std;

class Tank: public BattleUnit
{
public:
	Tank();
	~Tank();

	void Move(int x, int y) override {
		cout << "��������������ʵ��" << endl;
	}
protected:

private:

};

