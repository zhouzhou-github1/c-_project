#include <iostream>
#include <LandOwner.h>

using namespace std;
int main()
{
	LandOwner* LandOwner1 = new LandOwner{ "杰克",159,154};
	LandOwner* LandOwner2 = new LandOwner{ "杰克马",999,15400 };
	LandOwner* LandOwner3 = new LandOwner{ "小鱼儿"};

	LandOwner1->SetExp(999);
	LandOwner1->SetName("老九");
	LandOwner1->SetScore(159);
//这样摸牌还是不对，摸的只是自己类中的牌。导致1、2摸牌一样了
	LandOwner1->show();
	LandOwner1->TouchCards(20);			//摸20张牌
	LandOwner2->show();
	LandOwner2->TouchCards(20);			//摸20张牌
	LandOwner3->show();

	delete LandOwner1;					//释放
	delete LandOwner2;
	delete LandOwner3;
	return 0;
}