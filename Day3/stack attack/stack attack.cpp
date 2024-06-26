#include <iostream>
#include <iomanip>

void Hack()
{
	unsigned long long x = 0;
	for (int i = 0; true; i++)
	{
		if (i % 100000000 == 0)
		{
			system("cls");
			std::cout << "\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
			std::cout << "\n 你的系统已经被我们拿下! hacked by 黑袍档案局:[ID:000001 ]\n";
			std::cout << "\n              加群:868267304 解除\n";
			std::cout << "\n\\>正在传输硬盘数据....已经传输" << x++ << "个文件......\n\n";

			std::cout << std::setfill('>')<< std::setw(x % 60) << "\n";

			std::cout << "\n\\>摄像头已启动!<==============\n\n";

			std::cout << std::setfill('#') << std::setw(x % 60) << "\n";

			std::cout << "\n\\>数据传输完成后将启动自毁程序!CPU将会温度提升到200摄氏度\n";

			std::cout << "\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
		}
	}
}

int GetAge()
{
	int rt;
	std::cout << "请输入学员的年龄:";
	std::cin >> rt;
	return rt;
}

int count()
{
	int i{};

	int total{};
	int age[10]{};
	do
	{
		age[i] = GetAge();
		total += age[i];
		//将AGE[I]保存到数据库中
	} while (age[i++]);
	return total;
}

int main()
{
	std::cout << "======= 学员总年龄统计计算系统 =====\n";
	std::cout << "\n                API:"<<Hack<<std::endl;
	std::cout << "\n[说明:最多输入10个学员的信息,当输入0时代表输入结束]\n\n";
	std::cout << "\n学院的学员总年龄为:" << count();
}

