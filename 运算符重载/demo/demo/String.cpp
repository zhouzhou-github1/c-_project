#include "MyString.h"
#include "MyString.h"

String::String() :m_length(0)		//����Ĭ��ֵΪ0
{
	this->m_value = new char[m_length + 1];	//Ψһ�Ŀռ���\0
	this->m_value[0] = '\0';
}

String::String(const char * str)
{
	//��������ַ���str��ֵ������ǰ�е�m_value
	if (NULL == str)
	{
		this->m_value = new char[m_length + 1];	//Ψһ�Ŀռ���\0
		this->m_value[0] = '\0';
		return;
	}
	m_length = strlen(str);				//���Ҫ�����ַ����ĳ���
	m_value = new char[m_length + 1];	//����һ��\0
	strcpy(m_value,str);
}

String::String(const String & str)
{
	m_length = strlen(str.m_value);
	m_value = new char[m_length + 1];
	strcpy(m_value, str.m_value);
}

String::~String()
{
	//����ʱ�ͷ��ַ�������ָ��Ŀռ�
	delete[] m_value;
}


//���һ����ӵ��ָ�����͵ĳ�Ա����ô�󲿷�����£�����Ҫ�������---��ԭ�ж�����һ�ݳ���
//�������໥������û��ָ��ʱǳ���Ƽ��ɡ�
const String & String::operator=(const String & str)
{
	// TODO: �ڴ˴����� return ���
	if (this == &str)	return *this;	//�ж��ǲ������ҷ�ֵ
	delete[] m_value;					//�����ͷ�ԭʼ�ռ�
	m_length = str.m_length;
	m_value = new char[m_length + 1];
	strcpy(m_value, str.m_value);
	return *this;
}

ostream & operator<<(ostream & out, const String & str)
{
	// TODO: �ڴ˴����� return ���
	out << str.m_value<< '\n';
	out << "m_value�ĳ��ȣ�" << strlen(str.m_value)<<'\n'; 
	out << "m_length�ĳ��ȣ�" << str.m_length<< '\n';
/*	cout << "out���";*/
	return out;
}
