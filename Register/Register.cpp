#include <iostream>
#include <string>

void Error() {
	std::cout << std::endl << "���ǿ��õ����������\"Register /?\"�鿴�����ĵ�" << std::endl;
	exit(0);
}

void Help() {
	std::cout << std::endl << "�÷���" << "Register id:[����id] pass:[��������] country:[���Ĺ���]"
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

			std::cout << std::endl << "ע��ɹ�" << std::endl << std::endl;
			std::cout << "id = " << id << std::endl;
			std::cout << "pass = " << pass << std::endl;
			std::cout << "country = " << country << std::endl;
		}
		else Error();
	}
	else Error();

	return 0;
}