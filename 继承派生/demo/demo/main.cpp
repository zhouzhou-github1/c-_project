/*************************************************
 *�ļ�����main.cpp
 *��  ����C++�̳�������ѧϰ
 *��  �ߣ�����
 *ʱ  �䣺2020.12.05:20.06
 *************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "hero.h"		//ʹ��<>�򲻿�hero.h
#include "Warrior.h"
#include "Archmage.h"
#include "Teacher.h"
#include "GameCore.h"
#include "Assassin.h"

using namespace std;


void HeroTest();
void WarriorTest();
void AttackTest();
void TeacherTest();
void GameCoreTest();

int main()
{
	cout << "--------------------ȫ  ��  ��  ��--------------------" << endl;
//	HeroTest();
//	WarriorTest();
//	AttackTest();
//	TeacherTest();
	GameCoreTest();
	return 0;
}

void HeroTest()
{
	hero hero1;
	cout << hero1 << endl;
	hero1.Move();
	cout << endl;
	hero *hero2 = new hero("����Ӣ��2", 999, 5000, 5000);
	cout << *hero2 << endl;
	hero2->Move();			//�ȼ۷�ʽ   (*hero2).Move();

	delete hero2;
}

void WarriorTest()
{
	//�������������ʱ�����ȵ��û��๹�죬�ٵ��������๹��
	//����ʱ���ȵ����������������ٵ��û�������
	Warrior warrior1;
	//�������
	//���1:�����಻ʵ��Move������Ĭ�ϵ��û���ʵ��
	//���2:������ʵ��Move��������ô�ͻ����������ʵ��
	warrior1.Move();			//�������������ʵ��Move������Ĭ�ϵ��û���hero�е�Move����

	hero *hero3 = new Warrior();		//����ָ��ָ��������---��׼�Ķ�̬
	hero3->Move();						//���õ��ǻ���ʵ��   ****��Ҫ��������ʵ��---�麯��***
	delete hero3;

	Warrior warrior2("�����", 11);
	hero& refHero = warrior2;			//���ʹ�û�������ָ�������������ô�������þͲ��ܵ����������ж���ķ���
	hero* ptrHero = &warrior2;			//���ʹ�û���ָ��ָ�������������ô�������þͲ��ܵ����������ж���ķ���
	//���ǽ���ǿ��ת��
//	Warrior& warrior3 = refHero;	ֱ������ת����
	Warrior& warrior3 = (Warrior &)refHero;		//��������ǿתΪ�������û�ָ��
}

void AttackTest()
{
	Warrior warrior2("�ܲ�", 50);
	Warrior warrior3("����", 60);
	cout << "--------------------���ɵ�һ��Ӣ��--------------------" << endl;
	cout << warrior2 << endl;
	cout << "--------------------���ɵڶ���Ӣ��--------------------" << endl;
	cout << warrior3 << endl;
	cout << "--------------------��  ʼ  ��  ս--------------------" << endl;
	warrior2.XiaoQuanQuan(warrior3);
	cout << "--------------------���ɵ�����Ӣ��--------------------" << endl;
//	Archmage  *archmage1 = new Archmage("����", 55);	
//	����ʱ(*archmage1).BiuBiuBiu(warrior3);    archamage1->BiuBiuBiu(warrior3);�����Ǵ���ģ��޷������� 1 �ӡ�Archmage *��ת��Ϊ��Warrior &��
	Archmage archmage1("����", 55);
	cout << "--------------------��  ��  ��  ��--------------------" << endl;
	(archmage1).BiuBiuBiu(warrior3);			
	warrior3.XiaoQuanQuan(archmage1);
	cout << "С����������!!!����һ�ˡ�" << endl;
	warrior2.XiaoQuanQuan(warrior3);
	(archmage1).BiuBiuBiu(warrior3);
	(archmage1).BiuBiuBiu(warrior3);
	cout << "--------------------ս  ��  ��  ��--------------------" << endl;
	cout << "--------------------�ܲٵ�ǰ״̬��--------------------" << endl;
	cout << warrior2 << endl;
	cout << "--------------------������ǰ״̬��--------------------" << endl;
	cout << warrior3 << endl;
	cout << "--------------------������ǰ״̬��--------------------" << endl;
	cout << archmage1 << endl;

	Archmage * archmage2 = new Archmage("С��", 66);
	(*archmage2).BiuBiuBiu(archmage1);
//	archmage2->BiuBiuBiu(archmage2);
	warrior2.XiaoQuanQuan(*archmage2);
	(*archmage2).BiuBiuBiu(archmage1);
}
/**********************************************
 *����error:C2061:�﷨����
 *����ԭ������A�а�����B������B���ְ�����A
 *����취����A.h�ļ�������B��(class B;),��A.cpp�ļ���include "B.h";
 *			��B.h�ļ�������A��(class A;),��B.cpp�ļ���include "A.h";
 *ʹ��Ŀ�ģ����������ĵ��ã�����̿͹�����ʦ�ȵ�
 **********************************************/


void TeacherTest()
{
	Teacher teacher1(8000);
}

void GameCoreTest()
{
	hero hero1("����Ӣ��");
	Warrior warrior1("����", 55);
	Archmage archmage1("����", 80);
	//hero1.Move();				//ʵ����һ�㲻�������ã����ǰ�Move��װ��һ����
	//warrior1.Move();
	//archmage1.Move();


	GameCore gameCore;				//������ƶ���
/*��GameCore.h��һͬ

	//һ���򵥵Ķ�̬		��̬�Ķ�̬���ŵ㣺�����ٶȿ죬����Ч�ʸߡ�ȱ�������
	gameCore.MoveRole(warrior1);
	gameCore.MoveRole(archmage1);
	gameCore.MoveRole(hero1);

	cout << "--------------------��  ̬  ��  ̬--------------------" << endl;
	Warrior warrior11("����", 55);
	Warrior warrior12("�ĺ", 55);
	Warrior warrior13("��ҧ��", 55);
	Warrior warrior14("��", 55);
	Warrior warrior15("�޵�쫷��", 55);
	vector<Warrior*> vecWarrior;
	vecWarrior.push_back(&warrior11);
	vecWarrior.push_back(&warrior12);
	vecWarrior.push_back(&warrior13);
	vecWarrior.push_back(&warrior14);
	vecWarrior.push_back(&warrior15);
	//��Ҫ�۲죺������Ϸҵ�񷽷���ͳһ��������Ķ��սʿ

	gameCore.MoveRole(vecWarrior);

*/

	//cout << "--------------------����ʹ��virtual--------------------" << endl;
	gameCore.MoveRole(hero1);
	gameCore.MoveRole(warrior1);			//��������в����virtual�ؼ���
	gameCore.MoveRole(archmage1);			//�������ͻ���ݵ�ǰ��������͵��û����ж����Move����

	Assassin assa("�����߱ں���", 50);
	gameCore.MoveRole(assa);

	warrior1.XiaoQuanQuan(archmage1);
	warrior1.XiaoQuanQuan(assa);

	cout << "--------------------��������ת��--------------------" << endl;
	Archmage warrior10;
	hero & hero10 = warrior10;
	Warrior & newWarrior10 = (Warrior&)warrior10;		//��ִ�У����ǲ���ȫ�����÷�ʦ���սʿ
	newWarrior10.XiaoQuanQuan(assa);
}

