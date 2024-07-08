#pragma once
#include <iostream>

class tstring {
	char* str;	// 字符串的内容
	unsigned short len = 0;		// 字符串的长度
	unsigned short mlen = 0;	// 字符串的实际内存长度

	// 复制函数
	void copyStr(const char* ch);

public:

	// 无参构造函数
	tstring();

	// 自定义初始内存长度，但是不定义字符串内容的构造函数
	tstring(int mlen);

	// 利用字符常量初始化
	tstring(const char* ch);

	// 副本构造函数
	tstring(tstring& ch);

	// 重载 = 号，利用 C 字符串
	tstring& operator=(const tstring& ch);

	// 重载 + 号
	tstring& operator+(const tstring& ch);

	// 重载 << 号 (左移版)
	tstring& operator<<(const tstring& ch);

	// 重载 += 号
	tstring& operator+=(const tstring& ch);

	// 查看内容
	char* show () const { return this->str; }

	// 查看当前字符串长度
	int size() const { return this->len - 1; }

	// 重载 << 运算符
	friend std::ostream& operator<< (std::ostream& out, const tstring& str);
};