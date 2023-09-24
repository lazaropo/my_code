/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
// �������:
// ������� ������� ����� ������� � �������� ����� �������_�������������
// (������� ��� ������ �� a-z, A-Z � '_').
// �������� ������������ - �� ���������, ��������, �������, �����������
// ����������� � ���� �������. � �������� ������ ����������� ������� ���������
// ������: 1 - ������� ���� ���� � ������� ������� 2 - ������� ���� ���� �
// ������ ������� � �������� ������ ����������� ���������� ��������������
// ��������:
// + - ���������� ������ ������ � ������
// - - ���������� ������� ��������� ������ ����� � ������ ������ � �������� �
// > - ������� ������� ����� ������ � ������ �������
// < - ������� ������� ����� ������ � ������ �������
// � ������� ���������� ��������� ����� �� ����������, ����� �������.
// ����������, ��� ���� � ��� �� ����������)
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

#include "classes.h"
int checking_string(my_string::string& obj, const char* usr, const char ch);

int main() {
  using namespace my_string;
  string* pps = string_identifier{"test"};
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

int checking_string(my_string::string& obj, const char* usr, const char ch) {
  using namespace std;
  using namespace my_string;
  int e_code = 0;
  cout << usr << endl;
  cout << obj << endl;
  obj.i_set_uppercase();
  cout << "Uppercase test: " << obj << endl;
  obj.i_set_lowercase();
  cout << "Lowercase test: " << obj << endl;
  cout << "First char \'" << ch << " \' in string:" << obj.i_find_symbol(ch)
      ? print_string(obj.i_find_symbol(ch), obj.i_get_lenght())
      : print_string("NULLPTR", 8) << endl;

  string_identifier* ptr;
  {
    string_identifier lr = {};
    ptr = &lr;
    cout << "Empty constructor test: "
         << (obj.i_get_string() && obj.i_get_lenght() ? "SUCCESS"
                                                      : (e_code++, "FAIL"))
         << endl;
  }

  cout << "Destroyer test: " << (ptr ? "FAIL" : "SUCCESS") << endl;

  {
    char exmp[] = "this is\n STRING";
    string_identifier tmp(exmp);
    string_identifier& lr = tmp;
    cout << "String for init: "
         << "this is\n STRING";
    // Make string_compare func!!!
    cout << "String constructor test: "
         << (comparator(lr.i_get_string(), {"this is\n STRING"})
                 ? (e_code++, "FAIL")
                 : "SUCCESS")
         << endl;
    // cout << "string constructor test: "  <<
    //	obj.i_find_symbol(ch) ? print_string(obj.i_find_symbol(ch),
    // obj.i_get_lenght()) :
  }

  {
    string_identifier tmp('t');
    string_identifier& lr = tmp;
    cout << "Char for init: " << 't';
    // Make string_compare func!!!
    cout << "Char constructor test: "
         << (comparator(lr.i_get_string(), {"t"}) ? "FAIL" : "SUCCESS") << endl;
  }

  {
    char exmp[] = "bebra_____BEBRA";
    string_identifier tmp2(exmp);
    string_identifier& lr2 = tmp2;
    string_identifier& lr1{lr2};
    cout << "String for init: "
         << "bebra_____BEBRA" << endl;
    cout << "Overload for \'=\' operation result: " << lr1 << endl;
    cout << "Overload for \'=\' operation test result: "
         << (comparator(lr1.i_get_string(), {"bebra_____BEBRA"})
                 ? (e_code++, "FAIL")
                 : "SUCCESS")
         << endl;
    lr1.i_set_uppercase();
    cout << "Uppercase func result: " << lr1 << endl;
    cout << "Uppercase func test: "
         << (comparator(lr1.i_get_string(), {"bebra_____bebra"})
                 ? (e_code++, "FAIL")
                 : "SUCCESS")
         << endl;
    lr2.i_set_lowercase();
    cout << "Lowercase func result: " << lr2 << endl;
    cout << "Lowercase func test: "
         << (comparator(lr2.i_get_string(), {"bebra_____bebra"})
                 ? (e_code++, "FAIL")
                 : "SUCCESS")
         << endl;
  }

  {
    char str1[] = "bebra1___";
    char str2[] = "bebra2___";
    string_identifier tmp1(str1);
    string_identifier tmp2(str2);
    string_identifier& lr1 = tmp1;
    string_identifier& lr2 = tmp2;
    string_identifier& lr3 = lr1 + lr2;
    cout << "Overload for \'+\' operation result: " << lr3 << endl;
    cout << "Overload for \'+\' operation test result: "
         << (comparator(lr3.i_get_string(), {"bebra1___bebra2___"})
                 ? (e_code++, "FAIL")
                 : "SUCCESS")
         << endl;
    char str3[] = "bebra";
    lr3 = lr3 - string_identifier{str3};
    cout << "Overload for \'-\' operation result: " << lr3 << endl;
    cout << "Overload for \'-\' operation test result: "
         << (comparator(lr3.i_get_string(), {"1___2___"}) ? (e_code++, "FAIL")
                                                          : "SUCCESS")
         << endl;
    char num1[] = "22";
    char num2[] = "11";
    char num3[] = "00";
    //	char num4[]=
    cout << "Overload for \'>\' operation test result: "
         << ((lr3 > string_identifier{num1}) == '2' - '1' &&
                     !(lr3 > string_identifier{num2})
                 ? "SUCCESS"
                 : (e_code++, "FAIL"))
         << endl;
    cout << "Overload for \'<\' operation test result: "
         << ((lr3 < string_identifier{num3}) == '2' - '1' &&
                     !(lr3 < string_identifier{num2})
                 ? "SUCCESS"
                 : (e_code++, "FAIL"))
         << endl;
  }

  return e_code;

  int checking_string(const my_string::string_identifier& obj, const char* usr);

  int main() {
    using namespace my_string;
    string* pps[] = new*(string[2]);
    int num_of_strings = 0;

    while (true) {
      int size_ = 10;
      char* usr_string = new char[usr_string];
      while (!(std::cin > usr_string)) {
        std::cerr << std::endl << "Wrong string" << std::endl;
      }
      pps[num_of_strings] = new StringIdentifier;
      pps[num_of_strings] = {usr_string};
      ++num_of_strings;
    }
    return 0;
  }

  int checking_string(const my_string::StringIdentifier& obj, const char* usr,
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

    StringIdentifier* ptr;
    {
      StringIdentifier& lr = {};
      ptr = &lr;
      cout << "Empty constructor test: " << obj.iGetGtring() && obj.iGetLenght()
          ? "SUCCESS"
          : "FAIL" << endl;
    }

    cout << "Destroyer test: " << ptr ? "FAIL" : "SUCCESS" << endl;

    {
      StringIdentifier& lr = {"this is\n STRING"};
      cout << "String for init: "
           << "this is\n STRING";
      // Make string_compare func!!!
      cout << "Overload of = test: " << ;
      cout << "String constructor test: " << obj.i_find_symbol(ch)
          ? print_string(obj.i_find_symbol(ch), obj.i_get_lenght())
          :
    }
  }