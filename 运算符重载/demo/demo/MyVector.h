#pragma once
#include <iostream>
#include <cstring>
using namespace std;

//自定义的容器类
//使用了模板技术：模板技术一般用来做算法，比如重载100次某个类型的算法  例如下面的
//int GetMax(int num1, int num2);
//double GetMax(double num1, double num2);
//string GetMax(string num1, string num2);

//注意：如果使用模板技术，那么类的声明和方法实现都要放在一个头文件中，所以这个文件不用cpp文件。   .hpp是声明调用都在一个文件里

//template <class T>	//自定义的模板，用T指代任何类型 类型名称叫T
template <typename T>	//与class相同，
//T GetMax(T num1, T num2);  //会自动调用上面的
class MyVector
{
public:
	MyVector();
	MyVector(int len, T element);			//填充len长度的元素element
	MyVector(const MyVector<T> & vec);		//复制构造
	~MyVector();

	template<typename T2>
	friend ostream &operator<<(ostream & out, const MyVector<T2> &vec);		//

	MyVector<T> & operator=(const MyVector<T> & vec);
	T & operator[](int index);				//获取元素(可以写入)
	void push_back(T element);				//将元素element放入到内部数组中最后一个

	//T pop_back();							//返回并删除最后一个元素
	//void insert(int pos, T element);		//在pos位置插入元素element
	//void clear();							//清除所有元素
protected:

private:
	T * m_elements;			//用来存放元素的数组
	int m_length;			//所有放元素的实际个数
	int m_capacity;			//当前元素数组的大小
};

template <typename T>		//以后每个函数前面都要加
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
		//1、使用循环复制
		//m_elements[i] = element;		//这里每次都会调用重载的幅值运算符=
		//2、使用memcpy
		memcpy(&m_elements[i], &element, sizeof(T));
	}
}
template <typename T>
MyVector<T> & MyVector<T>::operator=(const MyVector<T> & vec)			//重载幅值运算符=
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
MyVector<T>::MyVector(const MyVector<T> & vec)							//复制构造
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
	//将element添加到内部数组的最后一个位置
	if (NULL == m_elements) {
		m_capacity = 16;
		m_length = 0;
		m_elements = new T[m_capacity];
	}
	//判断当前数组是否已满
	if (m_length == m_capacity) {
		//已满，进行扩容
		T* newElements = new T[m_capacity * 2 + 1];
		//把原来元素存到新空间中
		memcpy(newElements, m_elements, m_length*sizeof(T));
		delete m_elements;		//释放空间
		m_elements = newElements;	//将元素数组指向新空间；
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