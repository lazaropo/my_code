#include <iostream>

namespace my_string {
constexpr char k_lower_a = 'a';
constexpr char k_upper_a = 'A';
constexpr char k_lower_z = 'z';
constexpr char k_upper_z = 'Z';

std::ostream& print_string(const char* mpstring, const int mlenght,
                           std::ostream& = std::cout);

class string_identifier;

// void print_string(const char* str, const int l, std::ostream& to = std::cout);

class string {
 private:
  // My Pointer string
  char* mp_string = nullptr;
  int m_lenght = 0;

 protected:  
  void e_remove_string();
  const char* e_get_string() const;
  void e_set_char(const char);

 public:
  string();
  string(const char c);
  string(const char* ptr, const int l);
  string(const string& parent);
  ~string();

  int i_get_lenght() const;
  char* i_get_string();
  
  void i_set_string(const char*, const int);
  int i_compare_with_string(const char* str, const int l);

  friend std::ostream& operator<<(std::ostream& to, const string&);

  virtual void i_set_uppercase() = 0;
  virtual char* i_find_symbol(char c) = 0;
  virtual void i_set_lowercase() = 0;
  virtual const char* i_find_substring(const char* ptr) const = 0;
};

class string_identifier : public string {
  int m_check_char(const char c);
  int m_comparator(const string_identifier& obj1,
                   const string_identifier& obj2);

 public:
  string_identifier();
  string_identifier(const char* ptr);
  string_identifier(const char c);
  string_identifier(const string_identifier&);
  ~string_identifier() = default;

  void i_set_uppercase();
  void i_set_lowercase();
  char* i_find_symbol(const char c);
  // int i_get_lenght() const;

  string_identifier& operator=(const string_identifier&);
  string_identifier& operator=(char*);
  string_identifier& operator+(const string_identifier&);
  string_identifier& operator-(string_identifier&&);
  int operator>(const string_identifier&);
  int operator<(const string_identifier&);

  friend std::ostream& operator<<(std::ostream&, const string_identifier&);

  const char* i_find_substring(const char* ptr) const override;
  // char* remove_substring(const char* ptr) override;
};
}  // namespace my_string