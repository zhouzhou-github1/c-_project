#pragma once

//�Լ�������࣬�����η�װ���࣬�Ա�ʵ���������ķ�װ
class integer
{
public:
	integer();			//Ĭ�Ϲ���
	~ integer();
	integer(int);
	//���ؼӺ������
	integer operator+(integer other);
	int IntValue() { return m_value; }
private:
	int m_value;		//menmber
};

