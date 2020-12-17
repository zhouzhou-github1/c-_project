/*************************************************
 *文件名：main.cpp
 *描  述：实现星际争霸
 *作  者：冯洲
 *时  间：2020.12.16：16:20
 *************************************************/

#include <iostream>
#include <vector>
#include "AbstractClassDemo.h"
using namespace std;

void AbstractClassTest();
int main()
{
	cout << "haha" <<endl;
	AbstractClassTest();
	return 0;
}

void AbstractClassTest()
{
	//尝试实例化一个抽象类对象
	//BattleUnit unit;
	Marine marine1("巫妖王");
	Marine marine2("死亡骑士");
	marine1.Fight(marine2);

	siegeTank tank1("坦克1");
	tank1.Move(10, 20);

	Viking viking1("北欧海盗");
	vector<BattleUnit*> units;
	units.push_back(&marine1);			//注意加&  因为定义的是指针
	units.push_back(&marine2);
	units.push_back(&tank1);
	units.push_back(&viking1);
	cout << "-----------------------------------" << endl;
	Commander commander;
	cout << "让指挥官移动多个类型的战斗单位" << endl;
	commander.Move(units, 30, 40);

}