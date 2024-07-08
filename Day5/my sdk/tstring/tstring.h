#pragma once
#include <iostream>

class tstring {
	char* str;	// �ַ���������
	unsigned short len = 0;		// �ַ����ĳ���
	unsigned short mlen = 0;	// �ַ�����ʵ���ڴ泤��

	// ���ƺ���
	void copyStr(const char* ch);

public:

	// �޲ι��캯��
	tstring();

	// �Զ����ʼ�ڴ泤�ȣ����ǲ������ַ������ݵĹ��캯��
	tstring(int mlen);

	// �����ַ�������ʼ��
	tstring(const char* ch);

	// �������캯��
	tstring(tstring& ch);

	// ���� = �ţ����� C �ַ���
	tstring& operator=(const tstring& ch);

	// ���� + ��
	tstring& operator+(const tstring& ch);

	// ���� << �� (���ư�)
	tstring& operator<<(const tstring& ch);

	// ���� += ��
	tstring& operator+=(const tstring& ch);

	// �鿴����
	char* show () const { return this->str; }

	// �鿴��ǰ�ַ�������
	int size() const { return this->len - 1; }

	// ���� << �����
	friend std::ostream& operator<< (std::ostream& out, const tstring& str);
};