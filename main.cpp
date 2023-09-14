#include "classes.h"

int checking_string(my_string::string& obj, const char* usr, const char ch);

int main() {
	using namespace my_string;
	string** pps = new string*[2];
	int num_of_strings = 0;

	while (true) {
		int size_ = 10;
		char* usr_string = new char[size_];
		while (!(std::cin >> usr_string)) {
			std::cerr << std::endl << "Wrong string" << std::endl;
		}
		string_identifier obj{ usr_string };
		*(pps + num_of_strings) = &obj;
		checking_string(*(*pps + num_of_strings), usr_string, 'a');
		
		++num_of_strings;
	}
	// checking_string()
	return 0;
}

int checking_string(my_string::string& obj, const char* usr, const char ch) {
	using namespace std;
	using namespace my_string;
	cout << usr << endl;
	cout << obj << endl ;
	obj.uppercase();
	cout << "Uppercase test: " << obj << endl;
	obj.lowercase();
	cout << "Lowercase test: " << obj << endl;
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
		cout << "String constructor test: " << 
		 	comparator(lr.get_string(), { "this is\n STRING" })? "FAIL":"SUCCESS" << endl;
		// cout << "String constructor test: "  <<
		//	obj.find_symbol(ch) ? print_string(obj.find_symbol(ch), obj.get_lenght()) :
	}

	{
		string_identifier& lr = { 't' };
		cout << "Char for init: " << 't';
		// Make string_compare func!!!
		cout << "Char constructor test: " <<
			comparator(lr.get_string(), { 't' }) ? "FAIL" : "SUCCESS" << endl;
	}

	{
		string_identifier& lr2{ "bebra_____BEBRA" };
		string_identifier&  lr1 { lr2 };
		cout << "String for init: " << "bebra_____BEBRA" << endl;
		cout << "Overload for \'=\' operation result: " << lr1 << endl;
		cout << "Overload for \'=\' operation test result: " <<
			comparator(lr1.get_string(), { "bebra_____BEBRA" }) ? "FAIL" : "SUCCESS" << endl;
		lr1.uppercase();
		cout << "Uppercase func result: " << 
			print_string(lr1.get_string(), l1.get_lenght()) << endl;
		cout << "Uppercase func test: " << 
			comparator(lr1.get_string(), { "bebra_____bebra" }) ? "FAIL" : "SUCCESS" << endl;
		lr2.lowercase();
		cout << "Lowercase func result: " <<
			print_string(lr2.get_string(), l1.get_lenght()) << endl;
		cout << "Lowercase func test: " <<
			comparator(lr2.get_string(), { "bebra_____bebra" }) ? "FAIL" : "SUCCESS" << endl;
	}

	{
		string_identifier& lr1{ "bebra1___" };
		string_identifier& lr2{ "bebra2___" };
		string_identifier& lr3 = lr1 + lr2;
		cout << "Overload for \'+\' operation result: " <<
			lr3 << endl;
		cout << "Overload for \'+\' operation test result: " <<
			comparator(lr3.get_string(), { "bebra1___bebra2___" }) ? "FAIL" : "SUCCESS" << endl;
		lr3 = lr3 - string_identifier{"bebra"};
		cout << "Overload for \'-\' operation result: " <<
			lr3 << endl;
		cout << "Overload for \'-\' operation test result: " <<
			comparator(lr3.get_string(), { "1___2___" }) ? "FAIL" : "SUCCESS" << endl;
		cout << "Overload for \'>\' operation test result: " <<
			(lr3 > string_identifier{"22"} == '2' - '1') &&
			!(lr3 > string_identifier{"11"}) ? "SUCCESS" : "FAIL" << endl;
		cout << "Overload for \'<\' operation test result: " <<
			(lr3 < string_identifier{"00"} == '2' - '1') &&
			!(lr3 < string_identifier{"11"}) ? "SUCCESS" : "FAIL" << endl; ? "SUCCESS" : "FAIL" << endl;
	}
	

}