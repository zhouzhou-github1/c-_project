#include "hero.h"

hero::hero() : hero("Ĭ��Ӣ��", 1, 100, 100)
{
	//cout << "����hero��Ĭ�Ϲ���" << endl;
}

hero::~hero()
{
}

hero::hero(const string & nickname) : hero(nickname, 1, 100, 100)
{
	//cout << "����1��������Ĭ�Ϲ���" << endl;
}

hero::hero(const string & nickname, int level) : hero(nickname, level, 100, 100)		//�����Լ�/*******/
{
	//cout << "����2��������Ĭ�Ϲ���" << endl;
}

hero::hero(const string & nickname, int level, int maxlife, int currlife) : m_NickName(nickname), m_Level(level), m_MaxLife(maxlife), m_CurrLife(currlife)
{
	//cout << "����4��������Ĭ�Ϲ���" << endl;
}

void hero::Move()
{
	cout << "��ͨӢ�ۣ�" << m_NickName << "���ڱ���" << endl;

}

ostream & operator<<(ostream & out, const hero & hero)
{
	// TODO: �ڴ˴����� return ���
	out << "Ӣ������:" << hero.GetNickName() << "\n";
	out << "��    ��:" << hero.GetLevel() << "\n";
	out << "�������:" << hero.GetMaxLife() << "\n";
	out << "��ǰ����:" << hero.GetCurrLife();
	return out;
}
