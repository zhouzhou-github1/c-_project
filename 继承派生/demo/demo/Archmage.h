#pragma once
/*************************************************
 *文件名：Archmage.h
 *描  述：法师英雄派生类/子类-公有继承
 *作  者：冯洲
 *时  间：2020.12.05:21.20
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

	//c++11版本后，为了更好体现子类方法重写父类方法，可以在重写方法后添加override关键字
	void Move()override;
	void BiuBiuBiu(Warrior & other);		//法师对战士的伤害
	void BiuBiuBiu(Archmage & other);
protected:

private:
	int m_MagicalAttack;

};

