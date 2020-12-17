#pragma once

//自己定义的类，将整形封装成类，以便实现面向对象的封装
class integer
{
public:
	integer();			//默认构造
	~ integer();
	integer(int);
	//重载加号运算符
	integer operator+(integer other);
	int IntValue() { return m_value; }
private:
	int m_value;		//menmber
};

