/*************************************************
 *�ļ�����main.cpp
 *��  ����ʵ���Ǽ�����
 *��  �ߣ�����
 *ʱ  �䣺2020.12.16��16:20
 *************************************************/

#include <iostream>
#include <vector>
#include "AbstractClassDemo.h"
using namespace std;

void AbstractClassTest();
int main()
{
	cout << "haha" <<endl;
	AbstractClassTest();
	return 0;
}

void AbstractClassTest()
{
	//����ʵ����һ�����������
	//BattleUnit unit;
	Marine marine1("������");
	Marine marine2("������ʿ");
	marine1.Fight(marine2);

	siegeTank tank1("̹��1");
	tank1.Move(10, 20);

	Viking viking1("��ŷ����");
	vector<BattleUnit*> units;
	units.push_back(&marine1);			//ע���&  ��Ϊ�������ָ��
	units.push_back(&marine2);
	units.push_back(&tank1);
	units.push_back(&viking1);
	cout << "-----------------------------------" << endl;
	Commander commander;
	cout << "��ָ�ӹ��ƶ�������͵�ս����λ" << endl;
	commander.Move(units, 30, 40);

}