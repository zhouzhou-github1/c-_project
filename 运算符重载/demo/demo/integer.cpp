#include "integer.h"

integer::integer() : m_value(0)			//Ĭ�Ϲ��죬m_valueĬ�Ϸ�ֵ0
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
	integer result(this->m_value + m_value);		//�������صĽ������

	return result;
}
