#include "athlete.h"


// CS202
// Cheng Lin
// chlin@pdx.edu
// Program 3
// 08/10/2021


//This is .cpp implementation file of athlete.h class. This class manages a char array
//dynamically. Most of functions in this class are equality operator overloading. Also
//this class has a get name function that is used in the node class only. 
//header/inline comments will be added later

athlete::athlete()
{
  name = NULL;
}


athlete::athlete(char * name)
{
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}


athlete::athlete(const athlete & obj)
{
  name = new char[strlen(obj.name) + 1];
  strcpy(name, obj.name);
}


athlete::~athlete()
{
  if (name)
    delete [] name;
  name = NULL;
}


athlete & athlete::operator = (const athlete & obj)
{
  if (this == &obj)
    return *this;

  if (name)
   delete [] name; 
  name = new char[strlen(obj.name) + 1];
  strcpy(name, obj.name);

  return *this;
}


std::ostream & operator << (std::ostream & out, const athlete & obj)
{
  out << obj.name;

  return out;
}


bool operator < (const athlete & obj, char * name)
{
  return (strcmp(obj.name, name) < 0); 
}
bool operator < (char * name, const athlete & obj)
{
  return (strcmp(name, obj.name) < 0);
}
bool operator < (const athlete & obj1, const athlete & obj2)
{
  return (strcmp(obj1.name, obj2.name) < 0);
}


bool operator > (const athlete & obj, char * name)
{
  return (strcmp(obj.name, name) > 0);
}
bool operator > (char * name, const athlete & obj)
{
  return (strcmp(name, obj.name) > 0);
}
bool operator > (const athlete & obj1, const athlete & obj2)
{
  return (strcmp(obj1.name, obj2.name) > 0);
}


bool operator <= (const athlete & obj, char * name)
{
  return (strcmp(obj.name, name) <= 0);
}
bool operator <= (char * name, const athlete & obj)
{
  return (obj.name > name);
}
bool operator <= (const athlete & obj1, const athlete & obj2)
{
  return (strcmp(obj1.name, obj2.name) <= 0);
}

bool operator >= (const athlete & obj, char * name)
{
  return (strcmp(obj.name, name) >= 0);
}
bool operator >= (char * name, const athlete & obj)
{
  return (obj.name < name);
}
bool operator >= (const athlete & obj1, const athlete & obj2)
{
  return (strcmp(obj1.name, obj2.name) >= 0);
}


bool operator == (const athlete & obj, char * name)
{
  return (strcmp(obj.name, name) == 0);
}
bool operator == (char * name, const athlete & obj)
{
  return (strcmp(name, obj.name) == 0);
}
bool operator == (const athlete & obj1, const athlete & obj2)
{
  return (strcmp(obj1.name, obj2.name) == 0);
}


bool operator != (const athlete & obj, char * name)
{
  return !(strcmp(obj.name, name) == 0);
}
bool operator != (char * name, const athlete & obj)
{
  return !(strcmp(name, obj.name) == 0);
}
bool operator != (const athlete & obj1, const athlete & obj2)
{
  return !(obj1.name == obj2.name);
}

std::string athlete::get_name()
{
  std::string str(name);
  return str;
}
