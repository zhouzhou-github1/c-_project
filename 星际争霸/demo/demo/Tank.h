#pragma once
/*************************************************
 *文件名：Tank.h
 *描  述：学习虚函数，坦克类单元  子类
 *作  者：冯洲
 *时  间：2020.12.15.20:30
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
		cout << "在派生类中重新实现" << endl;
	}
protected:

private:

};

