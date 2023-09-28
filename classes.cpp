#include "classes.h"

#include "cassert"
namespace my_string {

std::ostream& print_string(const char* str, const int l, std::ostream& to) {
  for (int i = 0; i < l; ++i) to << str[i];
  return to;
}

string::string() : mp_string(new char[32]), m_lenght(0) {}

string::string(const char* ptr, const int l)
    : mp_string(new char[l]), m_lenght(l) {
  for (int i = 0; i < l; ++i) mp_string[i] = ptr[i];
}

string::string(const char c) : mp_string(new char[1]), m_lenght(1) {
  mp_string[0] = c;
}

string::string(const string& parent)
    : string(parent.e_get_string(), parent.i_get_lenght()) {}

string::~string() {
  delete[] mp_string;
  mp_string = nullptr;
  m_lenght = 0;
}

int string::i_get_lenght() const { return m_lenght; }

void string::e_remove_string() {
  delete[] mp_string;
  mp_string = nullptr;
  m_lenght = 0;
}

char* string::i_get_string() { return mp_string; }

const char* string::e_get_string() const { return mp_string; }

void string::e_set_char(const char c) {
  char* tmp = new char[++m_lenght];
  for (int i = 0; i < m_lenght; ++i) tmp[i] = mp_string[i];
  tmp[m_lenght] = c;
  delete[] mp_string;
  mp_string = tmp;
  return;
}

void string::e_set_string(const char* new_string, const int new_l) {
  delete[] mp_string;
  mp_string = new char[new_l];
  m_lenght = new_l;
  for (int i = 0; i < new_l; ++i) mp_string[i] = new_string[i];
  return;
}

void string::e_add_string(const char* p, const int l) {
  char* mp_string_new = new char[m_lenght + l];
  for (int i = 0; i < m_lenght; ++i) mp_string_new[i] = mp_string[i];
  for (int i = 0; i < l; ++i) mp_string_new[m_lenght + i] = p[i];
  delete[] mp_string;
  mp_string = mp_string_new;
  m_lenght = m_lenght + l;
  return;
}

int string::i_compare_with_string(const char* str, const int l) const {
  assert(str && l);
  int i = 0;
  // std::cout << std::endl << mp_string[i] << std::endl << str[i];
  for (; str[i] == mp_string[i] && i < m_lenght && i < l; ++i)
    ;
  --i;
  if (mp_string[i] > str[i])
    return 1;
  else if (mp_string[i] == str[i])
    return 0;
  else
    return -1;
}

//
// Definisions of funcs from STRING_IDENTIFIER class
//
int string_identifier::m_check_char(const char c) {
  return ((c >= k_lower_a && c <= k_lower_z) ||
          (c >= k_upper_a && c <= k_upper_z) || c == '_')
             ? 0
             : 1;
}

int string_identifier::m_comparator(const string_identifier& obj1,
                                    const string_identifier& obj2) {
  const char *ptr1 = obj1.e_get_string(), *ptr2 = obj2.e_get_string();
  int ret_value = 0, l1 = obj1.i_get_lenght(), l2 = obj2.i_get_lenght();
  int i = 0, max_i = l1 > l2 ? l2 : l1;
  for (; ptr1[i] == ptr2[i] && i < max_i; ++i) {
    if (i == max_i - 1) {
      if (l1 == max_i)
        ret_value = -1;
      else if (l2 == max_i)
        ret_value = 1;
    }
  }
  if (--i != max_i - 1 && (ptr1[i] - ptr2[i]) > 0)
    ret_value = 1;
  else if ((ptr1[i] - ptr2[i]) < 0)
    ret_value = -1;
  return ret_value;
}


string_identifier::string_identifier() 
    : string() {}

string_identifier::string_identifier(const char* ptr, const int l)
    : string(ptr, l) {
  // How to check every char???
  // if (!m_check_char(c))
}

string_identifier::string_identifier(const char c) 
    : string(c) {
  // if (!m_check_char(c))
}

string_identifier::string_identifier(const string_identifier& parent)
    : string(static_cast<const string&>(parent)) {}

void string_identifier::i_set_uppercase() {
  const char k_delta = k_lower_a - k_upper_a > 0 
      ? k_lower_a - k_upper_a
      : -(k_lower_a - k_upper_a);
  char* p = i_get_string();
  for (int i = 0, l = i_get_lenght(); i < l; ++i)
    p[i] = p[i] > k_upper_z ? p[i] - k_delta : p[i];
  return;
}

void string_identifier::i_set_lowercase() {
  const char k_delta = k_lower_a - k_upper_a > 0 
      ? k_lower_a - k_upper_a
      : -(k_lower_a - k_upper_a);
  char* p = i_get_string();
  for (int i = 0, l = i_get_lenght(); i < l; ++i)
    p[i] = p[i] < k_upper_a ? p[i] + k_delta : p[i];
  return;
}

const char* string_identifier::i_find_substring(const char* ptr,
                                                const int l) const {
  int i = 0;
  const int this_lenght = i_get_lenght();
  const char* this_str = e_get_string();
  for (int j = 0; i < this_lenght; ++i) {
    for (j = 0; i < this_lenght && j < l && ptr[j] == this_str[i + j]; ++j) {
      ;
    }
    if (j == l) {
      break;
    }
  }
  return i == this_lenght ? nullptr : &this_str[i];
}

string_identifier& string_identifier::operator=(const string_identifier& init) {
  this->e_set_string(init.e_get_string(), init.i_get_lenght());
  return *this;
};

string_identifier& string_identifier::operator+(const string_identifier& temp) {
  this->e_add_string(temp.e_get_string(), temp.i_get_lenght());
  return *this;
};

string_identifier& string_identifier::operator-(string_identifier&& tmp) {
  const char* here = i_find_substring(tmp.e_get_string(), tmp.i_get_lenght());
  if (here) {
    char *this_str = i_get_string(),
         *new_s = new char[i_get_lenght() - tmp.i_get_lenght()];
    int new_l = 0;
    while (*this_str != *here) {
      new_s[new_l++] = *this_str;
      this_str++;
    }
    for (int i = 0; i < tmp.i_get_lenght(); ++i) this_str++;
    while (*this_str) {
      new_s[new_l++] = *this_str;
      this_str++;
    }
    e_remove_string();
    e_set_string(new_s, new_l);
  }
  return *this;
}

int string_identifier::operator>(const string_identifier& cmpr) {
  const char *ptr = e_get_string(), *ptr_cmpr = cmpr.e_get_string();

  while (*ptr == *ptr_cmpr) {
    ptr++;
    ptr_cmpr++;
  }

  return static_cast<int>(*ptr - *ptr_cmpr);
}

int string_identifier::operator<(const string_identifier& cmpr) {
  const char *ptr = e_get_string(), *ptr_cmpr = cmpr.e_get_string();

  while (*ptr == *ptr_cmpr) {
    ptr++;
    ptr_cmpr++;
  }
  return static_cast<int>(*ptr - *ptr_cmpr);
}

std::ostream& operator<<(std::ostream& to, const string& obj) {
  print_string(obj.e_get_string(), obj.i_get_lenght(), to);
  return to;
}

std::ostream& operator<<(std::ostream& to, const string_identifier& obj) {
  print_string(obj.e_get_string(), obj.i_get_lenght(), to);
  return to;
}
}