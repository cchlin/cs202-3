#include "node.h"


// CS202
// Cheng Lin
// chlin@pdx.edu
// Program 3
// 08/15/2021


//This is .cpp implementation file for node. The tree class has a node that represent
//the athlete and the list of the the games the athlete has. The node class has the
//athlete and the game which is a head pointer of a list of games. The order of the
//classes are the same as the .h file but the order of the functions are different.


//////////////////////////////////////////////////////////////
//
//                        game class
//
//////////////////////////////////////////////////////////////


game::game()
{
  a_sport = NULL;
  next = NULL;
}


game::game(const sport & obj)
{
  a_sport = new sport(obj);
  next = NULL;
}


game::~game()
{
  if (a_sport)
    delete a_sport;
  a_sport = NULL;
  next = NULL;
}


game & game::operator = (const game & obj)
{
  if (this == &obj) //check self assignment
    return *this;

  if (a_sport)
    delete a_sport;
  a_sport = NULL;
  next = NULL;

  a_sport = obj.a_sport;

  return *this;
}


game * & game::go_next()
{
  return next;
}


void game::connect_next(game * & connection)
{
  next = connection;
}


//check if the name passed in matches the a_sport's name
int game::is_match(const std::string & name) const
{
  if (!(a_sport == name)) //return 0 if they are not the same
    return 0;
  else
    return 1;
}


//display the data member sport using its overloaded output operator
int game::display() const
{
  if (!a_sport)
    return 0;
  std::cout << *a_sport;
  return 1;
}


//remove an athlete from the team
void game::remove_athlete_from_team(const std::string & name)
{
  soccer * ptr = dynamic_cast<soccer*>(a_sport); //check if it's a team sport first
  if (ptr)
  {
    *ptr -= name; //if it is use the overlaoded operator to remove the athlete
  }
}


int game::add_history(int year)
{
  return a_sport->add_history(year);
}


int game::add_a_medal()
{
  ++*a_sport;
  return 1;
}


//add a member to the team sport
int game::add_a_member(const athlete & obj)
{
  soccer * ptr = dynamic_cast<soccer*>(a_sport);
  if (ptr)
  {
    *ptr += obj; 
    return 1;
  } 
  else
    return 0;
}


//////////////////////////////////////////////////////////////
//
//                        node class
//
//////////////////////////////////////////////////////////////


node::node()
{
  //a_athlete = NULL;
  head = NULL;
  left = right = NULL;
}


node::node(const athlete & obj)
{
  a_athlete = obj;
  head = NULL;
  left = right = NULL;
}


node::~node()
{
  game * temp = NULL;
  while (head)
  {
    temp = head->go_next();
    delete head;
    head = temp;
  }
  head = NULL;
  left = NULL;
  right = NULL;
  //a_athlete = NULL;
}


node & node::operator = (const node & obj)
{
  if (this == &obj) //check for seflassignment
   return *this;

  a_athlete = obj.a_athlete; //copy the a_thlete object

  game * current = obj.head; //step over the list and copy
  game * dest = head;
  while (current)
  {
    dest = new game;
    dest = current;
    current = current->go_next();
    dest = dest->go_next();
  }
  
  return *this;
}


node * & node::go_left()
{
  return left;
}


node * & node::go_right()
{
  return right;
}


void node::connect_left(node * & connection)
{
  left = connection;
}


void node::connect_right(node * & connection)
{
  right = connection;
}


int node::add_a_game(sport & a_sport)
{
  return add_a_game(head, a_sport);
}


//add a game into the list. Add at the end of the list. LLL
int node::add_a_game(game * & head, sport & a_sport)
{
  if (!head)
  {
    head = new game(a_sport);
    return 1;
  }
  return add_a_game(head->go_next(), a_sport);
}


int node::remove_a_game(const std::string & name)
{
  return remove_a_game(head, name);
}


//remove a game from the list. LLL
int node::remove_a_game(game * & head, const std::string & name)
{
  if (!head)
    return 0;
  if (head->is_match(name)) //if the name matches, remove
  {
    head->remove_athlete_from_team(a_athlete.get_name());
    game * temp = head->go_next();
    delete head;
    head = temp;
    return 1;
  }
  return remove_a_game(head->go_next(), name);
}


int node::display() const
{
  std::cout << a_athlete << std::endl;
  if (!head)
    return 0;
  return display(head);
}


int node::display(game * head) const
{
  if (!head)
    return 1;
  head->display();
  return display(head->go_next());
}


//compare obj's char name and a_athlete's
int node::compare(const athlete & obj) const
{
  if (obj == a_athlete)
    return 0;
  if (obj < a_athlete) //using athlete class' operator <
    return -1;
  else
    return 1;
}


//compare with string
int node::compare(const std::string & name) const
{
  char temp[name.size() + 1];
  strcpy(temp, name.c_str());
  if (temp == a_athlete)
    return 0;
  if (temp < a_athlete)
    return -1;
  else
    return 1;
}


int node::add_a_medal(const std::string & sport_name)
{
  game * current = head;
  while (current)
  {
    if (current->is_match(sport_name))
      return current->add_a_medal();
  }
  return 0;
}


int node::add_past_history(const std::string & sport_name, int year)
{
  game * current = head;
  while (current)
  {
    if (current->is_match(sport_name))
      return current->add_history(year);
  }
  return 0;
}


int node::add_a_member(const std::string & name, const athlete & obj)
{
  game * current = head;
  while (current)
  {
    if (current->is_match(name))
      return current->add_a_member(obj);
  }
  return -1;
}


//////////////////////////////////////////////////////////////
//
//                        tree class
//
//////////////////////////////////////////////////////////////


tree::tree()
{
  root = NULL;
}


tree::~tree()
{
  remove_all(root);
}


tree & tree::operator = (const tree & obj)
{
  if (this == &obj)
    return *this;

  if (root)
    remove_all();

  copy(root, obj.root);

  return *this;
}


void tree::copy(node * & root, node * copy_from)
{
  if (!copy_from)
    return;
  root = new node;
  root = copy_from;
  copy(root->go_left(), copy_from->go_left());
  copy(root->go_right(), copy_from->go_right());
}


int tree::add_athlete(const athlete & obj)
{
  return add_athlete(root, obj);
}


int tree::add_athlete(node * & root, const athlete & obj)
{
  if (!root) //reached the end of the tree. add new node
  {
    root = new node(obj);
    return 1;
  }

  if (root->compare(obj) == -1) //call node's compare function
    return add_athlete(root->go_left(), obj);
  else
    return add_athlete(root->go_right(), obj); 
}


int tree::add_game(const std::string & name, sport & obj)
{
  return add_game(root, name, obj);
}
//recursive add_game
int tree::add_game(node * & root, const std::string & name, sport & obj)
{
  if (!root)
    return 0;
  
  if (root->compare(name) == 0)
  {
    root->add_a_game(obj);
    return 1;  
  }

  if (root->compare(name) == -1)
    return add_game(root->go_left(), name, obj);
  else
    return add_game(root->go_right(), name, obj);
}


int tree::remove_athlete(const std::string & name)
{
  return remove_athlete(root, name);
}


int tree::remove_athlete(node * & root, const std::string & name)
{
  //reached the null left/right child
  if (!root)
    return 0;

  //indocator shows if there's item removed. 1 yes and 0 is nothing is removed
  int indicator = remove_athlete(root->go_left(), name);

  //if the name of the athlete matches the name passed in then start to remove
  if (root->compare(name) == 0)
  {
    //if the node to be removed has no children
    if (!root->go_left() && !root->go_right())
    {
      delete root;
      root = NULL;
      return 1;
    }

    //removed node has only left child
    else if (root->go_left() && !root->go_right())
    {
      node * temp = root->go_left(); //store left child
      delete root;
      root = NULL;
      root = temp; //adopt left child after delete
      return 1;
    }

    //removed node has only right child
    else if (!root->go_left() && root->go_right())
    {
      node * temp = root->go_right();
      delete root;
      root = NULL;
      root = temp; //adopt right child after delete
      return 1;
    }

    //removed node has two children
    else
    {
      //keep the left child to connect later
      node * root_left_child = root->go_left();
      node * root_right_child = root->go_right();
      //store right child and use it to find successor
      node * current = root->go_right();
      node * prev = NULL;
      while (current->go_left())
      {
        prev = current;
        current = current->go_left();
      }
      delete root;
      root = NULL;
      root = current;
      if (prev)
      {
        prev->connect_left(current->go_right());
        root->connect_right(root_right_child);
      }
      else //if the current(right child of the node to be removed) has no left child
      {
        root->connect_right(current->go_right());
      }
      root->connect_left(root_left_child);
      return 1;
    }
  }
  if (indicator == 1) //if the item is found return
    return indicator;
  indicator = remove_athlete(root->go_right(), name);

  return indicator;
}


int tree::remove_game(const std::string & athlete_name, const std::string & game_name)
{
  return remove_game(root, athlete_name, game_name); 
}


int tree::remove_game(node * & root, const std::string & athlete_name,
                      const std::string & game_name)
{
  if (!root)
    return 0;

  if (root->compare(athlete_name) == 0)
  {
    if (root->remove_a_game(game_name))
      return 1;
    else
      return 0;
  }

  if (root->compare(athlete_name) < 0)
    return remove_game(root->go_left(), athlete_name, game_name);
  else
    return remove_game(root->go_right(), athlete_name, game_name);
}


int tree::remove_all()
{
  return remove_all(root);
}


int tree::remove_all(node * & root)
{
  if (!root)
    return 0;

  remove_all(root->go_left());
  remove_all(root->go_right());
  delete root;
  root = NULL;

  return 1;
}


int tree::display(const std::string & name) const
{
  if (!root)
    return -1;
  return display(root, name);
}


int tree::display(node * root, const std::string & name) const
{
  if (!root)
    return 0;
  if (root->compare(name) == 0)
  {
    root->display();
    return 1;
  }
  if (root->compare(name) < 0)
    return display(root->go_left(), name);
  else
    return display(root->go_right(), name);
}


int tree::display_all() const
{
  return display_all(root);
}


int tree::display_all(node * root) const
{
  if (!root)
    return 0;

  display_all(root->go_left());
  root->display();
  std::cout << std::endl;
  display_all(root->go_right());

  return 1;
}


int tree::check_exist(const std::string & name) const
{
  return check_exist(root, name);
}


int tree::check_exist(node * root, const std::string & name) const
{
  if (!root)
    return 0;
  if (root->compare(name) == 0)
    return 1;
  if (root->compare(name) < 0)
    return check_exist(root->go_left(), name);
  else
    return check_exist(root->go_right(), name);
}


node * & tree::add_stuff(const std::string & name)
{
  return add_stuff(root, name);
}


node * & tree::add_stuff(node * & root, const std::string & name)
{
  if (!root)
    return root;
  if (root->compare(name) == 0)
    return root;
  if (root->compare(name) < 0)
    return add_stuff(root->go_left(), name);
  else
    return add_stuff(root->go_right(), name);
}
