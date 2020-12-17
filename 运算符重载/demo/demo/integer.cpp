#include "integer.h"

integer::integer() : m_value(0)			//默认构造，m_value默认幅值0
{
}

integer::~integer()
{
}

integer::integer(int value)
{
	m_value = value;
}

integer integer::operator+(integer other)
{
	integer result(this->m_value + m_value);		//用来返回的结果对象

	return result;
}
