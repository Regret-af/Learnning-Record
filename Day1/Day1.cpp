#include <iostream>

// ������Ķ���
union example{
	int num1;
	short num2;
	double num3;
};

int main() {
	
	example test;

	// �����干��һ���ڴ棬�ڴ��С�������ĳ�Ա��������
	std::cout << sizeof(test) << std::endl;
	std::cout << &test.num1 << std::endl;
	std::cout << &test.num2 << std::endl;

	// ���ڹ���һ���ڴ棬���Ը�һ�����ݣ����п�����������Ҳ���ı�
	// �������ֽ�����
	test.num1 = 0;
	// num2 Ϊshort���ͣ���ֵΪ-1��Ͷ��ֽڸ�ȫ1����0xff ff
	test.num2 = -1;

	std::cout << test.num1 << std::endl;
	// �Ͷ��ֽ�Ϊȫ1������65535
	std::cout << test.num2 << std::endl;

	return 0;
}