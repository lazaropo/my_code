#include "classes.h"
namespace my_string{

    void print_string(const char* str, const int lenght) {
        for (int i = 0; i < lenght; ++i) {
            cout << str[i];
        }
        return;
    }

    int comparator(const char* str1, const char* str2) const {
        int i = 0;
        for (; str1[i] == str2[i]; ++i) { ; }
        return static_cast<int>(str1[i]) - static_cast<int>(str2[i]);
    }

    string::string()
        : str(new char[2]), lenght(0) {}

    string::string(char* ptr)
        : string(){
        do{
            str[lenght]=ptr[lenght];
        }while(str[lenght++]);
        --lenght;
    }

    string::string(char c)
    :str(new char[2]), lenght(2) {
        str[0]=c;
        str[1]='\0';
    }

    string::string(const string& mom):
    str(mom.str), lenght(mom.lenght){}


    int string::get_lenght() const {
        return lenght;
    }

    void string::remove_string(){
        delete[] str;
        str = nullptr;
        lenght=0;
    }

    string::~string(){
        delete[] str;
        lenght = 0;
    }

    char* string::get_string() const{
        return str;
    }

    void string::set_char(char c) {
        str[lenght] = c;
        str[++lenght] = '\0';
        return;
    }

    void string::set_string(char*new_string, int new_lenght) {
        delete str;
        str = new_string;
        lenght = new_lenght;
        return;
    }

    char* string::find_substring(const char* ptr) const { return ptr?nullptr:nullptr; }

    // int string::comparator(const char* str1, const char* str2) const { return str1 && str2 ? nullptr : nullptr; }

    //
    // Definisions of funcs from STRING_IDENTIFIER class
    //
    int string_identifier::check_char(char c){
        return ((c > LOWER_A && c < LOWER_Z)||(c>UPPER_A && c< UPPER_Z) ||
        c == '_' ) ? 0 : 1;
    }

    char delta = ('a' - 'A')>0? 'a' - 'A': -('a' - 'A');

    char* string_identifier::find_substring(const char* ptr) const {
        int i=0;
        char* ptr_str = this->get_string();
        for(int j=0; ptr_str[i]; ++i){
            for(j=0; ptr[j] && ptr_str[i+j] && ptr[j]== ptr_str[i+j]; ++j){;}
            if(!ptr[j]){
                break;
            }
        }
        return ptr_str[i]?&ptr_str[i]:nullptr;
    }

    

    /*char* remove_substring(const char* ptr){
        if (!ptr) {
            return nullptr;
        }
        int size_ptr = 0;
        for (; ptr[size_ptr]; ++size_ptr) { ; }
        char* str = this->get_string();
        int size_str = 0;
        for (; str[size_str]; ++size_str) { ; }
        if (size_str >= size_ptr) {
            while(str[size_str])
        }
        else {

        }

    }*/

    string_identifier::string_identifier()
    : string(){}

    string_identifier::string_identifier(char* ptr){
        char* str = get_string();
            if(str){
                string_identifier();
            }
            int i=0;

            do{
                if(check_char(ptr[i])){
                    remove_string();
                    i = 0;
                    break;
                }else{
                    set_char(ptr[i]);
                }
            }while(str[i++]);
            // string.lenght=i?--i:i;
    }

    string_identifier::string_identifier(char c){
        if(check_char(c)){
            remove_string();
        }else{
            set_char(c);
        }
    }

    string_identifier::string_identifier(const string_identifier& dad)
        :string(static_cast<const string&>(dad)){
    }

    void string_identifier::uppercase(){
        int lenght = get_lenght();
        char* str = get_string();
        char delta = LOWER_A - UPPER_A > 0 ? LOWER_A - UPPER_A : -(LOWER_A - UPPER_A);
        for (int i = 0; i < lenght; ++i) {
            str[i]= str[i]>UPPER_Z ? str[i] - delta : str[i];
        }
        return;
    }

    void string_identifier::lowercase(){
        int lenght = get_lenght();
        char* str = get_string();
        char delta = LOWER_A - UPPER_A > 0 ? LOWER_A - UPPER_A : -(LOWER_A - UPPER_A);
        for (int i = 0; i < lenght; ++i) {
            str[i]= str[i]<LOWER_A ? str[i]+delta : str[i];
        }
        return;
    }

    char* string_identifier::find_symbol(char c){
        char* ptr=get_string();
        while(*ptr!=c){
            ptr++;
        }
        return ptr;
    }

    int string_identifier::get_lenght() const {
        return this->get_lenght();
    }

    // string_identifier::~string_identifier{};

    string_identifier& string_identifier::operator=(const string_identifier& init){
        this->set_string(init.get_string(), init.get_lenght());
        // string_identifier(init);
        return *this;
    };

    string_identifier& string_identifier::operator+(string_identifier& temp){
        this->set_string(temp.get_string(), temp.get_lenght());
        // string* pb = &*this;
        // *pb={temp.get_string()};
        return *this;
    };

    string_identifier& string_identifier::operator-(string_identifier&& tmp){
        char* here = find_substring(tmp.get_string());
        if(here){
            char* ptr = get_string(), *new_s = new char[get_lenght()-tmp.get_lenght()];
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
            remove_string();
            set_string(new_s, new_l);
            // delete new_s;
        }
        return *this;
    }
    
    int string_identifier::operator>(const string_identifier& cmpr) {
        /*char* ptr = get_string();
        char* ptr_cmpr = cmpr.get_string();

        while (*ptr == *ptr_cmpr) {
            ptr++;
            ptr_cmpr++;
        }

        return static_cast<int>(*ptr - *ptr_cmpr);*/
        return comparator(this->get_string(), cmpr.(get_string()));
    }

    int string_identifier::operator<(const string_identifier& cmpr) {
        /*char* ptr = get_string();
        char* ptr_cmpr = cmpr.get_string();

        while (*ptr == *ptr_cmpr) {
            ptr++;
            ptr_cmpr++;
        }

        return static_cast<int>(*ptr-*ptr_cmpr);*/
        return comparator(this->get_string(), cmpr.(get_string()));
    }

    std::ostream& string_identifier::operator<<(std::ostream& os, const string_identifier&) {
        os << print_string(get_string(), get_lenght());
        return os;
    }
};