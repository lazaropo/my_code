#include "classes.h"
namespace my_string{

    string::string():
    str(new char[0]), lenght(0){}

    string::string(char* ptr)
        : string(){
        int i = 0;
        do{
            str[i]=ptr[i];
        }while(str[i++]);
        lenght+=--i;
    }

    string::string(char c):{
        if(!lenght){
            string();
        }
        str[lenght]=c;
        str[++lenght]='\0';
    }

    string::string(const string& mom):
    str(mom.str), lenght(mom.lenght){}


    int string::get_lenght(){
        return lenght;
    }

    void string::remove_string(){
        delete str;
        str = nullptr;
        lenght=0;
    }

    string::~string(){
        delete str;
    }

    char* string::get_string(){
        return str;
    }


    //
    //Definisions of funcs from STRING_IDENTIFIER class
    //
    int string_identifier::check_char(char c){
        return ((c > LOWER_A && c < LOWER_Z)||(c>UPPER_A && c< UPPER_Z) ||
        c == '_' ) ? 0 : 1;
    }

    char delta = 'a' - 'A';

    if(delta<0){
        delta*=-1;
    }

    char* find_substring(const char* ptr){
        int i=0;
        for(int j=0; str[i]; ++i){
            for(j=0; ptr[j] && str[i+j] && ptr[j]==str[i+j]; ++j){;}
            if(!ptr[j]){
                break;
            }
        }
        return str[i]?&str[i]:nullptr;
    }

    char* remove_substring(const char* ptr){

    }

public:
    string_identifier()
        : string(){}

    string_identifier(char* ptr)
        :{
            if(!string.str){
                string();
            }
            int i=0;

            do{
                if(check_char(ptr[i])){
                    string.remove_string();
                    i = 0;
                    break;
                }else{
                    string(ptr[i]);
                }
            }while(str[i++]);
            string.lenght=i?--i:i;
        }

    string_identifier(char c)
        :{
            if(check_char(c)){
                    string.remove_string();
                    break;
                }else{
                    string(c);
                }
        }

    string_identifier::string_identifier(const string_identifier& dad)
        :string(dad){}

    void string_identifier::uppercase(){
        for(int i=0; i<lenght:++i){
            string.str[i]= string.str[i]>UPPER_Z: string.str[i] - delta:
            string.str[i];
        }
        return;
    }

    void string_identifier::lowercase(){
        for(int i=0; i<lenght:++i){
            string.str[i]= string.str[i]<LOWER_A: string.str[i]+delta :
            string.str[i];
        }
        return;
    }

    char* string_identifier::find_symbol(char c){
        char* ptr=string.str;
        while(*ptr!=c){
            ptr++;
        }
        return ptr;
    }

    string_identifier::~string_identifier{
        delete string;
    };

    string_identifier& string_identifier::operator=(const string_identifier& init){
        string_identifier(init);
        return *this;
    };

    string_identifier& string_identifier::operator+(string_identifier&& temp){
        string* pb = &*this;
        *pb={temp.get_string()};
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
            string(new_s);
            delete new_s;
            return *this;
        }
    }
    
    int string_identifier::operator>(const string_identifier&);
    int string_identifier::operator<(const string_identifier&);
};