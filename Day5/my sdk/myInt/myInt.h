#pragma once

#ifndef MYINT
#define MYINT

#include <iostream>

class myInt
{
private:
	char* mint;

	// �����ݴ� myInt ����
	void read(int& val);

	// ������д�� myInt ��
	void write(const int& val);

public:
	// ���캯��
	myInt(int val = 0);

	// �������캯��
	myInt(myInt& val);

	// ��������
	~myInt();

	// ���� = ��ֵ�����
	myInt& operator=(const int& val);

	myInt& operator=(const myInt& val);

	// ���� int ����ת�������
	operator int();

	// ���� ++ ���������
	myInt& operator++();

	const myInt operator++(int);

	// ���� -- �Լ������
	myInt& operator--();

	const myInt operator--(int);

	// ���� += �����
	myInt& operator+=(int val);

	// ���� -= �����
	myInt& operator-=(int val);

	// ���� *= �����
	myInt& operator*=(int val);

	// ���� /= �����
	myInt& operator/=(int val);

	// ��Ԫ����
	// ���� >> ���������
	friend std::istream& operator>>(std::istream& in, myInt& val);
};

#endif // !MYINT