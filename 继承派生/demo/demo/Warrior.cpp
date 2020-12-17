#include "Warrior.h"
#include "hero.h"
#include "Archmage.h"

Warrior::Warrior() : hero("默认战士", 1 ,100 ,100)
{
}

Warrior::Warrior(const string nickname, int phyattack) : hero(nickname, 1, 100, 100), m_PhysicalAttack(phyattack)
{
}

Warrior::~Warrior()
{
}

void Warrior::Move()
{
	//派生类中不能直接访问基类中的私有成员，可以将其改为受保护的(仅允许子类访问)
	cout << "战士英雄:" << "《" << GetNickName() << "》" << "正在背着武器奔跑" << endl;	//不可直接使用m_nickname进行访问，因为父类的nickname是私有的
}

void Warrior::HiSunZi()
{
	cout << "来打我呀！傻逼" << endl;
}

void Warrior::XiaoQuanQuan(hero & other)
{
	cout << "小拳拳捶你胸口！" << endl;
	cout << GetNickName() << "发出了一记流星锤!" << endl;
	if (other.GetCurrLife() > 10) {
		other.SetCurrLife(other.GetCurrLife() - 10);		//使对方掉10滴血	
		cout << other.GetNickName() << "受伤！！！血量减10" << endl;
	}
	else {
		other.SetCurrLife(0);							//血量少于10，直接死亡
		cout << other.GetNickName() << "死亡！！！" << endl;
	}

}

//void Warrior::XiaoQuanQuan(Warrior & other)
//{
//	cout << "小拳拳捶你胸口！" << endl;
//	cout << GetNickName() << "发出了一记流星锤!" << endl;
//	if (other.GetCurrLife() > 10) {
//		other.SetCurrLife(other.GetCurrLife() - 10);		//使对方掉10滴血	
//		cout << other.GetNickName() << "受伤！！！血量减10" << endl;
//	}
//	else {
//		other.SetCurrLife(0);							//血量少于10，直接死亡
//		cout << other.GetNickName() << "死亡！！！" << endl;
//	}
//}
//
//void Warrior::XiaoQuanQuan(Archmage & other)
//{
//	cout << "小拳拳捶你胸口！" << endl;
//	cout << GetNickName() << "为了攻击法师，冲上前去使出一招：野蛮冲撞！！" << endl;
//	if (other.GetCurrLife() > 20) {
//		other.SetCurrLife(other.GetCurrLife() - 20);		//使对方掉10滴血
//		cout << other.GetNickName() << "受重创！！！血量减20" << endl;
//	}
//	else {
//		other.SetCurrLife(0);							//血量少于10，直接死亡
//		cout << other.GetNickName() << "倒地死亡！！！" << endl;
//	}
//}
