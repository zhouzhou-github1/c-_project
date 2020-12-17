#pragma once
/*************************************************
 *文件名：Warrior.h
 *描  述：战士英雄派生类/子类-公有继承
 *作  者：冯洲
 *时  间：2020.12.05:20.50
 *************************************************/

#include <iostream>
#include <string>
#include "hero.h"
//#include "Archmage.h"

class Archmage;							//在战士类中声明法师类

class Warrior : public hero				//公有继承：最常见的继承方式，体现了is-a关系
{
public:
	Warrior();
	Warrior(const string nickname, int phyattack);
	~Warrior();

	void Move()override;			//派生类中实现Move方法
	void HiSunZi();

	//如果攻击方式只支持战士，就意味着英雄类型的增加，战士的攻击方法也变得十分复杂
	//void XiaoQuanQuan(Warrior & other);		//攻击传入的另一个战士引用
	//void XiaoQuanQuan(Archmage & other);		//攻击传入的另一个战士引用

	void XiaoQuanQuan(hero & other);		//使用多态进行升级
protected:

private:
	int m_PhysicalAttack;
};

