#include "LandOwner.h"

bool LandOwner::isContains(int cardNum)
{
	//使用for循环进行判断，低级   暂时没有测试
/*	for (int i = 0; i < SurplusCards.size(); i++) {
		if (SurplusCards[i] == cardNum)
			return true;
	}
	return false;*/

	//使用算法迭代器进行判断    注意这块有双冒号******** 定义一个迭代器
	vector<int>::iterator iter = find(SurplusCards.begin(),SurplusCards.end(),cardNum);
	//正常判断
/*	if (iter == SurplusCards.end()) {
		return false;			//等于最后一个了，证明没有找到，即为false
	}
	return true;*/
	//牛逼点的判断
	//当查找到时，iter不等于end，此时下式为真，返回true(即查找到)。     当iter等于end时，下式为假，返回false(即没查到)
	return iter != SurplusCards.end();		
}

void LandOwner::deleteCard(vector<int>& cards, int card)
{
	//①使用auto进行删除
/*	for (auto iter = cards.begin(); iter != cards.end(); ++iter) {
		if (*iter == card) {			//如果找到就删除
			iter = cards.erase(iter);	//注意这里的erase(pos)   pos是一个地址，不是一个数据。  并且返回值指向已删除元素的下一元素
		}
	}*/

	//②使用算法进行删除
	auto iter = find(cards.begin(),cards.end(),card);
	if (iter != cards.end()) {
		cards.erase(iter);
//		cout << "删除";
	}
}

string LandOwner::getColor(int card)			/*花色就是除13后的商*/
{
	if (card == 54)	return "大王";		//54大王
	if (card == 53)	return "小王";			//53小王
	string colors[] = {"黑桃","梅花","方片","桃心"};
	return colors[(card - 1) / 13];				//-1因为 0-12商是0，传进来的是牌面
}

string LandOwner::getNum(int card)			/*牌面就是除13都的余数*/
{
	if (card == 54)	return "Black Joker";		//54大王
	if (card == 53)	return "Red Joker";			//53小王
	string Num[] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K"};
	return Num[(card - 1) % 13];
}

LandOwner::LandOwner(string nameC)
{
	SetName(nameC);
	SetExp(11);
	SetScore(12);
	cout << "xixi" << endl;
	InitCards();
//	showCards(AllCards);
//	showCards(SurplusCards);
}
LandOwner::LandOwner(string nameC,int scoreC,double expC)
{
	SetName(nameC);
	SetExp(expC);
	SetScore(scoreC);
	InitCards();
//	showCards(AllCards);
}


LandOwner::~LandOwner()
{
	/*delete */
}

void LandOwner::InitCards()
{
//	AllCards.clear();
//	SurplusCards.clear();
	//使用迭代器进行初始化
	for (int i = 0; i < 54; i++) {
		AllCards.push_back(i + 1);
		SurplusCards.push_back(i + 1);				//两个都是从1开始的
	}
	MyCards.clear();
	//cout << "初始化结束" << endl;
}
void LandOwner::showCards(const vector<int>& cards)
{
	//①使用迭代器    注意地址和end()  一定不能忘记括号
/*	for (vector<int>::const_iterator iter = cards.begin(); iter != cards.end(); ++iter) {
		cout << *iter << ",";
	}
	cout << endl;*/

	//②C中for循环，正确执行。  记住size要加括号 size()
	//cout << "展示" << endl;
	for (int i = 0; i < cards.size(); i++) {
		cout << cards[i] << ":" << getColor(cards[i]) << "(" << getNum(cards[i]) << ")" << ",";
	}
	cout << endl;

	//③使用算法copy   copy(vector的头迭代器，vector的尾迭代器，复制到cout中输出并用逗号隔开);
	//注意两个头文件     #include <iterator>//迭代器的头文件    #include <algorithm>//copy函数的头文件
/*	copy(cards.cbegin(), cards.cend(),ostream_iterator<int>(cout,","));	
	cout << endl;*/

	//④c++ 11中的类型推断   auto关键字
	//自动检测类型
/*	for (auto iter = cards.begin(); iter != cards.end(); ++iter) {
		cout << *iter << ",";
	}
	cout << endl;*/

	//⑤for循环区间遍历  auto关键字的另一种用法  使用card去捕获cards容器中的值并输出
/*	for (auto card : cards) {
		cout << card << ":" << getColor(card) << "(" << getNum(card) << ")" << ",";
	}
	cout << endl;*/
}
void LandOwner::TouchCards(int cardCount)		
{
	//目的：随机生成一张剩余牌中有的拍，加入到玩家的牌中，并删除剩余牌中的这张  cardCount为摸牌数
	srand(time(NULL));			//随机时间种子   需要time.h头文件
	/*因为使用rand()每次产生的随机数都相同，需要用srand()来初始化它，即可以利用srand(time_t(NULL));的方法产生不同的随机数种子，因为每次程序运行时间不同*/
	for (int i = 0; i < cardCount; i++) {
		int randIndex = rand() % 54;	//除54的余数，生成0-53之间的数，作为下标
		//判断这个牌还在不在剩余牌中，若不在重新生成。
		if (isContains(AllCards[randIndex])) {
			MyCards.push_back(AllCards[randIndex]);			//有这张牌就加入到玩家的牌中
			//在剩余牌中删除这张牌
			deleteCard(SurplusCards,AllCards[randIndex]);
		}
		else {
			i--;		//重新进行摸牌，i--与i++抵消
		}
	}

	cout << "<地主摸牌>- 当前手牌如下" << endl;
	showCards(MyCards);
	cout << "<地主摸牌后>- 剩余手牌如下" << endl;
	showCards(SurplusCards);
}
void LandOwner::SetScore(int scoreChange)
{
	if (scoreChange > 999)
		score = 999;
	else if (scoreChange < -999) {
		score = -999;
	}
	else
		score = scoreChange;
	//cout << "分数：" << score << endl;
}

void LandOwner::SetName(string nameChange)
{
	name = nameChange;
}

void LandOwner::show()
{
	cout << "名称：" << name << "\n"
		<< "分数：" << score << "\n"
		<< "经验：" << exp << endl;
/*	showCards(AllCards);*/
}

void LandOwner::SetExp(double expChange)
{
	exp = expChange;
}


