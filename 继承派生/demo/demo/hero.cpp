#include "hero.h"

hero::hero() : hero("默认英雄", 1, 100, 100)
{
	//cout << "调用hero的默认构造" << endl;
}

hero::~hero()
{
}

hero::hero(const string & nickname) : hero(nickname, 1, 100, 100)
{
	//cout << "调用1个参数的默认构造" << endl;
}

hero::hero(const string & nickname, int level) : hero(nickname, level, 100, 100)		//调用自己/*******/
{
	//cout << "调用2个参数的默认构造" << endl;
}

hero::hero(const string & nickname, int level, int maxlife, int currlife) : m_NickName(nickname), m_Level(level), m_MaxLife(maxlife), m_CurrLife(currlife)
{
	//cout << "调用4个参数的默认构造" << endl;
}

void hero::Move()
{
	cout << "普通英雄：" << m_NickName << "正在奔跑" << endl;

}

ostream & operator<<(ostream & out, const hero & hero)
{
	// TODO: 在此处插入 return 语句
	out << "英雄名称:" << hero.GetNickName() << "\n";
	out << "等    级:" << hero.GetLevel() << "\n";
	out << "最大生命:" << hero.GetMaxLife() << "\n";
	out << "当前生命:" << hero.GetCurrLife();
	return out;
}
