#pragma once

#ifndef _MYSTRING
#define _MYSTRING

#include <iostream>
#include <assert.h>

class myString
{
private:
	char* str;	// 字符串的内容
	unsigned short len = 0;	// 字符串长度
	unsigned short mlen = 0;	//实际占用内存的长度

	// 复制函数
	void copyStr(const char* ch);

	// 获取字符串长度
	unsigned short getLenth(const char* ch) const;

public:

	// 无参构造函数
	myString();

	// 指定内存不指定内容的构造函数
	myString(int _mlen);

	// 指定内容的构造函数
	myString(const char* ch);

	// 拷贝构造函数
	myString(myString& ch);
	
	// 返回字符串长度的函数
	int size() const;

	// 返回字符串内存长度的函数
	int m_size() const;

	// 重设内存空间
	bool resetMlen(int len);

	// 重载 = 运算符
	myString& operator=(const myString& ch);

	// 重载 + 运算符
	myString operator+(const myString& ch);

	// 重载 += 运算符
	myString& operator+=(const myString& ch);

	// 重载 << 运算符
	myString& operator<<(myString& ch);

	// 重载 >> 运算符
	myString& operator>>(myString& ch);

	// 重载 [] 运算符
	char& operator[](int idx) const;

	// 析构函数
	~myString();

	// 友元函数
	// 重载 << 运算符 （输出版）
	friend std::ostream& operator<<(std::ostream& out, const myString& str);

	// 重载 >> 运算符 （输入版）
	friend std::istream& operator>>(std::istream& in, myString& str);

	// 重载 + 运算符
	friend myString operator+(const char* ch, myString& str);


	// 练习
	myString operator[](const char* ch);

};



#endif // !_MYSTRING