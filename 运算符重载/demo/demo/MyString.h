#pragma once
#include <iostream>


using namespace std;
//自定义的String类
class String
{
public:
	String();
	String(const char*);		//构造函数
	String(const String &);		//复制构造或者成为拷贝构造
	~String();
	//重置幅值运算符，将数组中的每个元素都进行复制，而不是只复制数组指针。如果包含多个对象，每个对象都需要进行复制---深复制
	const String & operator=(const String &str);
	friend ostream & operator<<(ostream & out, const String & str);	//友元函数方便打印
protected:

private:
	int m_length;
	char* m_value;
};

