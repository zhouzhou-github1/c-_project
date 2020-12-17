#pragma once
/*************************************************
 *文件名：Assassin.h
 *描  述：刺客英雄派生类/子类-公有继承
 *作  者：冯洲
 *时  间：2020.12.06:21.00
 *************************************************/

#include <iostream>
#include <string>
#include "hero.h"

 /****************************************
  *       体会游戏是如何进行升级的       *
  *  假设游戏需要添加一个新的职业：刺客  *
  * 前提：核心业务类hero肯定不能进行修改 *
  ****************************************/
class Assassin : public hero
{
public:
	Assassin();
	Assassin(const string &nikename, int power) : hero(nikename), m_power(power) {}
	~Assassin();

	//体会升级的Move方法
	void Move() override {
		cout << "隐藏在黑暗中的刺客：" << GetNickName() << "正在偷偷潜入" << endl;
	}

protected:

private:
	int m_power;		//刺客能量值
};

