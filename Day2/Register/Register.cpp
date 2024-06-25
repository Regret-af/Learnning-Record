#include <iostream>
#include <string>

void Error() {
	std::cout << std::endl << "不是可用的命令，可输入\"Register /?\"查看帮助文档" << std::endl;
	exit(0);
}

void Help() {
	std::cout << std::endl << "用法：" << "Register id:[您的id] pass:[您的密码] country:[您的国家]"
		<< std::endl;

	exit(0);
}

int main(const int argcount, char* c_arg[]) {
	std::string id;
	std::string pass;
	std::string country;

	if (argcount > 4) {
		Error();
	}

	std::string strs[4];

	for (int i = 0; i < argcount; i++) {
		strs[i] = c_arg[i];
	}

	if (argcount == 2 and strs[1] == "/?") {
		Help();
	}

	if (argcount == 4) {
		std::string str1 = strs[1].substr(0, 3);
		std::string str2 = strs[2].substr(0, 5);
		std::string str3 = strs[3].substr(0, 8);

		if (str1 == "id:" and str2 == "pass:" and str3 == "country:") {
			id = strs[1].substr(3);
			pass = strs[2].substr(5);
			country = strs[3].substr(8);

			std::cout << std::endl << "注册成功" << std::endl << std::endl;
			std::cout << "id = " << id << std::endl;
			std::cout << "pass = " << pass << std::endl;
			std::cout << "country = " << country << std::endl;
		}
		else Error();
	}
	else Error();

	return 0;
}
