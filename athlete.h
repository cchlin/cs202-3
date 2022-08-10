#include <iostream>
#include <cstring>
#include <cctype>

// CS202
// Cheng Lin
// chlin@pdx.edu
// Program 3
// 08/09/2021


//This athlete class is a single athlete that will use in tree later. A team sport
//will also contain a list of athlete of this class. Implement relational/equality
//operators with member functions as well as non member functions for practice, and
//for now I am thinking they will be used when working with tree.


class athlete
{
  public:
    athlete();
    athlete(char * name);
    athlete(const athlete & obj);
    ~athlete();
    
    athlete & operator = (const athlete & obj);

    //athlete std::istream & operator >> (std::istream & in, char * name);

    //use this replace display function
    friend std::ostream & operator << (std::ostream & out, const athlete & obj);

    //compare by name. Used in tree data structure
    friend bool operator < (const athlete & obj, char * name);
    friend bool operator < (char * name, const athlete & obj);
    friend bool operator < (const athlete & obj1, const athlete & obj2);
    
    friend bool operator > (const athlete & obj, char * name);
    friend bool operator > (char * name, const athlete & obj);
    friend bool operator > (const athlete & obj1, const athlete & obj2);
    
    friend bool operator <= (const athlete & obj, char * name);
    friend bool operator <= (char * name, const athlete & obj);
    friend bool operator <= (const athlete & obj1, const athlete & obj2);

    friend bool operator >= (const athlete & obj, char * name);
    friend bool operator >= (char * name, const athlete & obj);
    friend bool operator >= (const athlete & obj1, const athlete & obj2);

    friend bool operator == (const athlete & obj, char * name);
    friend bool operator == (char * name, const athlete & obj);
    friend bool operator == (const athlete & obj1, const athlete & obj2);

    friend bool operator != (const athlete & obj, char * name);
    friend bool operator != (char * name, const athlete & obj);
    friend bool operator != (const athlete & obj1, const athlete & obj2);

    std::string get_name();

  private:
    char * name;
};
