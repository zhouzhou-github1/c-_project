#include <iostream>
#include <LandOwner.h>

using namespace std;
int main()
{
	LandOwner* LandOwner1 = new LandOwner{ "�ܿ�",159,154};
	LandOwner* LandOwner2 = new LandOwner{ "�ܿ���",999,15400 };
	LandOwner* LandOwner3 = new LandOwner{ "С���"};

	LandOwner1->SetExp(999);
	LandOwner1->SetName("�Ͼ�");
	LandOwner1->SetScore(159);
//�������ƻ��ǲ��ԣ�����ֻ���Լ����е��ơ�����1��2����һ����
	LandOwner1->show();
	LandOwner1->TouchCards(20);			//��20����
	LandOwner2->show();
	LandOwner2->TouchCards(20);			//��20����
	LandOwner3->show();

	delete LandOwner1;					//�ͷ�
	delete LandOwner2;
	delete LandOwner3;
	return 0;
}