#pragma once

#ifndef _MYSTRING
#define _MYSTRING

#include <iostream>
#include <assert.h>

class myString
{
private:
	char* str;	// �ַ���������
	unsigned short len = 0;	// �ַ�������
	unsigned short mlen = 0;	//ʵ��ռ���ڴ�ĳ���

	// ���ƺ���
	void copyStr(const char* ch);

	// ��ȡ�ַ�������
	unsigned short getLenth(const char* ch) const;

public:

	// �޲ι��캯��
	myString();

	// ָ���ڴ治ָ�����ݵĹ��캯��
	myString(int _mlen);

	// ָ�����ݵĹ��캯��
	myString(const char* ch);

	// �������캯��
	myString(myString& ch);
	
	// �����ַ������ȵĺ���
	int size() const;

	// �����ַ����ڴ泤�ȵĺ���
	int m_size() const;

	// �����ڴ�ռ�
	bool resetMlen(int len);

	// ���� = �����
	myString& operator=(const myString& ch);

	// ���� + �����
	myString operator+(const myString& ch);

	// ���� += �����
	myString& operator+=(const myString& ch);

	// ���� << �����
	myString& operator<<(myString& ch);

	// ���� >> �����
	myString& operator>>(myString& ch);

	// ���� [] �����
	char& operator[](int idx) const;

	// ��������
	~myString();

	// ��Ԫ����
	// ���� << ����� ������棩
	friend std::ostream& operator<<(std::ostream& out, const myString& str);

	// ���� >> ����� ������棩
	friend std::istream& operator>>(std::istream& in, myString& str);

	// ���� + �����
	friend myString operator+(const char* ch, myString& str);


	// ��ϰ
	myString operator[](const char* ch);

};



#endif // !_MYSTRING