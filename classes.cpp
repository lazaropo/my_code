#include "classes.h"

namespace my_string {

void print_string(const char *str, const int l, std::ostream &to = std::cout) {
  for (int i = 0; i < l; ++i) {
    to << str[i];
  }
  return;
}

string::string() : mpstring(new char[32]), mlenght(0) {}

string::string(const char *ptr, int l) : mpstring(new char[l]), mlenght(l) {
  for (int i = 0; i < l; ++i) mpstring[i] = ptr[i];
}

string::string(char c) : mpstring(new char[1]), mlenght(1) { mpstring[0] = c; }

string::string(const string &parent)
    : string::string(parent.i_get_string(), parent.i_get_lenght()),
      mlenght(parent.i_get_lenght()) {}

string::~string() {
  delete[] mpstring;
  mlenght = 0;
}

int string::i_get_lenght() const { return mlenght; }

void string::i_remove_string() {
  delete[] mpstring;
  mpstring = nullptr;
  mlenght = 0;
}

char *string::i_get_string() const { return mpstring; }

void string::i_set_char(char c) {
  char *tmp = new char[++m_lenght];
  for (int i = 0; i < m_lenght; ++i) tmp[i] = mp_string[i];
  tmp[m_lenght] = c;
  delete[] mp_string;
  mp_string = tmp;
  return;
}

void string::i_set_string(char *new_string, int new_l) {
  delete mp_string;
  mp_string = new char[new_l];
  m_lenght = new_l;
  for (int i = 0; i < new_l; ++i) mp_string[i] = new_string[i];
  return;
}

//
// Definisions of funcs from STRING_IDENTIFIER class
//
int string_identifier::CheckChar(char c) {
  return ((c > kLowerA && c < kLowerZ) || (c > kUpperA && c < kUpperZ) ||
          c == '_')
             ? 0
             : 1;
}

int m_comparator(const string_identifier &obj1, const string_identifier &obj2) {
  char *ptr1 = obj1.i_get_string(), *ptr2 = obj2.i_get_string();
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

// char delta = ('a' - 'A') > 0 ? 'a' - 'A' : - ('a' - 'A');

char *StringIdentifier::iFindSubstring(const char *ptr) const {
  int i = 0;
  char *ptr_str = this->iGetGtring();
  for (int j = 0; ptr_str[i]; ++i) {
    for (j = 0; ptr[j] && ptr_str[i + j] && ptr[j] == ptr_str[i + j]; ++j) {
      ;
    }
    if (!ptr[j]) {
      break;
    }
  }
  return ptr_str[i] ? &ptr_str[i] : nullptr;
}

/*char* remove_substring(const char* ptr){
    if (!ptr) {
        return nullptr;
    }
    int size_ptr = 0;
    for (; ptr[size_ptr]; ++size_ptr) { ; }
    char* mpstring = this->iGetGtring();
    int size_str = 0;
    for (; mpstring[size_str]; ++size_str) { ; }
    if (size_str >= size_ptr) {
        while(mpstring[size_str])
    }
    else {

<<<<<<< HEAD
    std::ostream& print_string(const char* mpstring, const int mlenght,
std::ostream& to) { if (!mpstring) { return to;
        }
        for (int i = 0; i < mlenght; ++i) {
            to << mpstring[i];
        }
        return to;
    }

    int comparator(const char* str1, const char* str2) {
        int i = 0;
        for (; str1[i] == str2[i]; ++i) { ; }
        return static_cast<int>(str1[i]) - static_cast<int>(str2[i]);
=======
>>>>>>> eed27bc85d40a7c49a0ed83e0bb6f183ce277a6a
    }

}*/

string_identifier::string_identifier() : String() {}

string_identifier::string_identifier(char *ptr) {
  char *mpstring = iGetGtring();
  if (mpstring) {
    string_identifier();
  }
  int i = 0;

  do {
    if (CheckChar(ptr[i])) {
      RemoveString();
      i = 0;
      break;
    } else {
      SetChar(ptr[i]);
    }
  } while (mpstring[i++]);
  // string.mlenght=i?--i:i;
}

string_identifier::string_identifier(char c) {
  if (CheckChar(c)) {
    RemoveString();
  } else {
    SetChar(c);
  }
}

string_identifier::string_identifier(const string_identifier &dad)
    : String(static_cast<const String &>(dad)) {}

void string_identifier::iSetUppercase() {
  int mlenght = iGetLenght();
  char *mpstring = iGetGtring();
  char delta = kLowerA - kUpperA > 0 ? kLowerA - kUpperA : -(kLowerA - kUpperA);
  for (int i = 0; i < mlenght; ++i) {
    mpstring[i] = mpstring[i] > kUpperZ ? mpstring[i] - delta : mpstring[i];
  }
  return;
}

void string_identifier::iSetLowercase() {
  int mlenght = iGetLenght();
  char *mpstring = iGetGtring();
  char delta = kLowerA - kUpperA > 0 ? kLowerA - kUpperA : -(kLowerA - kUpperA);
  for (int i = 0; i < mlenght; ++i) {
    mpstring[i] = mpstring[i] < kLowerA ? mpstring[i] + delta : mpstring[i];
  }
  return;
}

char *string_identifier::iFindSymbol(char c) {
  char *ptr = iGetGtring();
  while (*ptr != c) {
    ptr++;
  }
  return ptr;
}

int string_identifier::iGetLenght() const { return this->iGetLenght(); }

// string_identifier::~string_identifier{};

string_identifier &string_identifier::operator=(const string_identifier &init) {
  this->SetString(init.iGetGtring(), init.iGetLenght());
  // string_identifier(init);
  return *this;
};

string_identifier &string_identifier::operator+(string_identifier &temp) {
  this->SetString(temp.iGetGtring(), temp.iGetLenght());
  // string* pb = &*this;
  // *pb={temp.iGetGtring()};
  return *this;
};

string_identifier &string_identifier::operator-(string_identifier &&tmp) {
  char *here = iFindSubstring(tmp.iGetGtring());
  if (here) {
    char *ptr = iGetGtring(),
         *new_s = new char[iGetLenght() - tmp.iGetLenght()];
    int new_l = 0;
    while (ptr != here) {
      new_s[new_l++] = *ptr;
      ptr++;
    }
    while (*here) {
      ptr++;
    }
    while (*ptr) {
      new_s[new_l++] = *ptr;
      ptr++;
    }
    RemoveString();
    SetString(new_s, new_l);
    // delete new_s;
  }
  return *this;
}

int string_identifier::operator>(const string_identifier &cmpr) {
  char *ptr = iGetGtring();
  char *ptr_cmpr = cmpr.iGetGtring();

  while (*ptr == *ptr_cmpr) {
    ptr++;
    ptr_cmpr++;
  }

  return static_cast<int>(*ptr - *ptr_cmpr);
}

int string_identifier::operator<(const string_identifier &cmpr) {
  char *ptr = iGetGtring();
  char *ptr_cmpr = cmpr.iGetGtring();

  while (*ptr == *ptr_cmpr) {
    ptr++;
    ptr_cmpr++;
  }

  std::ostream &operator<<(std::ostream &to, const string &obj) {
    print_string(obj.iGetGtring(), obj.iGetLenght(), to);
    return to;
  }

  // int string::comparator(const char* str1, const char* str2) const { return
  // str1 && str2 ? nullptr : nullptr; }

  //
  // Definisions of funcs from STRING_IDENTIFIER class
  //
  int string_identifier::CheckChar(char c) {
    return ((c > kLowerA && c < kLowerZ) || (c > kUpperA && c < kUpperZ) ||
            c == '_')
               ? 0
               : 1;
  }

  char delta = ('a' - 'A') > 0 ? 'a' - 'A' : -('a' - 'A');
  /*
  char* string_identifier::iFindSubstring(const char* ptr) const {
      int i=0;
      char* ptr_str = this->iGetGtring();
      for(int j=0; ptr_str[i]; ++i){
          for(j=0; ptr[j] && ptr_str[i+j] && ptr[j]== ptr_str[i+j]; ++j){;}
          if(!ptr[j]){
              break;
          }
      }
      return ptr_str[i]?&ptr_str[i]:nullptr;
  }
  */

  /*char* remove_substring(const char* ptr){
      if (!ptr) {
          return nullptr;
      }
      int size_ptr = 0;
      for (; ptr[size_ptr]; ++size_ptr) { ; }
      char* mpstring = this->iGetGtring();
      int size_str = 0;
      for (; mpstring[size_str]; ++size_str) { ; }
      if (size_str >= size_ptr) {
          while(mpstring[size_str])
      }
      else {

      }

  }*/

  StringIdentifier::StringIdentifier() : String() {}

  StringIdentifier::StringIdentifier(char *ptr) {
    char *mpstring = iGetGtring();
    if (mpstring) {
      StringIdentifier();
    }
    int i = 0;

    do {
      if (CheckChar(ptr[i])) {
        RemoveString();
        i = 0;
        break;
      } else {
        SetChar(ptr[i]);
      }
    } while (mpstring[i++]);
    // string.mlenght=i?--i:i;
  }

  StringIdentifier::StringIdentifier(char c) {
    if (CheckChar(c)) {
      RemoveString();
    } else {
      SetChar(c);
    }
  }

  StringIdentifier::StringIdentifier(const StringIdentifier &dad)
      : String(static_cast<const String &>(dad)) {}

  void StringIdentifier::iSetUppercase() {
    int mlenght = iGetLenght();
    char *mpstring = iGetGtring();
    char delta =
        kLowerA - kUpperA > 0 ? kLowerA - kUpperA : -(kLowerA - kUpperA);
    for (int i = 0; i < mlenght; ++i) {
      mpstring[i] = mpstring[i] > kUpperZ ? mpstring[i] - delta : mpstring[i];
    }
    return;
  }

  void StringIdentifier::iSetLowercase() {
    int mlenght = iGetLenght();
    char *mpstring = iGetGtring();
    char delta =
        kLowerA - kUpperA > 0 ? kLowerA - kUpperA : -(kLowerA - kUpperA);
    for (int i = 0; i < mlenght; ++i) {
      mpstring[i] = mpstring[i] < kLowerA ? mpstring[i] + delta : mpstring[i];
    }
    return;
  }

  char *StringIdentifier::iFindSymbol(char c) {
    char *ptr = iGetGtring();
    while (*ptr != c) {
      ptr++;
    }
    return ptr;
  }

  int StringIdentifier::iGetLenght() const { return String::iGetLenght(); }

  // string_identifier::~string_identifier{};

  StringIdentifier &StringIdentifier::operator=(const StringIdentifier &init) {
    this->SetString(init.iGetGtring(), init.iGetLenght());
    // string_identifier(init);
    return *this;
  };

  StringIdentifier &StringIdentifier::operator=(char *ptr) {
    int size = 0;
    while (*(ptr + size)) {
      ++size;
    }
    this->SetString(ptr, size);
    return *this;
  }

  StringIdentifier &StringIdentifier::operator+(StringIdentifier &temp) {
    this->SetString(temp.iGetGtring(), temp.iGetLenght());
    // string* pb = &*this;
    // *pb={temp.iGetGtring()};
    return *this;
  };

  StringIdentifier &StringIdentifier::operator-(StringIdentifier &&tmp) {
    char *here = iFindSubstring(tmp.iGetGtring());
    if (here) {
      char *ptr = iGetGtring(),
           *new_s = new char[iGetLenght() - tmp.iGetLenght()];
      int new_l = 0;
      while (ptr != here) {
        new_s[new_l++] = *ptr;
        ptr++;
      }
      while (*here) {
        ptr++;
      }
      while (*ptr) {
        new_s[new_l++] = *ptr;
        ptr++;
      }
      RemoveString();
      SetString(new_s, new_l);
      // delete new_s;
    }
    return *this;
  }

  int StringIdentifier::operator>(const StringIdentifier &cmpr) {
    /*char* ptr = iGetGtring();
    char* ptr_cmpr = cmpr.iGetGtring();

    while (*ptr == *ptr_cmpr) {
        ptr++;
        ptr_cmpr++;
    }

    return static_cast<int>(*ptr - *ptr_cmpr);*/
    return comparator(this->iGetGtring(), cmpr.iGetGtring());
  }

  int StringIdentifier::operator<(const StringIdentifier &cmpr) {
    /*char* ptr = iGetGtring();
    char* ptr_cmpr = cmpr.iGetGtring();

    while (*ptr == *ptr_cmpr) {
        ptr++;
        ptr_cmpr++;
    }

    return static_cast<int>(*ptr-*ptr_cmpr);*/
    return comparator(this->iGetGtring(), cmpr.iGetGtring());
  }

  std::ostream &operator<<(std::ostream &to, const StringIdentifier &obj) {
    print_string(obj.iGetGtring(), obj.iGetLenght(), to);
    return to;
  }
};
== == == = return static_cast<int>(*ptr - *ptr_cmpr);
}

std::ostream &StringIdentifier::operator<<(std::ostream &os,
                                           const StringIdentifier &) {
  os << print_string(iGetGtring(), iGetLenght());
  return os;
}
}
;  // namespace my_string
>>>>>>> eed27bc85d40a7c49a0ed83e0bb6f183ce277a6a
