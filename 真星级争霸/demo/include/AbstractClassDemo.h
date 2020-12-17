#pragma once
/*************************************************
 *�ļ�����AbstractClassDemo.h
 *��  ����ʵ��һ���򵥰��Ǽ�������Ϸ�������̬�ͳ��������
 *��  �ߣ�����
 *ʱ  �䣺2020.12.16��16:20
 *************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Point {				//�Զ���������λ
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
class BattleUnit			//ս����λ��---������
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

	//����ĳ������Ϊ���麯����BattleUnit�ͱ�ɳ�����---ֻ�ܱ��̳У��޷�ʵ����
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
	Point position;			//��ǰ����������
	int attDistance;		//��ǰ����Ĺ�������
private:

};
//�����ṩ������ി�麯����Ĭ��ʵ��
void BattleUnit::Fight(BattleUnit& unit) {
	/*����������ÿ����λ��սǰ����������������߼�ࡣ�����೬���������룬�򹥻�ʧ��*/
	cout << name << "���ڹ�����һ��ս����λ" << unit.GetName() << endl;
}
void BattleUnit::Move(int x, int y) {				//��Ϊ�ƶ�������ڸ�����ʵ��
	position.SetX(x);
	position.SetY(y);
}


//���ࣺ½ս��Ա    ����ʵ�ָ������������д��麯���������������Ҳ���ɳ�����
class Marine :public BattleUnit {
public:
	Marine() {}
	Marine(const string& _name):BattleUnit(_name) {}

	void Fight(BattleUnit& unit)override;
	void Move(int x, int y) override {
		BattleUnit::Move(x, y);
		cout << "½ս��Ա<" << GetName() << ">�յ��ƶ�����" << "(" << position << endl;
	}
	void Move(Point& position) override {}
protected:

private:


};

void Marine::Fight(BattleUnit& unit) {
	//�����е��ø����ͬ������
	BattleUnit::Fight(unit);
	cout << "½ս��Ա" << GetName() << "���ڹ������ˣ�" << unit.GetName() << endl;
}



//����̹��
class siegeTank :public BattleUnit {
public:
	siegeTank() {}
	siegeTank(const string& _name):BattleUnit(_name){}
	void Fight(BattleUnit& unit)override {};
	void Move(int x, int y) override {
		BattleUnit::Move(x,y);
		cout << "����̹��<" << GetName() << ">�յ��ƶ�����" << "(" << position << endl;
	}
	void Move(Point& position) override {}
protected:

private:


};
/**********************************************
 *����error:undefined reference to
 *����ԭ������û����ȫʵ�ָ���Ĵ��麯��
 *����취������������ȫʵ�ָ���Ĵ��麯������ʵ��Ҳ�Ӹ�{}
 *�����ļ������Ǽ�����demo��
 **********************************************/


//ά��ս��
class Viking :public BattleUnit {
public:
	Viking() {}
	Viking(const string& _name) :BattleUnit(_name) {}
	void Fight(BattleUnit& unit)override {};
	void Move(int x, int y) override {
		BattleUnit::Move(x, y);
		cout << "ά��ս��<" << GetName() << ">��������" << "(" << position << endl;
	}
	void Move(Point& position) override {}
protected:

private:


};



//ָ�ӹ���---ģ�������Ϸ�еĺ���ҵ����
class Commander {
public:
	//һ��ָ�ӹ��ƶ��˶����ս��λ
	void Move(vector<BattleUnit*> units, int x, int y) {
		for (auto unit : units) {
			(*unit).Move(x, y);
		}
	}
protected:

private:

};
