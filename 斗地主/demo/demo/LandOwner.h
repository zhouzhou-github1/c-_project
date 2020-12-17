#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <iterator>			//迭代器的头文件
#include <algorithm>		//copy函数的头文件
#include <cstdlib>
#include <algorithm>
#include <time.h>


using namespace std;

class LandOwner
{
private:
	string name;						/*玩家名称*/
	int score;							/*玩家分数*/
	double exp;							/*玩家经验*/
	vector<int> AllCards;				/*所有的牌面*/
	vector<int> SurplusCards;			/*抽取后剩余的牌面*/
	vector<int> MyCards;				/*玩家抽到的牌面*/
	bool isContains(int);				/*判断剩余牌中是否包含这张牌*/
	void deleteCard(vector<int>&,int);	/*在剩余牌中删除这张牌*/
	string getColor(int);				/*获得花色*/
	string getNum(int);					/*获得牌面*/

public:
	LandOwner(string);					/*有参构造*/
	LandOwner(string,int,double);		/** 构造函数*/
	~LandOwner();						/*析构函数*/
	void InitCards();					/*初始化所有的牌面*/
	void showCards(const vector<int>&);		/*显示牌面,5中遍历方法 重点：迭代器和copy*/
	void TouchCards(int);					/*摸牌*/
	void SetScore(int);					/*设置分数*/
	void SetName(string);				/*设置名字*/
	void SetExp(double expChange);		/*设置经验*/
	void show();						/*显示玩家信息*/
};

