#include "MyString.h"
#include "MyString.h"

String::String() :m_length(0)		//长度默认值为0
{
	this->m_value = new char[m_length + 1];	//唯一的空间存放\0
	this->m_value[0] = '\0';
}

String::String(const char * str)
{
	//将传入的字符串str的值赋给当前中的m_value
	if (NULL == str)
	{
		this->m_value = new char[m_length + 1];	//唯一的空间存放\0
		this->m_value[0] = '\0';
		return;
	}
	m_length = strlen(str);				//获得要复制字符串的长度
	m_value = new char[m_length + 1];	//存在一个\0
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
	//析构时释放字符数组所指向的空间
	delete[] m_value;
}


//如果一个类拥有指针类型的成员，那么大部分情况下，都需要进行深复制---将原有对象复制一份出来
//让两者相互独立。没有指针时浅复制即可。
const String & String::operator=(const String & str)
{
	// TODO: 在此处插入 return 语句
	if (this == &str)	return *this;	//判断是不是自我幅值
	delete[] m_value;					//首先释放原始空间
	m_length = str.m_length;
	m_value = new char[m_length + 1];
	strcpy(m_value, str.m_value);
	return *this;
}

ostream & operator<<(ostream & out, const String & str)
{
	// TODO: 在此处插入 return 语句
	out << str.m_value<< '\n';
	out << "m_value的长度：" << strlen(str.m_value)<<'\n'; 
	out << "m_length的长度：" << str.m_length<< '\n';
/*	cout << "out输出";*/
	return out;
}
