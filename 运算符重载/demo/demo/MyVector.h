#pragma once
#include <iostream>
#include <cstring>
using namespace std;

//�Զ����������
//ʹ����ģ�弼����ģ�弼��һ���������㷨����������100��ĳ�����͵��㷨  ���������
//int GetMax(int num1, int num2);
//double GetMax(double num1, double num2);
//string GetMax(string num1, string num2);

//ע�⣺���ʹ��ģ�弼������ô��������ͷ���ʵ�ֶ�Ҫ����һ��ͷ�ļ��У���������ļ�����cpp�ļ���   .hpp���������ö���һ���ļ���

//template <class T>	//�Զ����ģ�壬��Tָ���κ����� �������ƽ�T
template <typename T>	//��class��ͬ��
//T GetMax(T num1, T num2);  //���Զ����������
class MyVector
{
public:
	MyVector();
	MyVector(int len, T element);			//���len���ȵ�Ԫ��element
	MyVector(const MyVector<T> & vec);		//���ƹ���
	~MyVector();

	template<typename T2>
	friend ostream &operator<<(ostream & out, const MyVector<T2> &vec);		//

	MyVector<T> & operator=(const MyVector<T> & vec);
	T & operator[](int index);				//��ȡԪ��(����д��)
	void push_back(T element);				//��Ԫ��element���뵽�ڲ����������һ��

	//T pop_back();							//���ز�ɾ�����һ��Ԫ��
	//void insert(int pos, T element);		//��posλ�ò���Ԫ��element
	//void clear();							//�������Ԫ��
protected:

private:
	T * m_elements;			//�������Ԫ�ص�����
	int m_length;			//���з�Ԫ�ص�ʵ�ʸ���
	int m_capacity;			//��ǰԪ������Ĵ�С
};

template <typename T>		//�Ժ�ÿ������ǰ�涼Ҫ��
MyVector<T>::MyVector() :m_capacity(16), m_length(0)
{
	this->m_elements = new T[m_capacity];
}

template <typename T>
MyVector<T>::MyVector(int len, T element) :m_capacity(16)
{
	m_capacity = len + m_capacity;
	m_length = len;
	m_elements = new T[m_capacity];
	for (int i = 0; i < m_length; i++) {
		//1��ʹ��ѭ������
		//m_elements[i] = element;		//����ÿ�ζ���������صķ�ֵ�����=
		//2��ʹ��memcpy
		memcpy(&m_elements[i], &element, sizeof(T));
	}
}
template <typename T>
MyVector<T> & MyVector<T>::operator=(const MyVector<T> & vec)			//���ط�ֵ�����=
{
	if (this == &vec)	return *this;
	if (NULL != m_elements) {
		delete[] m_elements;
		m_elements = NULL;
	}
	m_capacity = vec.m_length + vec.m_capacity;
	m_length = vec.m_length;
	m_elements = new T[vec.m_capacity];
	memcpy(m_elements, vec.m_elements, m_length * sizeof(T));
	return *this;
}
template <typename T>
MyVector<T>::MyVector(const MyVector<T> & vec)							//���ƹ���
{
	m_capacity = vec.m_capacity;
	m_length = vec.m_length;
	m_elements = new T[m_capacity];
	memcpy(m_elements, vec.m_elements, m_length*sizeof(T));
}

template <typename T>
MyVector<T>::~MyVector() {
	delete[] m_elements;
}

template <typename T>
T & MyVector<T>::operator[](int index)
{
	return m_elements[index];
}

template <typename T>
void MyVector<T>::push_back(T element)
{
	//��element��ӵ��ڲ���������һ��λ��
	if (NULL == m_elements) {
		m_capacity = 16;
		m_length = 0;
		m_elements = new T[m_capacity];
	}
	//�жϵ�ǰ�����Ƿ�����
	if (m_length == m_capacity) {
		//��������������
		T* newElements = new T[m_capacity * 2 + 1];
		//��ԭ��Ԫ�ش浽�¿ռ���
		memcpy(newElements, m_elements, m_length*sizeof(T));
		delete m_elements;		//�ͷſռ�
		m_elements = newElements;	//��Ԫ������ָ���¿ռ䣻
	}
	//m_elements[m_length++] = element;
	memcpy(&m_elements[m_length++],&element,sizeof(T));
}


template<typename T2>
ostream &operator<<(ostream & out, const MyVector<T2> &vec)
{
	for (int i = 0; i < vec.m_length; i++) {
		out << vec.m_elements[i] << ",";
	}
	out <<endl;
	return out;
}