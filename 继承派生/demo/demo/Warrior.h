#pragma once
/*************************************************
 *�ļ�����Warrior.h
 *��  ����սʿӢ��������/����-���м̳�
 *��  �ߣ�����
 *ʱ  �䣺2020.12.05:20.50
 *************************************************/

#include <iostream>
#include <string>
#include "hero.h"
//#include "Archmage.h"

class Archmage;							//��սʿ����������ʦ��

class Warrior : public hero				//���м̳У�����ļ̳з�ʽ��������is-a��ϵ
{
public:
	Warrior();
	Warrior(const string nickname, int phyattack);
	~Warrior();

	void Move()override;			//��������ʵ��Move����
	void HiSunZi();

	//���������ʽֻ֧��սʿ������ζ��Ӣ�����͵����ӣ�սʿ�Ĺ�������Ҳ���ʮ�ָ���
	//void XiaoQuanQuan(Warrior & other);		//�����������һ��սʿ����
	//void XiaoQuanQuan(Archmage & other);		//�����������һ��սʿ����

	void XiaoQuanQuan(hero & other);		//ʹ�ö�̬��������
protected:

private:
	int m_PhysicalAttack;
};

