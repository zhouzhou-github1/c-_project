#pragma once
#include <iostream>


using namespace std;
//�Զ����String��
class String
{
public:
	String();
	String(const char*);		//���캯��
	String(const String &);		//���ƹ�����߳�Ϊ��������
	~String();
	//���÷�ֵ��������������е�ÿ��Ԫ�ض����и��ƣ�������ֻ��������ָ�롣��������������ÿ��������Ҫ���и���---���
	const String & operator=(const String &str);
	friend ostream & operator<<(ostream & out, const String & str);	//��Ԫ���������ӡ
protected:

private:
	int m_length;
	char* m_value;
};

