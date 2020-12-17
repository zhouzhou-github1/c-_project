#include "Archmage.h"
#include "hero.h"
#include "Warrior.h"

Archmage::Archmage() : hero("默认法师", 1, 80, 80)
{
}

Archmage::~Archmage()
{
}

Archmage::Archmage(const string nikename, int magicalattack) : hero(nikename, 1, 80, 80), m_MagicalAttack(magicalattack)
{
}

void Archmage::Move()
{
	cout << "法师英雄:" << "《" << GetNickName() << "》" << "正在跳着舞奔跑" << endl;	//不可直接使用m_nickname进行访问，因为父类的nickname是私有的

}

void Archmage::BiuBiuBiu(Warrior & other)
{
	cout << "BiuBiuBiu！" << endl;
	cout << GetNickName() << "使用技能BiuBiuBiu!" << endl;
	if (other.GetCurrLife() > 30) {
		other.SetCurrLife(other.GetCurrLife() - 30);		//使对方掉20滴血	
		cout << other.GetNickName() << "受伤！！！血量减30" << endl;
	}
	else {
		other.SetCurrLife(0);							//血量少于10，直接死亡
		cout << other.GetNickName() << "死亡！！！" << endl;
	}
}

void Archmage::BiuBiuBiu(Archmage & other)
{
	cout << "BiuBiuBiu！" << endl;
	cout << GetNickName() << "使用技能BiuBiuBiu哦!" << endl;
	if (other.GetCurrLife() > 40) {
		other.SetCurrLife(other.GetCurrLife() - 40);		//使对方掉20滴血	
		cout << other.GetNickName() << "受重伤！！！血量减40" << endl;
	}
	else {
		other.SetCurrLife(0);							//血量少于10，直接死亡
		cout << other.GetNickName() << "死亡！！！" << endl;
	}
}
