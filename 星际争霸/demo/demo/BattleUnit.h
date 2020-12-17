#pragma once
/*************************************************
 *文件名：BattleUnit.h
 *描  述：学习虚函数，战斗类单位   父类
 *作  者：冯洲
 *时  间：2020.12.15.20:30
 *************************************************/


class BattleUnit
{
public:
	BattleUnit();
	~BattleUnit();

	virtual void Fight(BattleUnit& unit);
	virtual void Move(int x, int y);
protected:

private:

};

