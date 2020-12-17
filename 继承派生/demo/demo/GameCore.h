#pragma once
/*************************************************
 *文件名：GameCore.h
 *描  述：学习多态，实现英雄的移动
 *作  者：冯洲
 *时  间：2020.12.06:19.50
 *************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "hero.h"
#include "Warrior.h"
#include "Archmage.h"

using namespace std;

/*************************************************
 *  游戏引擎/游戏业务/游戏核心类
 *************************************************/
class GameCore
{
public:
	GameCore();
	~GameCore();

/*与main.cpp中GameCoreTest()一同

	//重载：函数名相同，参数列表类型/数量不同
	//定义一个函数，用来移动游戏角色----静态多态
	void MoveRole(Warrior & warrior) {
		warrior.Move();				//实际上就是调用传入战士的移动方法
	}

	void MoveRole(Archmage & archmage) {
		archmage.Move();
	}
	void MoveRole(hero & hero) {
		hero.Move();
	}

	//动态多态  移动数组英雄
	void MoveRole(vector<Warrior*> vec_warrior) {			//这里放引用会保存，就放指针即可
		for (auto warrior : vec_warrior) {  //这里的auto是编译器自动帮你确认类型，而不是转换类型。 但是开发项目时尽量少于auto，因为会增加编译时间
			warrior->Move();
		}
	}

*/

	/*************************************************************************************
     * 为了能够让同一函数操作不同类型的子类对象，所以我们把参数类型定义\\\成基类///对象  *
	 *   当传递hero类型的子类型时，参数类型可以自动转换：
	 * 关于向上和向下转换：
	 *1、当B是A的子类型时，(B : public A)，就意味着所有对A的操作都可以对B对象进行操作(自动转换)
	 *   即：B重用A的操作来实现自己的操作
	 *  向上转型：把子类型转换为父类型对象，有三个注意点：
	 * ①向上转型是安全的；
	 * ②向上转型可以自动类型转换；
	 * ③向上转型过程中会丢失子类型信息(缺点)
	 *eg：Warrior w;   w.XiaoQuanQuan();
	 *	Warrior warrior;			//定义子类型
	 *	hero & hero = warrior;		//父类型引用指向子类型---向上转型
	 *	hero.XiaoQuanQuan();		//编译器会报错
	 * //如果还想调用子类型方法，那么就需要再进行强制转换---向下转型
	 *	Warrior & newWarrior = (Warrior&)hero;		//向下转型不安全，因为hero对象可能是hero父类型的另一个子类型
	 *假如程序是这样的：
	 *	Archmage warrior;
	 *	hero & hero = warrior;
	 *	Warrior & newWarrior = (Warrior&)warrior;	//运行不会报错。不安全
     *************************************************************************************/
	void MoveRole(hero & hero) {		//向上转型移动安全
		hero.Move();			//调用统一英雄移动方法
	}

protected:

private:

};

