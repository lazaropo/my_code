#include <iostream>

#define LOWER_A 'a'
#define UPPER_A 'A'
#define LOWER_Z 'z'
#define UPPER_Z 'Z'

namespace my_string{
class string{
    char* str;
    int lenght;
protected:
    string();
    string(char* ptr);
    string(char c);
    string(const string&);
    string(string&&);
    int get_lenght();
    void remove_string();
    ~string();

    virtual char* find_substring(const char* ptr);
    virtual char* remove_substring(const char* ptr);

    char* get_string();
};

class string_identifier:public string{
    int check_char(char c);
    public:
    string_identifier();
    string_identifier(char* ptr);
    string_identifier(char c);
    string_identifier(const string_identifier&);
    void uppercase();
    void lowercase();
    char* find_symbol(char c);
    ~string_identifier();

    string_identifier& operator=(const string_identifier&);
    string_identifier& operator+(string_identifier&&);
    string_identifier& operator-(string_identifier&&);
    int operator>(const string_identifier&);
    int operator<(const string_identifier&);

    char* find_substring(const char* ptr) override;
    char* remove_substring(const char* ptr) override;
};}