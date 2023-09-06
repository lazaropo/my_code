#include "classes.h"

int checking_string(const my_string::string_identifier& obj, const char*usr);

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

int checking_string(const my_string::string_identifier& obj, const char* usr, const char ch) {
	using namespace std;
	using namespace my_string;
	cout << usr << endl;
	cout << obj << endl ;
	cout << "Uppercase test: " << obj.uppercase()<< endl;
	cout << "Lowercase test: " << obj.lowercase() << endl;
	cout << "First char \'" << ch << " \' in string:" << 
		obj.find_symbol(ch) ? print_string(obj.find_symbol(ch), obj.get_lenght()) : "NULLPTR" << endl;

	string_identifier* ptr;
	{
		string_identifier& lr = {};
		ptr = &lr;
		cout << "Empty constructor test: " <<
			obj.get_string() && obj.get_lenght() ? "SUCCESS" : "FAIL" << endl;
	}

	cout << "Destroyer test: " << ptr ? "FAIL" : "SUCCESS" << endl;

	{
		string_identifier& lr = {"this is\n STRING"};
		cout << "String for init: " << "this is\n STRING";
		// Make string_compare func!!!
		cout << "Overload of = test: " << ;
		cout << "String constructor test: "  <<
			obj.find_symbol(ch) ? print_string(obj.find_symbol(ch), obj.get_lenght()) :
	}
	

}