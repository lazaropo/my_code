#include <iostream.h>

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
};

class string_identifier:string{
    int check_char(char c);
    public:
    string_identifier();
    string_identifier(char* ptr);
    string_identifier(char c);
    string_identifier(const string_identifier&);
    void uppercase();
    void lowercase();
    char* find_symbol(char c);
    ~string_identifier;

    operator=(const string_identifier&);
    operator+(string_identifier&&);
    operator-(string_identifier&&);
    operator>(const string_identifier&);
    operator<(const string_identifier&);

    char* find_substring(const char* ptr) override;
    char* remove_substring(const char* ptr) override;
};