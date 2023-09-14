#include <iostream>

#define LOWER_A 'a'
#define UPPER_A 'A'
#define LOWER_Z 'z'
#define UPPER_Z 'Z'

namespace my_string{
    void print_string(const char* str, const int lenght, std::ostream& = std::cout);
    int comparator(const char* str1, const char* str2);

    class string_identifier;

class string{
    char* str=nullptr;
    int lenght=0;
protected:
    string();
    string(char* ptr);
    string(char c);
    string(const string&);
    ~string();
    
    void remove_string();

    virtual char* find_substring(const char* ptr) const;
    // virtual int comparator(const char* str1, const char* str2) const;
    // virtual char* remove_substring(const char* ptr);
    public:
    int get_lenght() const;
    char* get_string() const;
    protected:
    void set_char(char);
    void set_string(char*, int);

    friend std::ostream& operator<<(std::ostream&, const string&);
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
    int get_lenght() const;

    ~string_identifier() = default;

    string_identifier& operator=(const string_identifier&);
    string_identifier& operator=(char*);
    string_identifier& operator+(string_identifier&);
    string_identifier& operator-(string_identifier&&);
    int operator>(const string_identifier&);
    int operator<(const string_identifier&);

    friend std::ostream& operator<<(std::ostream&, const string_identifier&);

    char* find_substring(const char* ptr) const override;
    //char* remove_substring(const char* ptr) override;
};}