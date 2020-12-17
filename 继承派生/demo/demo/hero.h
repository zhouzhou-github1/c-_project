#pragma once
/*************************************************
 *�ļ�����hero.h
 *��  ����Ӣ�ۻ���/����-���м̳�
 *��  �ߣ�����
 *ʱ  �䣺2020.12.05:20.06
 *************************************************/

#include <iostream>
#include <string>
//#include "Warrior.h"
//#include "Archmage.h"
using namespace std;


class hero
{
public:
	hero();
	~hero();
	hero(const string & nickname);
	hero(const string & nickname, int level);
	hero(const string & nickname, int level, int maxlife, int currlife);

	/**�����е��ƶ�����*/
	//����virtual�ؼ��֣����߱��������������Ҫ������д��
	virtual void Move();					//Ӣ�۵�Ĭ���ƶ�����

	friend ostream & operator<<(ostream & out, const hero & hero);				//���������<<

	const string & GetNickName() const { return m_NickName; }					//�õ�Ӣ������
	const int & GetLevel()const { return m_Level; }								//�õ�Ӣ�۵ȼ�
	const int & GetMaxLife()const { return m_MaxLife; }						//�õ�Ӣ���������
	const int & GetCurrLife()const { return m_CurrLife; }						//�õ�Ӣ�۵�ǰ����

	void SetNickName(const string & nickname) {	this->m_NickName = nickname; }
	void SetLevel(int level) { this->m_Level = level; }
	void SetMaxLife(int maxlife) { this->m_MaxLife = maxlife; }
	void SetCurrLife(int currlife) { this->m_CurrLife = currlife; }
protected:

private:
	string m_NickName;			//Ӣ������
	int m_Level;				//Ӣ�۵ȼ�
	int m_MaxLife;				//Ӣ���������ֵ
	int m_CurrLife;				//Ӣ�۵�ǰ����ֵ
};

