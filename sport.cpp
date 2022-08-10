#include "sport.h"


// CS202
// Cheng Lin
// chlin@pdx.edu
// Program 3
// 08/09/2021


//this .cpp sport file has 4 classes just like its .h file. The order of the classes
//are the same but the order of the functions are different. The sport calss is the
//base class, and swim, judo, and soccer "is a" sport. Sport and swim classes
//manage dynamic memory char array and soccer class has vector container.
//header comments will be added later



///////////////////////////////////////////////////////////////////
//
//                        sport base class
//
///////////////////////////////////////////////////////////////////

sport::sport()
{
  sport_name = NULL;
  gender = NULL;
  medal = 0;
}


sport::sport(char * sport_name, char * gender)
{
  this->sport_name = new char[strlen(sport_name) + 1];
  strcpy(this->sport_name, sport_name);

  this->gender = new char[strlen(gender) + 1];
  strcpy(this->gender, gender);

  medal = 0;
}


//copy constructor
sport::sport(const sport & obj)
{
 // if (sport_name)
 //   delete [] sport_name;
 // if (gender)
 //   delete [] gender;

  sport_name = new char[strlen(obj.sport_name) + 1];
  strcpy(sport_name, obj.sport_name);
  gender = new char[strlen(obj.gender) + 1];
  strcpy(gender, obj.gender);

  medal = obj.medal;

  year_attended.clear();
  year_attended.assign(obj.year_attended.begin(), obj.year_attended.end());
}


sport::~sport()
{
  if (sport_name)
    delete [] sport_name;
  sport_name = NULL;
  if (gender)
    delete [] gender;
  gender = NULL;

  year_attended.clear();
}


int sport::add_history(int year)
{
  //add exception later
  year_attended.push_back(year); 
  return 1;
}


int sport::delete_history(int year)
{
  for (unsigned int i = 0; i < year_attended.size(); ++i)
  {
    if (year == year_attended[i]) //if the year matches
    {
      year_attended.erase(year_attended.begin() + i); //delete it
      return 1;
    }
  }
  return 0;
}


int sport::display_all_history() const
{
  if(year_attended.empty()) //check if vector is empty first
    return 0;

  //if not empty ouput all of them
  for (unsigned int i = 0; i < year_attended.size(); ++i)
    std::cout << year_attended[i] << " ";
  std::cout << std::endl;
  return 1;
}


sport & sport::operator = (const sport & obj)
{
  if (this == &obj)
    return *this;

  if (sport_name)
    delete [] sport_name;
  sport_name = new char[strlen(obj.sport_name) + 1];
  strcpy(sport_name, obj.sport_name);

  if (gender)
    delete [] gender;
  gender = new char[strlen(obj.gender) + 1];
  strcpy(gender, obj.gender);

  medal = obj.medal;

  year_attended.clear();
  year_attended.assign(obj.year_attended.begin(), obj.year_attended.end());

  return *this;
}


sport & sport::operator ++ ()
{
  medal += 1;
  return *this; 
}


sport & sport::operator -- ()
{
  if (medal != 0)
    medal -= 1;
  return *this;
}


std::ostream & operator << (std::ostream & out, const sport & obj)
{
  obj.display(out);

  return out;
}


bool operator == (const sport * obj, const std::string & name)
{
  char temp[name.size() + 1];
  strcpy(temp, name.c_str());

  return (strcmp(obj->sport_name, temp) == 0);
}


bool operator == (const std::string & name, const sport * obj)
{
  char temp[name.size() + 1];
  strcpy(temp, name.c_str());

  return (strcmp(temp, obj->sport_name) == 0);
}


void sport::display(std::ostream & out) const
{
  out << "Game: " << sport_name << std::endl
      << "Gender: " << gender << std::endl
      << "Number of medals: " << medal << std::endl
      << "Past attended: ";
  if (!display_all_history())
    out << "No history" << std::endl;
}


///////////////////////////////////////////////////////////////////
//
//                        swim class
//
///////////////////////////////////////////////////////////////////


swim::swim()
{
  style = NULL;
}


swim::swim(char * sport_name, char * gender, char * style, const std::string & course) :
           sport(sport_name, gender), course(course)
{
  this->style = NULL;
  change_style(style);
}


//copy constructor
swim::swim(const swim & obj) : sport(obj), course(obj.course)
{
  change_style(obj.style);
}


swim::~swim()
{
  if (style)
    delete [] style; //deallocate the char *
  style = NULL;
}


swim & swim::operator = (const swim & obj)
{
  if (this == &obj)
    return *this;

  sport::operator=(obj);

  change_style(obj.style);

  course = obj.course;

  return *this;  
}


/*
std::ostream & operator << (std::ostream & out, const swim & obj)
{
  obj.display(out);

  return out;
}
*/


void swim::display(std::ostream & out) const
{
  sport::display(out);

  out << "Style: " << style << std::endl
      << "Course: " << course << std::endl;
}


int swim::change_style(char * style)
{
  if (this->style)
    delete [] this->style;
  this->style = new char[strlen(style) + 1];
  strcpy(this->style, style);
  return 1;
}


int swim::change_course(const std::string & course)
{
  this->course = course;
  return 1;
}


///////////////////////////////////////////////////////////////////
//
//                        judo class
//
///////////////////////////////////////////////////////////////////
judo::judo()
{
}


judo::judo(char * sport_name, char * gender, const std::string & weight_classes) : 
           sport(sport_name, gender), weight_classes(weight_classes)
{
}


int judo::change_class(const std::string & weight_classes)
{
  if (weight_classes.empty())
    return 0;
  this->weight_classes = weight_classes;
  return 1;
}


void judo::display(std::ostream & out) const
{
  sport::display(out);

  out << "Weight class: " << weight_classes << std::endl;
}


///////////////////////////////////////////////////////////////////
//
//                        soccer class
//
///////////////////////////////////////////////////////////////////
soccer::soccer()
{
  num_of_members = 0;
}


soccer::soccer(char * sport_name, char * gender) : sport(sport_name, gender)
{
  num_of_members = 0;
}


soccer::soccer(const soccer & obj) : sport(obj)
{
  num_of_members = obj.num_of_members;

  member.clear();
  member.assign(obj.member.begin(), obj.member.end());
}


soccer::~soccer()
{
  member.clear();  
}


soccer & soccer::operator = (const soccer & obj)
{
  if (this == &obj)
    return *this;

  sport::operator=(obj);

  num_of_members = obj.num_of_members;

  member.clear();
  member.assign(obj.member.begin(), obj.member.end());

  return *this;
}

soccer operator + (const soccer & obj1, const athlete & obj2)
{
  soccer temp(obj1);

  temp.member.push_back(obj2);
  temp.num_of_members += 1;

  return temp;
}
soccer operator + (const athlete & obj1, const soccer & obj2)
{
  soccer temp(obj2);

  temp.member.push_back(obj1);
  temp.num_of_members += 1;

  return temp;
}

soccer operator + (const soccer & obj, const std::string & name)
{
  char c[name.size() + 1];
  strcpy(c, name.c_str());
  athlete a(c);

  soccer temp(obj);

  temp.member.push_back(a);
  temp.num_of_members += 1;

  return temp; 
}

soccer operator + (const std::string & name, const soccer & obj)
{
  return  (obj + name); 
}


soccer operator - (const soccer & obj, const std::string & name)
{
  soccer temp(obj);

  char c[name.size() + 1];
  strcpy(c, name.c_str());

  for (unsigned int i = 0; i < temp.member.size(); ++i)
  {
    if (temp.member[i] == c)
    {
      //delete temp.member[i];
      temp.member.erase(temp.member.begin() + i);
      temp.num_of_members -= 1;
    }
  }
  return temp;
}
soccer operator - (const std::string & name, const soccer & obj)
{
  return (obj - name);
}


soccer & soccer::operator += (const athlete & obj)
{
  member.push_back(obj);
  num_of_members += 1;

  return *this;
}

soccer & soccer::operator += (const std::string & name)
{
  char c[name.size() + 1];
  strcpy(c, name.c_str());
  athlete a(c);
  member.push_back(a);
  num_of_members += 1;
  return *this;
}


soccer & soccer::operator -= (const std::string & name)
{
  char c[name.size() + 1];
  strcpy(c, name.c_str());
  
  for (unsigned int i = 0; i < member.size(); ++i)
  {
    if (member[i] == c)
    {
      member.erase(member.begin() + i);
      num_of_members -= 1;
    }
  }
  return *this;
}


int soccer::display_all_members() const
{
  if (member.empty()) //return 0 if the vector is empty
    return 0;

  //if vector has data in it display and return 1 after finished
  for (unsigned int i = 0; i < member.size(); ++i)
    std::cout << member[i] << std::endl;
  return 1;
}


athlete & soccer::operator [] (int index)
{
  return member[index];
}


void soccer::display(std::ostream & out) const
{
  sport::display(out);
  
  if (!display_all_members())
    out << "No members." << std::endl;
  else
    out << "Total " << num_of_members << " members." << std::endl;
}

