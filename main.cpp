/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
// Задание:
// Сделать базовый класс стринга и дочерний класс стринга_идентификатор 
// (идентиф это строка из a-z, A-Z и '_').
// написать конструкторы - по умолчанию, символом, строкой, конструктор копирования в двух классах.
// В дочернем классе реализовать функции обработки строки:
// 1 - перевод всех букв в верхний регистр
// 2 - перевод всех букв в нижний регистр
// В дочернем классе реализовать перегрузки арифметических операций:
// + - склеивание второй строки к первой
// - - нахождение первого вхождения строки слева в строке справа и удаление её
// > - вернуть разницу между первой и второй строкой
// < - вернуть разницу между первой и второй строкой
// В задании перегрузки сравнения ничем не отличаются, очень странно. 
// Фактически, это один и тот же компаратор)
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


#include "classes.h"
int checking_string(my_string::String& obj, const char* usr, const char ch);

int main() {
	using namespace my_string;
	String* pps = StringIdentifier{"test"};
	int num_of_strings = 0;
	if (checking_string(*pps, "test", 'a')) {
		std::cerr << "Here some errors" << std::endl;
	}
	/*
	while (true) {
		int size_ = 10;
		char* usr_string = new char[size_];
		while (!(std::cin >> usr_string)) {
			std::cerr << std::endl << "Wrong string" << std::endl;
		}
		string_identifier obj{ usr_string };
		*(pps + num_of_strings) = &obj;
		if (checking_string(*(*pps + num_of_strings), usr_string, 'a')) {
			std::cerr << "Here some errors" << std::endl;
		}
		
		++num_of_strings;
	}
	*/
	// if (checking_string())
	return 0;
}

int checking_string(my_string::String& obj, const char* usr, const char ch) {
	using namespace std;
	using namespace my_string;
	int e_code = 0;
	cout << usr << endl;
	cout << obj << endl ;
	obj.iSetUppercase();
	cout << "Uppercase test: " << obj << endl;
	obj.iSetLowercase();
	cout << "Lowercase test: " << obj << endl;
	cout << "First char \'" << ch << " \' in string:" << 
		obj.iFindSymbol(ch) ? 
			print_string(obj.iFindSymbol(ch), obj.iGetLenght()) : 
			print_string("NULLPTR", 8) << endl;

	StringIdentifier* ptr;
	{
		StringIdentifier lr={};
		ptr = &lr;
		cout << "Empty constructor test: " <<
			(obj.iGetGtring() && obj.iGetLenght() ? "SUCCESS" : (e_code++, "FAIL")) << endl;
	}

	cout << "Destroyer test: " << (ptr ? "FAIL" : "SUCCESS") << endl;

	{
		char exmp[] = "this is\n STRING";
		StringIdentifier tmp(exmp);
		StringIdentifier& lr = tmp;
		cout << "String for init: " << "this is\n STRING";
		// Make string_compare func!!!
		cout << "String constructor test: " << 
			(comparator(lr.iGetGtring(), { "this is\n STRING" }) ? (e_code++, "FAIL") : "SUCCESS") << endl;
		// cout << "String constructor test: "  <<
		//	obj.iFindSymbol(ch) ? print_string(obj.iFindSymbol(ch), obj.iGetLenght()) :
	}

	{
		StringIdentifier tmp('t');
		StringIdentifier& lr = tmp;
		cout << "Char for init: " << 't';
		// Make string_compare func!!!
		cout << "Char constructor test: " <<
			(comparator(lr.iGetGtring(), { "t" }) ? "FAIL" : "SUCCESS") << endl;
	}

	{
		char exmp[] = "bebra_____BEBRA";
		StringIdentifier tmp2(exmp);
		StringIdentifier& lr2=tmp2;
		StringIdentifier&  lr1 { lr2 };
		cout << "String for init: " << "bebra_____BEBRA" << endl;
		cout << "Overload for \'=\' operation result: " << lr1 << endl;
		cout << "Overload for \'=\' operation test result: " <<
			(comparator(lr1.iGetGtring(), { "bebra_____BEBRA" }) ? 
				(e_code++, "FAIL") : "SUCCESS") << endl;
		lr1.iSetUppercase();
		cout << "Uppercase func result: " << 
			lr1 << endl;
		cout << "Uppercase func test: " << 
			(comparator(lr1.iGetGtring(), { "bebra_____bebra" }) ? 
				(e_code++, "FAIL") : "SUCCESS") << endl;
		lr2.iSetLowercase();
		cout << "Lowercase func result: " <<
			lr2 << endl;
		cout << "Lowercase func test: " <<
			(comparator(lr2.iGetGtring(), { "bebra_____bebra" }) ?
				(e_code++, "FAIL") : "SUCCESS") << endl;
	}

	{
		char str1[] = "bebra1___";
		char str2[] = "bebra2___";
		StringIdentifier tmp1(str1);
		StringIdentifier tmp2(str2);
		StringIdentifier& lr1=tmp1;
		StringIdentifier& lr2=tmp2;
		StringIdentifier& lr3 = lr1 + lr2;
		cout << "Overload for \'+\' operation result: " <<
			lr3 << endl;
		cout << "Overload for \'+\' operation test result: " <<
			(comparator(lr3.iGetGtring(), { "bebra1___bebra2___" }) ? (e_code++, "FAIL") : "SUCCESS") << endl;
		char str3[] = "bebra";
		lr3 = lr3 - StringIdentifier{str3};
		cout << "Overload for \'-\' operation result: " <<
			lr3 << endl;
		cout << "Overload for \'-\' operation test result: " <<
			(comparator(lr3.iGetGtring(), { "1___2___" }) ? (e_code++, "FAIL") : "SUCCESS") << endl;
		char num1[] = "22";
		char num2[] = "11";
		char num3[] = "00";
		//	char num4[]=
		cout << "Overload for \'>\' operation test result: " <<
			((lr3 > StringIdentifier{num1}) == '2' - '1' &&
				!(lr3 > StringIdentifier{num2}) ? "SUCCESS" : (e_code++, "FAIL")) << endl;
		cout << "Overload for \'<\' operation test result: " <<
			((lr3 < StringIdentifier{num3}) == '2' - '1' &&
				!(lr3 < StringIdentifier{num2}) ? "SUCCESS" : (e_code++, "FAIL")) << endl;
	}
	
	return e_code;

int checking_string(const my_string::StringIdentifier &obj, const char *usr);

int main() {
  using namespace my_string;
  String *pps[] = new *(String[2]);
  int num_of_strings = 0;

  while (true) {
    int size_ = 10;
    char *usr_string = new char[usr_string];
    while (!(std::cin > usr_string)) {
      std::cerr << std::endl << "Wrong string" << std::endl;
    }
    pps[num_of_strings] = new StringIdentifier;
    pps[num_of_strings] = {usr_string};
    ++num_of_strings;
  }
  return 0;
}

int checking_string(const my_string::StringIdentifier &obj, const char *usr,
                    const char ch) {
  using namespace std;
  using namespace my_string;
  cout << usr << endl;
  cout << obj << endl;
  cout << "Uppercase test: " << obj.iSetUppercase() << endl;
  cout << "Lowercase test: " << obj.iSetLowercase() << endl;
  cout << "First char \'" << ch << " \' in string:" << obj.iFindSymbol(ch)
      ? print_string(obj.iFindSymbol(ch), obj.iGetLenght())
      : "NULLPTR" << endl;

  StringIdentifier *ptr;
  {
    StringIdentifier &lr = {};
    ptr = &lr;
    cout << "Empty constructor test: " << obj.iGetGtring() && obj.iGetLenght()
        ? "SUCCESS"
        : "FAIL" << endl;
  }

  cout << "Destroyer test: " << ptr ? "FAIL" : "SUCCESS" << endl;

  {
    StringIdentifier &lr = {"this is\n STRING"};
    cout << "String for init: "
         << "this is\n STRING";
    // Make string_compare func!!!
    cout << "Overload of = test: " << ;
    cout << "String constructor test: " << obj.iFindSymbol(ch)
        ? print_string(obj.iFindSymbol(ch), obj.iGetLenght())
        :
  }

}