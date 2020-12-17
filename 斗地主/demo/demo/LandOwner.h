#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <iterator>			//��������ͷ�ļ�
#include <algorithm>		//copy������ͷ�ļ�
#include <cstdlib>
#include <algorithm>
#include <time.h>


using namespace std;

class LandOwner
{
private:
	string name;						/*�������*/
	int score;							/*��ҷ���*/
	double exp;							/*��Ҿ���*/
	vector<int> AllCards;				/*���е�����*/
	vector<int> SurplusCards;			/*��ȡ��ʣ�������*/
	vector<int> MyCards;				/*��ҳ鵽������*/
	bool isContains(int);				/*�ж�ʣ�������Ƿ����������*/
	void deleteCard(vector<int>&,int);	/*��ʣ������ɾ��������*/
	string getColor(int);				/*��û�ɫ*/
	string getNum(int);					/*�������*/

public:
	LandOwner(string);					/*�вι���*/
	LandOwner(string,int,double);		/** ���캯��*/
	~LandOwner();						/*��������*/
	void InitCards();					/*��ʼ�����е�����*/
	void showCards(const vector<int>&);		/*��ʾ����,5�б������� �ص㣺��������copy*/
	void TouchCards(int);					/*����*/
	void SetScore(int);					/*���÷���*/
	void SetName(string);				/*��������*/
	void SetExp(double expChange);		/*���þ���*/
	void show();						/*��ʾ�����Ϣ*/
};

