#pragma once
/*************************************************
 *�ļ�����Assassin.h
 *��  �����̿�Ӣ��������/����-���м̳�
 *��  �ߣ�����
 *ʱ  �䣺2020.12.06:21.00
 *************************************************/

#include <iostream>
#include <string>
#include "hero.h"

 /****************************************
  *       �����Ϸ����ν���������       *
  *  ������Ϸ��Ҫ���һ���µ�ְҵ���̿�  *
  * ǰ�᣺����ҵ����hero�϶����ܽ����޸� *
  ****************************************/
class Assassin : public hero
{
public:
	Assassin();
	Assassin(const string &nikename, int power) : hero(nikename), m_power(power) {}
	~Assassin();

	//���������Move����
	void Move() override {
		cout << "�����ںڰ��еĴ̿ͣ�" << GetNickName() << "����͵͵Ǳ��" << endl;
	}

protected:

private:
	int m_power;		//�̿�����ֵ
};

