#include "classes.h"
namespace my_string {

void print_string(const char *mpstring, const int mlenght) {
  for (int i = 0; i < mlenght; ++i) {
    std::cout << mpstring[i];
  }
  return;
}

String::String() : mpstring(new char[2]), mlenght(0) {}

String::String(const char *ptr, int l) : mpstring(new char[l]), mlenght(l) {
    for (int i = 0; i < l; ++i)
        mpstring[i] = ptr[i];
}

String::String(char c) : mpstring(new char[1]), mlenght(1) {
  mpstring[0] = c;
}

String::String(const String &parent) : 
    String::String(parent.iGetGtring(), parent.iGetLenght()), 
    mlenght(parent.iGetLenght()) {}

int String::iGetLenght() const { return mlenght; }

void String::RemoveString() {
  delete[] mpstring;
  mpstring = nullptr;
  mlenght = 0;
}

String::~String() {
  delete[] mpstring;
  mlenght = 0;
}

char *String::iGetGtring() const { return mpstring; }

void String::SetChar(char c){
  mpstring[mlenght] = c;
  mpstring[++mlenght] = '\0';
  return;
}

void String::SetString(char *new_string, int new_lenght) {
  delete mpstring;
  mpstring = new_string;
  mlenght = new_lenght;
  return;
}

//
// Definisions of funcs from STRING_IDENTIFIER class
//
int StringIdentifier::CheckChar(char c) {
  return ((c > kLowerA && c < kLowerZ) || (c > kUpperA && c < kUpperZ) ||
          c == '_')
             ? 0
             : 1;
}

char delta = ('a' - 'A') > 0 ? 'a' - 'A' : -('a' - 'A');

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
    std::ostream& print_string(const char* mpstring, const int mlenght, std::ostream& to) {
        if (!mpstring) {
            return to;
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
  char delta = kLowerA - kUpperA > 0 ? kLowerA - kUpperA : -(kLowerA - kUpperA);
  for (int i = 0; i < mlenght; ++i) {
    mpstring[i] = mpstring[i] > kUpperZ ? mpstring[i] - delta : mpstring[i];
  }
  return;
}

void StringIdentifier::iSetLowercase() {
  int mlenght = iGetLenght();
  char *mpstring = iGetGtring();
  char delta = kLowerA - kUpperA > 0 ? kLowerA - kUpperA : -(kLowerA - kUpperA);
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

int StringIdentifier::iGetLenght() const { return this->iGetLenght(); }

// string_identifier::~string_identifier{};

StringIdentifier &StringIdentifier::operator=(const StringIdentifier &init) {
  this->SetString(init.iGetGtring(), init.iGetLenght());
  // string_identifier(init);
  return *this;
};

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
  char *ptr = iGetGtring();
  char *ptr_cmpr = cmpr.iGetGtring();

  while (*ptr == *ptr_cmpr) {
    ptr++;
    ptr_cmpr++;
  }

  return static_cast<int>(*ptr - *ptr_cmpr);
}

int StringIdentifier::operator<(const StringIdentifier &cmpr) {
  char *ptr = iGetGtring();
  char *ptr_cmpr = cmpr.iGetGtring();

  while (*ptr == *ptr_cmpr) {
    ptr++;
    ptr_cmpr++;
  }

<<<<<<< HEAD
    std::ostream& operator<<(std::ostream& to, const String& obj) {
        print_string(obj.iGetGtring(), obj.iGetLenght(), to);
        return to;
    }

    // int string::comparator(const char* str1, const char* str2) const { return str1 && str2 ? nullptr : nullptr; }

    //
    // Definisions of funcs from STRING_IDENTIFIER class
    //
    int StringIdentifier::CheckChar(char c){
        return ((c > kLowerA && c < kLowerZ)||(c>kUpperA && c< kUpperZ) ||
        c == '_' ) ? 0 : 1;
    }

    char delta = ('a' - 'A')>0? 'a' - 'A': -('a' - 'A');
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

    StringIdentifier::StringIdentifier()
    : String(){}

    StringIdentifier::StringIdentifier(char* ptr){
        char* mpstring = iGetGtring();
            if(mpstring){
                StringIdentifier();
            }
            int i=0;

            do{
                if(CheckChar(ptr[i])){
                    RemoveString();
                    i = 0;
                    break;
                }else{
                    SetChar(ptr[i]);
                }
            }while(mpstring[i++]);
            // string.mlenght=i?--i:i;
    }

    StringIdentifier::StringIdentifier(char c){
        if(CheckChar(c)){
            RemoveString();
        }else{
            SetChar(c);
        }
    }

    StringIdentifier::StringIdentifier(const StringIdentifier& dad)
        :String(static_cast<const String&>(dad)){
    }

    void StringIdentifier::iSetUppercase(){
        int mlenght = iGetLenght();
        char* mpstring = iGetGtring();
        char delta = kLowerA - kUpperA > 0 ? kLowerA - kUpperA : -(kLowerA - kUpperA);
        for (int i = 0; i < mlenght; ++i) {
            mpstring[i]= mpstring[i]>kUpperZ ? mpstring[i] - delta : mpstring[i];
        }
        return;
    }

    void StringIdentifier::iSetLowercase(){
        int mlenght = iGetLenght();
        char* mpstring = iGetGtring();
        char delta = kLowerA - kUpperA > 0 ? kLowerA - kUpperA : -(kLowerA - kUpperA);
        for (int i = 0; i < mlenght; ++i) {
            mpstring[i]= mpstring[i]<kLowerA ? mpstring[i]+delta : mpstring[i];
        }
        return;
    }

    char* StringIdentifier::iFindSymbol(char c){
        char* ptr=iGetGtring();
        while(*ptr!=c){
            ptr++;
        }
        return ptr;
    }

    int StringIdentifier::iGetLenght() const {
        return String::iGetLenght();
    }

    // string_identifier::~string_identifier{};

    StringIdentifier& StringIdentifier::operator=(const StringIdentifier& init){
        this->SetString(init.iGetGtring(), init.iGetLenght());
        // string_identifier(init);
        return *this;
    };

    StringIdentifier& StringIdentifier::operator=(char* ptr) {
        int size = 0;
        while (*(ptr + size)) {
            ++size;
        }
        this->SetString(ptr, size);
        return *this;
    }

    StringIdentifier& StringIdentifier::operator+(StringIdentifier& temp){
        this->SetString(temp.iGetGtring(), temp.iGetLenght());
        // string* pb = &*this;
        // *pb={temp.iGetGtring()};
        return *this;
    };

    StringIdentifier& StringIdentifier::operator-(StringIdentifier&& tmp){
        char* here = iFindSubstring(tmp.iGetGtring());
        if(here){
            char* ptr = iGetGtring(), *new_s = new char[iGetLenght()-tmp.iGetLenght()];
            int new_l=0;
            while(ptr!=here){
                new_s[new_l++]=*ptr;
                ptr++;
            }
            while(*here){
                ptr++;
            }
            while(*ptr){
                new_s[new_l++]=*ptr;
                ptr++;
            }
            RemoveString();
            SetString(new_s, new_l);
            // delete new_s;
        }
        return *this;
    }
    
    int StringIdentifier::operator>(const StringIdentifier& cmpr) {
        /*char* ptr = iGetGtring();
        char* ptr_cmpr = cmpr.iGetGtring();

        while (*ptr == *ptr_cmpr) {
            ptr++;
            ptr_cmpr++;
        }

        return static_cast<int>(*ptr - *ptr_cmpr);*/
        return comparator(this->iGetGtring(), cmpr.iGetGtring());
    }

    int StringIdentifier::operator<(const StringIdentifier& cmpr) {
        /*char* ptr = iGetGtring();
        char* ptr_cmpr = cmpr.iGetGtring();

        while (*ptr == *ptr_cmpr) {
            ptr++;
            ptr_cmpr++;
        }

        return static_cast<int>(*ptr-*ptr_cmpr);*/
        return comparator(this->iGetGtring(), cmpr.iGetGtring());
    }

    std::ostream& operator<<(std::ostream& to, const StringIdentifier& obj) {
        print_string(obj.iGetGtring(), obj.iGetLenght(), to);
        return to;
    }
};
=======
  return static_cast<int>(*ptr - *ptr_cmpr);
}

std::ostream &StringIdentifier::operator<<(std::ostream &os,
                                            const StringIdentifier &) {
  os << print_string(iGetGtring(), iGetLenght());
  return os;
}
}; // namespace my_string
>>>>>>> eed27bc85d40a7c49a0ed83e0bb6f183ce277a6a
