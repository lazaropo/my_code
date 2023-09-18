#include <iostream>

constexpr char LOWER_A = 'a';
constexpr char UPPER_A = 'A';
constexpr char LOWER_Z = 'z';
constexpr char UPPER_Z = 'Z';


namespace my_string{
    std::ostream& print_string(const char* str, const int lenght, std::ostream& = std::cout);
    int comparator(const char* str1, const char* str2);

    class string_identifier;

namespace my_string {
void print_string(const char *str, const int lenght);

class string {
private:
  char *str = nullptr;
  int lenght = 0;


protected:
    void remove_string();

    virtual char* find_substring(const char* ptr) =0;
    
    // virtual int comparator(const char* str1, const char* str2) const;
    // virtual char* remove_substring(const char* ptr);
public:
    int get_lenght() const;
    virtual void uppercase()=0;
    virtual char* find_symbol(char c)=0;
    virtual void lowercase()=0;

    char* get_string() const;
    protected:
    void set_char(char);
    void set_string(char*, int);

    friend std::ostream& operator<<(std::ostream&, const string&);

  string();
  string(const char *ptr, int l);
  string(char c);
  string(const string & parent);
  ~string();
  // int get_lenght() const;
  // void remove_string();

    virtual char *find_substring(const char *ptr) = 0;
  // virtual char* remove_substring(const char* ptr);

  // char *get_string() const;

};

class string_identifier : public string {
  int check_char(char c);

public:
  string_identifier();
  string_identifier(char *ptr);
  string_identifier(char c);
  string_identifier(const string_identifier &);
  ~string_identifier() = default;

  void uppercase();
  void lowercase();
  char *find_symbol(char c);
  int get_lenght() const;


    string_identifier& operator=(const string_identifier&);
    string_identifier& operator=(char*);
    string_identifier& operator+(string_identifier&);
    string_identifier& operator-(string_identifier&&);
    int operator>(const string_identifier&);
    int operator<(const string_identifier&);

    friend std::ostream& operator<<(std::ostream&, const string_identifier&);

    char *find_substring(const char *ptr) const override;
  // char* remove_substring(const char* ptr) override;
};
} // namespace my_string