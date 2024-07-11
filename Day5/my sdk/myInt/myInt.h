#pragma once

#ifndef MYINT
#define MYINT

#include <iostream>

class myInt
{
private:
	char* mint;

	// 将数据从 myInt 读出
	void read(int& val);

	// 将数据写入 myInt 中
	void write(const int& val);

public:
	// 构造函数
	myInt(int val = 0);

	// 拷贝构造函数
	myInt(myInt& val);

	// 析构函数
	~myInt();

	// 重载 = 赋值运算符
	myInt& operator=(const int& val);

	myInt& operator=(const myInt& val);

	// 重载 int 类型转换运算符
	operator int();

	// 重载 ++ 自增运算符
	myInt& operator++();

	const myInt operator++(int);

	// 重载 -- 自减运算符
	myInt& operator--();

	const myInt operator--(int);

	// 重载 += 运算符
	myInt& operator+=(int val);

	// 重载 -= 运算符
	myInt& operator-=(int val);

	// 重载 *= 运算符
	myInt& operator*=(int val);

	// 重载 /= 运算符
	myInt& operator/=(int val);

	// 友元函数
	// 重载 >> 右移运算符
	friend std::istream& operator>>(std::istream& in, myInt& val);
};

#endif // !MYINT