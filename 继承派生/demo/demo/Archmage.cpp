#include "Archmage.h"
#include "hero.h"
#include "Warrior.h"

Archmage::Archmage() : hero("Ĭ�Ϸ�ʦ", 1, 80, 80)
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
	cout << "��ʦӢ��:" << "��" << GetNickName() << "��" << "���������豼��" << endl;	//����ֱ��ʹ��m_nickname���з��ʣ���Ϊ�����nickname��˽�е�

}

void Archmage::BiuBiuBiu(Warrior & other)
{
	cout << "BiuBiuBiu��" << endl;
	cout << GetNickName() << "ʹ�ü���BiuBiuBiu!" << endl;
	if (other.GetCurrLife() > 30) {
		other.SetCurrLife(other.GetCurrLife() - 30);		//ʹ�Է���20��Ѫ	
		cout << other.GetNickName() << "���ˣ�����Ѫ����30" << endl;
	}
	else {
		other.SetCurrLife(0);							//Ѫ������10��ֱ������
		cout << other.GetNickName() << "����������" << endl;
	}
}

void Archmage::BiuBiuBiu(Archmage & other)
{
	cout << "BiuBiuBiu��" << endl;
	cout << GetNickName() << "ʹ�ü���BiuBiuBiuŶ!" << endl;
	if (other.GetCurrLife() > 40) {
		other.SetCurrLife(other.GetCurrLife() - 40);		//ʹ�Է���20��Ѫ	
		cout << other.GetNickName() << "�����ˣ�����Ѫ����40" << endl;
	}
	else {
		other.SetCurrLife(0);							//Ѫ������10��ֱ������
		cout << other.GetNickName() << "����������" << endl;
	}
}
