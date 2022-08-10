#include <vector>
#include "athlete.h"

// CS202
// Cheng Lin
// chlin@pdx.edu
// Program 3
// 08/06/2021


//This sport.h file has 4 classes. A sport base class and three derived classes swim,
//judo, and soccer. For now, soccer class is a team sport that will contain a list of
//athletes in its data member using vector. Base class sport has a linked list of
//history that shows the year of the olympic that the athlete attended in the past


class sport
{
  public:
    sport();
    sport(char * sport_name, char * gender);
    sport(const sport & obj);
    virtual ~sport();

    //return 1 when the year is added
    int add_history(int year);

    //return 0 if no year mathced
    //return 1 if the year is deleted
    int delete_history(int year);

    //return 0 if the vector is empty
    //return 1 if at least one is displayed
    int display_all_history() const;

    //modifies the current object
    virtual sport & operator = (const sport & obj);
    //do it virtual later


    //add and subtract the medals once at a time
    //add metals only
    //prefix
    //lvalue - return by reference
    sport & operator ++ ();
    sport & operator -- ();

    //ostream isteand of display. display all information
    friend std::ostream & operator << (std::ostream & out, const sport & obj); 

    friend bool operator == (const sport * obj, const std::string & name);
    friend bool operator == (const std::string & name, const sport * obj);

  protected:
    virtual void display(std::ostream & obj) const;

  private:
    char * sport_name;
    char * gender; //male female or mix
    int medal;
    std::vector<int> year_attended;    
};


class swim : public sport
{
  public:
    swim();
    swim(char * sport_name, char * gender, char * style, const std::string & course);
    swim(const swim & obj);
    ~swim();

    swim & operator = (const swim & obj);

    //friend std::ostream & operator << (std::ostream & out, const swim & obj);

    int change_style(char * style);
    int change_course(const std::string & course);

  protected:
    void display(std::ostream & out) const;

  private:
    char * style;
    std::string course;
};


class judo : public sport
{
  public:
    judo();
    judo(char * sport_name, char * gender, const std::string & weight_classes);

    //friend std::ostream & operator << (std::ostream & out, const judo & obj);

    int change_class(const std::string & weight_class);

  protected:
    void display(std::ostream & out) const;

  private:
    std::string weight_classes;
};


class soccer : public sport
{
  public:
    soccer();
    soccer(char * sport_name, char * gender);
    soccer(const soccer & obj);
    ~soccer();

    soccer & operator = (const soccer & obj);

    //friend std::ostream & operator << (std::ostream & out, const soccer & obj);

    //operator + adds a team  member
    //- subtracts a team member
    friend soccer operator + (const soccer & obj1, const athlete & obj2);
    friend soccer operator + (const athlete & obj1, const soccer & obj2);    
    friend soccer operator + (const soccer & obj, const std::string & name);
    friend soccer operator + (const std::string & name, const soccer & obj);    
    friend soccer operator - (const soccer & obj, const std::string & name);
    friend soccer operator - (const std::string & name, const soccer & obj);    
    
    //operator += adds a team member
    //-= subtracts a team member
    //modifies the current object
    soccer & operator += (const athlete & obj);
    soccer & operator += (const std::string & name);
    soccer & operator -= (const std::string & name);

    int display_all_members() const;

    //access to a team member
    athlete & operator [] (int index);

  protected:
    void display(std::ostream & out) const;

  private:
    int num_of_members;
    std::vector<athlete> member;
};
