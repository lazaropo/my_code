/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
// Задание:
// Сделать базовый класс стринга и дочерний класс стринга_идентификатор
// (идентиф это строка из a-z, A-Z и '_').
// написать конструкторы - по умолчанию, символом, строкой, конструктор
// копирования в двух классах. В дочернем классе реализовать функции обработки
// строки: 1 - перевод всех букв в верхний регистр 2 - перевод всех букв в
// нижний регистр В дочернем классе реализовать перегрузки арифметических
// операций:
// + - склеивание второй строки к первой
// - - нахождение первого вхождения строки слева в строке справа и удаление её
// > - вернуть разницу между первой и второй строкой
// < - вернуть разницу между первой и второй строкой
// В задании перегрузки сравнения ничем не отличаются, очень странно.
// Фактически, это один и тот же компаратор)
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

#include "classes.h"

int checking_string();

int main() {
  /*
  using namespace my_string;
  string* pps = string_identifier{"test"};
  int num_of_strings = 0;
  */
  if (checking_string()) {
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


int checking_string() {
    using namespace std;
    using namespace my_string;
    int e_code = 0;
    // string_identifier obj{};
    // cout << usr << endl;
    // cout << obj << endl;
    /*obj.i_set_uppercase();
    cout << "Uppercase test: " << obj << endl;
    obj.i_set_lowercase();
    cout << "Lowercase test: " << obj << endl;
    cout << "First char \'" << ch << " \' in string:" << obj.i_find_symbol(ch)
        ? print_string(obj.i_find_symbol(ch), obj.i_get_lenght())
        : print_string("NULLPTR", 8) << endl;*/

    my_string::string* ptr;
    my_string::string*& lp = ptr;
    {
        string_identifier tmp {};
        ptr = &tmp;
        cout << "Empty constructor test: "
            << (lp && !tmp.i_get_lenght() ? "SUCCESS"
                : (e_code++, "FAIL"))
            << endl;
    }

    cout << "Destroyer test: " << (lp ? (e_code++, "FAIL") : "SUCCESS") << endl;
    cout << lp << endl;

    //{
    //  char exmp[] = "this is\n STRING";
    //  string_identifier tmp(exmp);
    //  string_identifier& lr = tmp;
    //  cout << "String for init: "
    //       << "this is\n STRING";
    //  // Make string_compare func!!!
    //  cout << "String constructor test: "
    //       << (comparator(lr.i_get_string(), {"this is\n STRING"})
    //               ? (e_code++, "FAIL")
    //               : "SUCCESS")
    //       << endl;
    //  // cout << "string constructor test: "  <<
    //  //	obj.i_find_symbol(ch) ? print_string(obj.i_find_symbol(ch),
    //  // obj.i_get_lenght()) :
    //}

    //{
    //  string_identifier tmp('t');
    //  string_identifier& lr = tmp;
    //  cout << "Char for init: " << 't';
    //  // Make string_compare func!!!
    //  cout << "Char constructor test: "
    //       << (comparator(lr.i_get_string(), {"t"}) ? "FAIL" : "SUCCESS") << endl;
    //}

    //{
    //  char exmp[] = "bebra_____BEBRA";
    //  string_identifier tmp2(exmp);
    //  string_identifier& lr2 = tmp2;
    //  string_identifier& lr1{lr2};
    //  cout << "String for init: "
    //       << "bebra_____BEBRA" << endl;
    //  cout << "Overload for \'=\' operation result: " << lr1 << endl;
    //  cout << "Overload for \'=\' operation test result: "
    //       << (comparator(lr1.i_get_string(), {"bebra_____BEBRA"})
    //               ? (e_code++, "FAIL")
    //               : "SUCCESS")
    //       << endl;
    //  lr1.i_set_uppercase();
    //  cout << "Uppercase func result: " << lr1 << endl;
    //  cout << "Uppercase func test: "
    //       << (comparator(lr1.i_get_string(), {"bebra_____bebra"})
    //               ? (e_code++, "FAIL")
    //               : "SUCCESS")
    //       << endl;
    //  lr2.i_set_lowercase();
    //  cout << "Lowercase func result: " << lr2 << endl;
    //  cout << "Lowercase func test: "
    //       << (comparator(lr2.i_get_string(), {"bebra_____bebra"})
    //               ? (e_code++, "FAIL")
    //               : "SUCCESS")
    //       << endl;
    //}

    //{
    //  char str1[] = "bebra1___";
    //  char str2[] = "bebra2___";
    //  string_identifier tmp1(str1);
    //  string_identifier tmp2(str2);
    //  string_identifier& lr1 = tmp1;
    //  string_identifier& lr2 = tmp2;
    //  string_identifier& lr3 = lr1 + lr2;
    //  cout << "Overload for \'+\' operation result: " << lr3 << endl;
    //  cout << "Overload for \'+\' operation test result: "
    //       << (comparator(lr3.i_get_string(), {"bebra1___bebra2___"})
    //               ? (e_code++, "FAIL")
    //               : "SUCCESS")
    //       << endl;
    //  char str3[] = "bebra";
    //  lr3 = lr3 - string_identifier{str3};
    //  cout << "Overload for \'-\' operation result: " << lr3 << endl;
    //  cout << "Overload for \'-\' operation test result: "
    //       << (comparator(lr3.i_get_string(), {"1___2___"}) ? (e_code++, "FAIL")
    //                                                        : "SUCCESS")
    //       << endl;
    //  char num1[] = "22";
    //  char num2[] = "11";
    //  char num3[] = "00";
    //  //	char num4[]=
    //  cout << "Overload for \'>\' operation test result: "
    //       << ((lr3 > string_identifier{num1}) == '2' - '1' &&
    //                   !(lr3 > string_identifier{num2})
    //               ? "SUCCESS"
    //               : (e_code++, "FAIL"))
    //       << endl;
    //  cout << "Overload for \'<\' operation test result: "
    //       << ((lr3 < string_identifier{num3}) == '2' - '1' &&
    //                   !(lr3 < string_identifier{num2})
    //               ? "SUCCESS"
    //               : (e_code++, "FAIL"))
    //       << endl;
    //}

    return e_code;
}