#include "classes.h"

class string{
    char* str;
    int lenght=0;
protected:
    string():
    str(new char[0]), lenght(0){}

    string(char* ptr)
        : string(){
        int i = 0;
        do{
            str[i]=ptr[i];
        }while(str[i++]);
        lenght+=--i;
    }

    string(char c):{
        if(!lenght){
            string();
        }
        str[lenght]=c;
        str[++lenght]='\0';
    }

    string(const string& mom):
    str(mom.str), lenght(mom.lenght){}


    int get_lenght(){
        return lenght;
    }

    void remove_string(){
        delete str;
        str = nullptr;
        lenght=0;
    }

    ~string(){
        delete str;
    }
};

class string_identifier:public string{
    int check_char(char c){
        return ((c > 'a' && c < 'z')||(c>'A'&&c<'Z')||c=='_')?0:1;
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

    string_identifier(const string_identifier& dad)
        :string(dad){}

    void uppercase(){
        for(int i=0; i<lenght:++i){
            string.str[i]= string.str[i]>'Z': string.str[i]-delta:string.str[i];
        }
        return;
    }

    void lowercase(){
        for(int i=0; i<lenght:++i){
            string.str[i]= string.str[i]<'a': string.str[i]+delta:string.str[i];
        }
        return;
    }

    char* find_symbol(char c){
        char* ptr=string.str;
        while(*ptr!=c){
            ptr++;
        }
        return ptr;
    }

    ~string_identifier{
        delete string;
    };

    operator=(const string_identifier& init){
        string_identifier(init);
        return init;
    };

    operator+(string_identifier&& temp){
        string(temp.string.str);
        return *this;
    };

    operator-(string_identifier&& tmp){
        char* here = find_substring(tmp.string.str);
        if(here){
            char* ptr = string.str, new_s = new char[get_lenght()-tmp.get_lenght()];
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
    
    operator>(const string_identifier&);
    operator<(const string_identifier&);
};