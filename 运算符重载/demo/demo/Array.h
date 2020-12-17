#pragma once

#include <iostream>
#include <cstring>
using namespace std;
class Array
{
public:
	Array(int length = 0);
	Array(const Array & arr);		//拷贝构造
	~Array();

//	int operator[](int index);		//只读的  获取元素(无法写入)
	int & operator[](int index);	//因为返回的是引用，所以是可以修改的
	const Array & operator= (const Array &);
	friend ostream & operator<< (ostream & out, const Array & arr);

protected:

private:
	int m_length;
	int* m_datas;
};


