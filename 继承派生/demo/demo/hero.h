#pragma once
/*************************************************
 *文件名：hero.h
 *描  述：英雄基类/父类-公有继承
 *作  者：冯洲
 *时  间：2020.12.05:20.06
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

	/**基类中的移动方法*/
	//增加virtual关键字，告诉编译器这个方法需要子类重写。
	virtual void Move();					//英雄的默认移动方法

	friend ostream & operator<<(ostream & out, const hero & hero);				//重载输出流<<

	const string & GetNickName() const { return m_NickName; }					//得到英雄名称
	const int & GetLevel()const { return m_Level; }								//得到英雄等级
	const int & GetMaxLife()const { return m_MaxLife; }						//得到英雄最大生命
	const int & GetCurrLife()const { return m_CurrLife; }						//得到英雄当前生命

	void SetNickName(const string & nickname) {	this->m_NickName = nickname; }
	void SetLevel(int level) { this->m_Level = level; }
	void SetMaxLife(int maxlife) { this->m_MaxLife = maxlife; }
	void SetCurrLife(int currlife) { this->m_CurrLife = currlife; }
protected:

private:
	string m_NickName;			//英雄名称
	int m_Level;				//英雄等级
	int m_MaxLife;				//英雄最大生命值
	int m_CurrLife;				//英雄当前生命值
};

