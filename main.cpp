#include "classes.h"

int main() {
	using namespace my_string;
	string* pps[] = new * (string[2]);
	int num_of_strings = 0;

	while (true) {
		int size_ = 10;
		char* usr_string = new char[usr_string];
		while (!(std::cin > usr_string)) {
			std::cerr << std::endl << "Wrong string" << std::endl;
		}
		pps[num_of_strings] = new string_identifier;
		pps[num_of_strings] = { usr_string };
		++num_of_strings;
	}
	return 0;
}