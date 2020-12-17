#pragma once
/*************************************************
 *文件名：AbstractClassDemo.h
 *描  述：实现一个简单版星际争霸游戏，加深多态和抽象类理解
 *作  者：冯洲
 *时  间：2020.12.16：16:20
 *************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Point {				//自定义的坐标点位
public:
	Point() {}
	Point(int _x, int _y):x(_x), y(_y) {}
	int GetX() { return x; }	
	int GetY() { return y; }
	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }

	friend ostream& operator<<(ostream& out, const Point& p) {
		out << "(" << p.x << "," << p.y << ")" ;
		return out;
	}
protected:

private:
	int x;
	int y;
};
class BattleUnit			//战斗单位类---抽象类
{
public:
	BattleUnit() {}
	BattleUnit(const string& _name):name(_name) {
		maxHp = 100;
		currHp = 100;
		Point p(0,0);
		position.SetX(0);
		position.SetY(0);
		attDistance = 100;
	}
	~BattleUnit() {}

	//设置某个方法为纯虚函数后，BattleUnit就变成抽象类---只能被继承，无法实例化
	virtual void Fight(BattleUnit& unit) = 0;
	virtual void Move(int x, int y) = 0;
	virtual void Move(Point& position) = 0;
	const string& GetName()const {
		return name;
	}
protected:
	string name;
	int maxHp;
	int currHp;
	Point position;			//当前对象的坐标点
	int attDistance;		//当前对象的攻击距离
private:

};
//可以提供抽象基类纯虚函数的默认实现
void BattleUnit::Fight(BattleUnit& unit) {
	/*可以增加在每个单位作战前，根据坐标计算两者间距。如果间距超过攻击距离，则攻击失败*/
	cout << name << "正在攻击另一个战斗单位" << unit.GetName() << endl;
}
void BattleUnit::Move(int x, int y) {				//因为移动最好是在父类中实现
	position.SetX(x);
	position.SetY(y);
}


//子类：陆战队员    必须实现父类抽象类的所有纯虚函数，否则这个子类也会变成抽象类
class Marine :public BattleUnit {
public:
	Marine() {}
	Marine(const string& _name):BattleUnit(_name) {}

	void Fight(BattleUnit& unit)override;
	void Move(int x, int y) override {
		BattleUnit::Move(x, y);
		cout << "陆战队员<" << GetName() << ">收到移动命令" << "(" << position << endl;
	}
	void Move(Point& position) override {}
protected:

private:


};

void Marine::Fight(BattleUnit& unit) {
	//子类中调用父类的同名方法
	BattleUnit::Fight(unit);
	cout << "陆战队员" << GetName() << "正在攻击敌人：" << unit.GetName() << endl;
}



//攻城坦克
class siegeTank :public BattleUnit {
public:
	siegeTank() {}
	siegeTank(const string& _name):BattleUnit(_name){}
	void Fight(BattleUnit& unit)override {};
	void Move(int x, int y) override {
		BattleUnit::Move(x,y);
		cout << "攻城坦克<" << GetName() << ">收到移动命令" << "(" << position << endl;
	}
	void Move(Point& position) override {}
protected:

private:


};
/**********************************************
 *错误error:undefined reference to
 *错误原因：子类没有完全实现父类的纯虚函数
 *解决办法：在子类中完全实现父类的纯虚函数，不实现也加个{}
 *具体文件：真星际争霸demo中
 **********************************************/


//维京战机
class Viking :public BattleUnit {
public:
	Viking() {}
	Viking(const string& _name) :BattleUnit(_name) {}
	void Fight(BattleUnit& unit)override {};
	void Move(int x, int y) override {
		BattleUnit::Move(x, y);
		cout << "维京战机<" << GetName() << ">立即飞往" << "(" << position << endl;
	}
	void Move(Point& position) override {}
protected:

private:


};



//指挥官类---模拟的是游戏中的核心业务类
class Commander {
public:
	//一个指挥官移动了多个作战单位
	void Move(vector<BattleUnit*> units, int x, int y) {
		for (auto unit : units) {
			(*unit).Move(x, y);
		}
	}
protected:

private:

};
