#include <iostream>

// 联合体的定义
union example{
	int num1;
	short num2;
	double num3;
};

int main() {
	
	example test;

	// 联合体共用一块内存，内存大小由其最大的成员变量决定
	std::cout << sizeof(test) << std::endl;
	std::cout << &test.num1 << std::endl;
	std::cout << &test.num2 << std::endl;

	// 由于共用一块内存，所以改一个数据，就有可能其他数据也被改变
	// 将低四字节清零
	test.num1 = 0;
	// num2 为short类型，赋值为-1则低二字节赋全1，即0xff ff
	test.num2 = -1;

	std::cout << test.num1 << std::endl;
	// 低二字节为全1，代表65535
	std::cout << test.num2 << std::endl;

	return 0;
}