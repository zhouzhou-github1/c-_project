#pragma once
/*************************************************
 *�ļ�����Archmage.h
 *��  ������ʦӢ��������/����-���м̳�
 *��  �ߣ�����
 *ʱ  �䣺2020.12.05:21.20
 *************************************************/

#include <iostream>
#include <string>
#include "hero.h"
//#include "Warrior.h"

class Warrior;

class Archmage : public hero
{
public:
	Archmage();
	~Archmage();
	Archmage(const string nikename, int magicalattack);

	//c++11�汾��Ϊ�˸����������෽����д���෽������������д���������override�ؼ���
	void Move()override;
	void BiuBiuBiu(Warrior & other);		//��ʦ��սʿ���˺�
	void BiuBiuBiu(Archmage & other);
protected:

private:
	int m_MagicalAttack;

};

