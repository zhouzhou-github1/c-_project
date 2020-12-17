#include "LandOwner.h"

bool LandOwner::isContains(int cardNum)
{
	//ʹ��forѭ�������жϣ��ͼ�   ��ʱû�в���
/*	for (int i = 0; i < SurplusCards.size(); i++) {
		if (SurplusCards[i] == cardNum)
			return true;
	}
	return false;*/

	//ʹ���㷨�����������ж�    ע�������˫ð��******** ����һ��������
	vector<int>::iterator iter = find(SurplusCards.begin(),SurplusCards.end(),cardNum);
	//�����ж�
/*	if (iter == SurplusCards.end()) {
		return false;			//�������һ���ˣ�֤��û���ҵ�����Ϊfalse
	}
	return true;*/
	//ţ�Ƶ���ж�
	//�����ҵ�ʱ��iter������end����ʱ��ʽΪ�棬����true(�����ҵ�)��     ��iter����endʱ����ʽΪ�٣�����false(��û�鵽)
	return iter != SurplusCards.end();		
}

void LandOwner::deleteCard(vector<int>& cards, int card)
{
	//��ʹ��auto����ɾ��
/*	for (auto iter = cards.begin(); iter != cards.end(); ++iter) {
		if (*iter == card) {			//����ҵ���ɾ��
			iter = cards.erase(iter);	//ע�������erase(pos)   pos��һ����ַ������һ�����ݡ�  ���ҷ���ֵָ����ɾ��Ԫ�ص���һԪ��
		}
	}*/

	//��ʹ���㷨����ɾ��
	auto iter = find(cards.begin(),cards.end(),card);
	if (iter != cards.end()) {
		cards.erase(iter);
//		cout << "ɾ��";
	}
}

string LandOwner::getColor(int card)			/*��ɫ���ǳ�13�����*/
{
	if (card == 54)	return "����";		//54����
	if (card == 53)	return "С��";			//53С��
	string colors[] = {"����","÷��","��Ƭ","����"};
	return colors[(card - 1) / 13];				//-1��Ϊ 0-12����0����������������
}

string LandOwner::getNum(int card)			/*������ǳ�13��������*/
{
	if (card == 54)	return "Black Joker";		//54����
	if (card == 53)	return "Red Joker";			//53С��
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
	//ʹ�õ��������г�ʼ��
	for (int i = 0; i < 54; i++) {
		AllCards.push_back(i + 1);
		SurplusCards.push_back(i + 1);				//�������Ǵ�1��ʼ��
	}
	MyCards.clear();
	//cout << "��ʼ������" << endl;
}
void LandOwner::showCards(const vector<int>& cards)
{
	//��ʹ�õ�����    ע���ַ��end()  һ��������������
/*	for (vector<int>::const_iterator iter = cards.begin(); iter != cards.end(); ++iter) {
		cout << *iter << ",";
	}
	cout << endl;*/

	//��C��forѭ������ȷִ�С�  ��סsizeҪ������ size()
	//cout << "չʾ" << endl;
	for (int i = 0; i < cards.size(); i++) {
		cout << cards[i] << ":" << getColor(cards[i]) << "(" << getNum(cards[i]) << ")" << ",";
	}
	cout << endl;

	//��ʹ���㷨copy   copy(vector��ͷ��������vector��β�����������Ƶ�cout��������ö��Ÿ���);
	//ע������ͷ�ļ�     #include <iterator>//��������ͷ�ļ�    #include <algorithm>//copy������ͷ�ļ�
/*	copy(cards.cbegin(), cards.cend(),ostream_iterator<int>(cout,","));	
	cout << endl;*/

	//��c++ 11�е������ƶ�   auto�ؼ���
	//�Զ��������
/*	for (auto iter = cards.begin(); iter != cards.end(); ++iter) {
		cout << *iter << ",";
	}
	cout << endl;*/

	//��forѭ���������  auto�ؼ��ֵ���һ���÷�  ʹ��cardȥ����cards�����е�ֵ�����
/*	for (auto card : cards) {
		cout << card << ":" << getColor(card) << "(" << getNum(card) << ")" << ",";
	}
	cout << endl;*/
}
void LandOwner::TouchCards(int cardCount)		
{
	//Ŀ�ģ��������һ��ʣ�������е��ģ����뵽��ҵ����У���ɾ��ʣ�����е�����  cardCountΪ������
	srand(time(NULL));			//���ʱ������   ��Ҫtime.hͷ�ļ�
	/*��Ϊʹ��rand()ÿ�β��������������ͬ����Ҫ��srand()����ʼ����������������srand(time_t(NULL));�ķ���������ͬ����������ӣ���Ϊÿ�γ�������ʱ�䲻ͬ*/
	for (int i = 0; i < cardCount; i++) {
		int randIndex = rand() % 54;	//��54������������0-53֮���������Ϊ�±�
		//�ж�����ƻ��ڲ���ʣ�����У��������������ɡ�
		if (isContains(AllCards[randIndex])) {
			MyCards.push_back(AllCards[randIndex]);			//�������ƾͼ��뵽��ҵ�����
			//��ʣ������ɾ��������
			deleteCard(SurplusCards,AllCards[randIndex]);
		}
		else {
			i--;		//���½������ƣ�i--��i++����
		}
	}

	cout << "<��������>- ��ǰ��������" << endl;
	showCards(MyCards);
	cout << "<�������ƺ�>- ʣ����������" << endl;
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
	//cout << "������" << score << endl;
}

void LandOwner::SetName(string nameChange)
{
	name = nameChange;
}

void LandOwner::show()
{
	cout << "���ƣ�" << name << "\n"
		<< "������" << score << "\n"
		<< "���飺" << exp << endl;
/*	showCards(AllCards);*/
}

void LandOwner::SetExp(double expChange)
{
	exp = expChange;
}


