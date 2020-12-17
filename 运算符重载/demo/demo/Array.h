#pragma once

#include <iostream>
#include <cstring>
using namespace std;
class Array
{
public:
	Array(int length = 0);
	Array(const Array & arr);		//��������
	~Array();

//	int operator[](int index);		//ֻ����  ��ȡԪ��(�޷�д��)
	int & operator[](int index);	//��Ϊ���ص������ã������ǿ����޸ĵ�
	const Array & operator= (const Array &);
	friend ostream & operator<< (ostream & out, const Array & arr);

protected:

private:
	int m_length;
	int* m_datas;
};


