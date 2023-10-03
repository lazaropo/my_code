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
void expand_char_array_size(char*& p, int l, int& l_max_old, double coeff = 1.7);
void expand_string_array_size(my_string::string**& pp, int l, int& l_max_old,
                              double coeff = 1.7);

int main() {
  using namespace my_string;
  // START - PART WITH USERS INPUT
  int l_pps = 0, l_max_pps = 1;
  string** pps = new string*[l_max_pps];
    int l_input = 0, l_max_input = 32;
    char c;
    char *p_input=new char[32];
    while(std::cin >> std::noskipws >> c){
      if(c=='\n'){
        string_identifier* tmp = new string_identifier{p_input, l_input};
      if (l_pps >= l_max_pps) expand_string_array_size(pps, l_pps, l_max_pps);
      *(pps + l_pps++) = tmp;
      l_input = 0;
      l_max_input = 32;
      delete[] p_input;
      p_input = new char[l_max_input];
    }
    if (l_input >= l_max_input)
        expand_char_array_size(p_input, l_input, l_max_input);
      p_input[l_input++] = c;
    };
    delete[] p_input;
    for (int i = 0; i < l_pps; ++i) std::cout << *pps[i] << std::endl;

    if (checking_string()) 
    std::cerr << "Here some errors" << std::endl;

    for (int i = 0; i < l_pps; ++i)
      delete pps[i];
  delete[] pps;
  // THE END - PART WITH USERS INPUT

  

  return 0;
}

void expand_string_array_size(my_string::string**& pp, int l, int& l_max_old,
                              double coeff) {
  l_max_old *= coeff;
  if (l >= l_max_old) l_max_old *= 2;
  my_string::string** pp_new = new my_string::string*[l_max_old];
  for (int i = 0; i < l; ++i) pp_new[i] = pp[i];
  delete[] pp;
  pp = pp_new;
  return;
}

void expand_char_array_size(char*& p, int l, int& l_max_old, double coeff) {
  l_max_old *= coeff;
  if (l >= l_max_old) l_max_old *= 2;
  char* p_new = new char[l_max_old];
  for (int i = 0; i < l; ++i) p_new[i] = p[i];
  delete[] p;
  p = p_new;
  return;
}

int checking_string() {
  using namespace std;
  using namespace my_string;
  int e_code = 0;

  {
    string_identifier tmp{};

    cout << "Empty constructor test: "
         << (tmp.i_get_string() && !tmp.i_get_lenght() ? "SUCCESS"
                                                       : (e_code++, "FAIL"))
         << endl;
  }
  if (!e_code) {
    const char* test_result = "a";
    string_identifier tmp{'a'};

    bool test1 = !(tmp.i_compare_with_string(test_result, 1));
    bool test2 = tmp.i_get_lenght() == 1;
    cout << "Char constructor test : "
         << (test1 && test2 ? "SUCCESS" : (e_code++, "FAIL")) << endl;
  }
  if (!e_code) {
    const char* test_result = "bebra";
    string_identifier tmp{test_result, 5};

    cout << "String constructor test: "
         << (tmp.i_compare_with_string(test_result, 5) ? (e_code++, "FAIL")
                                                       : "SUCCESS")
         << endl;
  }

  if (!e_code) {
    const char* for_test = "bebra";
    string_identifier from{for_test, 5};
    string_identifier to{from};

    cout << "Copy constructor test: "
         << (to.i_compare_with_string(from.i_get_string(), from.i_get_lenght())
                 ? (e_code++, "FAIL")
                 : "SUCCESS")
         << endl;
  }

  if (!e_code) {
    const char *for_test = "bEbRa", *test_result_1 = "BEBRA",
               *test_result_2 = "bebra";
    string_identifier test1{for_test, 5}, test2{for_test, 5};

    test1.i_set_uppercase();
    cout << "Uppercase func test : "
         << (test1.i_compare_with_string(test_result_1, 5) ? (e_code++, "FAIL")
                                                           : "SUCCESS")
         << endl;

    test2.i_set_lowercase();
    cout << "Lowercase func test: "
         << (test2.i_compare_with_string(test_result_2, 5) ? (e_code++, "FAIL")
                                                           : "SUCCESS")
         << endl;
  }

  if (!e_code) {
    const char* for_test = "bebra";
    string_identifier from{for_test, 5}, to = from;

    cout << "Overload for \'=\' operation test result: "
         << (to.i_compare_with_string(from.i_get_string(), from.i_get_lenght())
                 ? (e_code++, "FAIL")
                 : "SUCCESS")
         << endl;
  }

  if (!e_code) {
    const char *for_test1 = "sobakaA", *for_test2 = "sobakaB",
               *test_result = "sobakaAsobakaB";
    string_identifier test1{for_test1, 7}, test2{for_test2, 7};

    test1 + test2;
    cout << "Overload for \'+\' operation test result: "
         << (test1.i_compare_with_string(test_result, 14) ? (e_code++, "FAIL")
                                                          : "SUCCESS")
         << endl;
  }

  if (!e_code) {
    const char *for_test1 = "sobakaAsobakaB", *for_test2 = "sobaka",
               *test_result = "AsobakaB";
    string_identifier test1{for_test1, 14}, test2{for_test2, 6};
    // :))))))))))))))))))))))))))))))
    test1 - static_cast<string_identifier&&>(test2);
    cout << "Overload for \'-\' operation test result: "
         << (test1.i_compare_with_string(test_result, 8) ? (e_code++, "FAIL")
                                                         : "SUCCESS")
         << endl;
  }

  if (!e_code) {
    const char *for_test1 = "bebra", *for_test2 = "beppa";
    const int test_result = 'b' - 'p';
    string_identifier test1{for_test1, 5}, test2{for_test2, 5};

    cout << "Overload for \'>\' operation test result: "
         << (((test1 > test2) == test_result) ? "SUCCESS" : (e_code++, "FAIL"))
         << endl;
  }

  if (!e_code) {
    const char *for_test1 = "bebra, 5", *for_test2 = "beppa, 5";
    const int test_result = 'b' - 'p';
    string_identifier test1{for_test1, 5}, test2{for_test2, 5};

    cout << "Overload for \'<\' operation test result: "
         << (((test1 < test2) == test_result) ? "SUCCESS" : (e_code++, "FAIL"));
  }

  return e_code;
}