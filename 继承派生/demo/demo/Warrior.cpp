#include "Warrior.h"
#include "hero.h"
#include "Archmage.h"

Warrior::Warrior() : hero("Ĭ��սʿ", 1 ,100 ,100)
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
	//�������в���ֱ�ӷ��ʻ����е�˽�г�Ա�����Խ����Ϊ�ܱ�����(�������������)
	cout << "սʿӢ��:" << "��" << GetNickName() << "��" << "���ڱ�����������" << endl;	//����ֱ��ʹ��m_nickname���з��ʣ���Ϊ�����nickname��˽�е�
}

void Warrior::HiSunZi()
{
	cout << "������ѽ��ɵ��" << endl;
}

void Warrior::XiaoQuanQuan(hero & other)
{
	cout << "Сȭȭ�����ؿڣ�" << endl;
	cout << GetNickName() << "������һ�����Ǵ�!" << endl;
	if (other.GetCurrLife() > 10) {
		other.SetCurrLife(other.GetCurrLife() - 10);		//ʹ�Է���10��Ѫ	
		cout << other.GetNickName() << "���ˣ�����Ѫ����10" << endl;
	}
	else {
		other.SetCurrLife(0);							//Ѫ������10��ֱ������
		cout << other.GetNickName() << "����������" << endl;
	}

}

//void Warrior::XiaoQuanQuan(Warrior & other)
//{
//	cout << "Сȭȭ�����ؿڣ�" << endl;
//	cout << GetNickName() << "������һ�����Ǵ�!" << endl;
//	if (other.GetCurrLife() > 10) {
//		other.SetCurrLife(other.GetCurrLife() - 10);		//ʹ�Է���10��Ѫ	
//		cout << other.GetNickName() << "���ˣ�����Ѫ����10" << endl;
//	}
//	else {
//		other.SetCurrLife(0);							//Ѫ������10��ֱ������
//		cout << other.GetNickName() << "����������" << endl;
//	}
//}
//
//void Warrior::XiaoQuanQuan(Archmage & other)
//{
//	cout << "Сȭȭ�����ؿڣ�" << endl;
//	cout << GetNickName() << "Ϊ�˹�����ʦ������ǰȥʹ��һ�У�Ұ����ײ����" << endl;
//	if (other.GetCurrLife() > 20) {
//		other.SetCurrLife(other.GetCurrLife() - 20);		//ʹ�Է���10��Ѫ
//		cout << other.GetNickName() << "���ش�������Ѫ����20" << endl;
//	}
//	else {
//		other.SetCurrLife(0);							//Ѫ������10��ֱ������
//		cout << other.GetNickName() << "��������������" << endl;
//	}
//}
