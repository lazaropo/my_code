#include <iostream>

constexpr char LOWER_A = 'a';
constexpr char UPPER_A = 'A';
constexpr char LOWER_Z = 'z';
constexpr char UPPER_Z = 'Z';

<<<<<<< HEAD
namespace my_string{
    std::ostream& print_string(const char* str, const int lenght, std::ostream& = std::cout);
    int comparator(const char* str1, const char* str2);

    class string_identifier;
=======
namespace my_string {
void print_string(const char *str, const int lenght);

class string {
private:
  char *str = nullptr;
  int lenght = 0;
>>>>>>> eed27bc85d40a7c49a0ed83e0bb6f183ce277a6a

protected:
<<<<<<< HEAD
    string();
    string(char* ptr);
    string(char c);
    string(const string&);
    ~string();
    
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
=======
  string();
  string(char *ptr);
  string(char c);
  string(const string &);
  ~string();
  int get_lenght() const;
  void remove_string();

  virtual char *find_substring(const char *ptr) =0;
  // virtual char* remove_substring(const char* ptr);

  char *get_string() const;
  void set_char(char);
  void set_string(char *, int);
>>>>>>> eed27bc85d40a7c49a0ed83e0bb6f183ce277a6a
};

class string_identifier : public string {
  int check_char(char c);

<<<<<<< HEAD
    void uppercase() override;
    void lowercase() override;

    char* find_symbol(char c) override;
    int get_lenght() const;
=======
public:
  string_identifier();
  string_identifier(char *ptr);
  string_identifier(char c);
  string_identifier(const string_identifier &);
>>>>>>> eed27bc85d40a7c49a0ed83e0bb6f183ce277a6a

  void uppercase();
  void lowercase();
  char *find_symbol(char c);
  int get_lenght() const;

<<<<<<< HEAD
    string_identifier& operator=(const string_identifier&);
    string_identifier& operator=(char*);
    string_identifier& operator+(string_identifier&);
    string_identifier& operator-(string_identifier&&);
    int operator>(const string_identifier&);
    int operator<(const string_identifier&);

    friend std::ostream& operator<<(std::ostream&, const string_identifier&);
=======
  ~string_identifier() = default;
>>>>>>> eed27bc85d40a7c49a0ed83e0bb6f183ce277a6a

  string_identifier &operator=(const string_identifier &);
  string_identifier &operator+(string_identifier &);
  string_identifier &operator-(string_identifier &&);
  int operator>(const string_identifier &);
  int operator<(const string_identifier &);
  std::ostream &operator<<(std::ostream &os, const string_identifier &);

  char *find_substring(const char *ptr) const override;
  // char* remove_substring(const char* ptr) override;
};
} // namespace my_string