#include "Array.h"

Array::Array(int length) : m_length(length)
{
	if (m_length == 0) {
		m_datas = NULL;
	}
	else
	{
		m_datas = new int[m_length];
	}
}

Array::Array(const Array & arr)
{
	if (arr.m_length == 0)	return;
	m_length = arr.m_length;
	m_datas = new int[m_length];
//1��ѭ�����Ԫ�ؿ���
//2��memcpy
	memcpy(m_datas, arr.m_datas, m_length * sizeof(int));

}

Array::~Array()
{
	delete[] m_datas;
}

//int Array::operator[](int index)
//{
//	if (m_length == 0) {
//		cerr << "����Ϊ�գ�����ʧ�ܣ�" << endl;
//	}
//	if (index < 0 || index >= m_length) {
//		cerr << "�����±�Խ�磡" << endl;
//	}
//	return m_datas[index];
//}
int & Array::operator[](int index)
{
	if (m_length == 0) {
		cerr << "����Ϊ�գ�����ʧ�ܣ�" << endl;
	}
	if (index < 0 || index >= m_length) {
		cerr << "�����±�Խ�磡" << endl;
	}
	return m_datas[index];
}

const Array & Array::operator=(const Array & arr)
{
	// TODO: �ڴ˴����� return ���
	if (this == &arr)	return *this;
	if (arr.m_length == 0)	return *this;
	m_length = arr.m_length;
	m_datas = new int[m_length];
	//1��ѭ�����Ԫ�ؿ���
	//2��memcpy
	memcpy(m_datas, arr.m_datas, m_length * sizeof(int));
	return *this;
}

ostream & operator<<(ostream & out, const Array &arr)
{
	// TODO: �ڴ˴����� return ���
	for (int i = 0; i < arr.m_length; i++) {
		out << arr.m_datas[i];
	}
	out <<endl;
	return out;
}
