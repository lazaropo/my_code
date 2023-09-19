#include <iostream>




namespace my_string{
    constexpr char kLowerA = 'a';
    constexpr char kUpperA = 'A';
    constexpr char kLowerZ = 'z';
    constexpr char kUpperZ = 'Z';

    std::ostream& print_string(const char* mpstring, const int mlenght, std::ostream& = std::cout);
    int comparator(const char* str1, const char* str2);

    class StringIdentifier;

void print_string(const char *mpstring, const int mlenght);

class String {
private:
    // My Pointer String
  char *mpstring = nullptr;
  int mlenght = 0;

protected:
    void RemoveString();

    virtual char* iFindSubstring(const char* ptr) =0;
    
    // virtual int comparator(const char* str1, const char* str2) const;
    // virtual char* remove_substring(const char* ptr);
public:
    int iGetLenght() const;
    char* iGetGtring() const;
    virtual void iSetUppercase()=0;
    virtual char* iFindSymbol(char c)=0;
    virtual void iSetLowercase()=0;
    virtual char* iFindSubstring(const char* ptr) = 0;

protected:
    void SetChar(char);
    void SetString(char*, int);

    friend std::ostream& operator<<(std::ostream& to, const String&);

    String();
    String(const char *ptr, int l);
    String(char c);
    String(const String & parent);
    ~String();

  // int iGetLenght() const;
  // void RemoveString();

  // virtual char* remove_substring(const char* ptr);
  // char *iGetGtring() const;

};

class StringIdentifier : public String {
  int CheckChar(char c);

public:
  StringIdentifier();
  StringIdentifier(char *ptr);
  StringIdentifier(char c);
  StringIdentifier(const StringIdentifier &);
  ~StringIdentifier() = default;

  void iSetUppercase();
  void iSetLowercase();
  char *iFindSymbol(char c);
  int iGetLenght() const;


    StringIdentifier& operator=(const StringIdentifier&);
    StringIdentifier& operator=(char*);
    StringIdentifier& operator+(StringIdentifier&);
    StringIdentifier& operator-(StringIdentifier&&);
    int operator>(const StringIdentifier&);
    int operator<(const StringIdentifier&);

    friend std::ostream& operator<<(std::ostream&, const StringIdentifier&);

    char *iFindSubstring(const char *ptr) const override;
  // char* remove_substring(const char* ptr) override;
};
} // namespace my_string