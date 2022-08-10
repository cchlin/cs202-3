#include "sport.h"


// CS202
// Cheng Lin
// chlin@pdx.edu
// Program 3
// 08/14/2021


//This node.h file so far has the game class and the node class implemented. The tree
//class is still working in progress. There's no inheritance in this data structure
//file. tree class "has a" node, and the node class "has a" LLL of game class. A game
//class stores a single sport, and a node class stores a athlete and a list of sports


class game
{
  public:
    game();
    game(const sport & obj);
    ~game();

    game & operator = (const game & obj);

    game * & go_next();

    void connect_next(game * & connection);

    //check if the sport's name mathces
    //return 0 if they do not match and 1 if they match
    int is_match(const std::string & name) const;
    int display() const;
    
    //remove from the team sport
    void remove_athlete_from_team(const std::string & name);

    int add_a_medal();
    int add_history(int year);

    //return 0 if this is not a team sport
    int add_a_member(const athlete & obj);

  private:
    sport * a_sport;
    game * next; 
};


class node
{
  public:
    node();
    node(const athlete & obj);
    ~node();

    node & operator = (const node & obj);

    node * & go_left();
    node * & go_right();

    void connect_left(node * & connection);
    void connect_right(node * & connection);

    int add_a_game(sport & a_sport);

    //remove a game from the list.
    //return 0 if no matching game
    int remove_a_game(const std::string & name);

    int display() const;

    //compare the if the name passed in is smaller or greater than athlete's
    //return -1 if the name is smaller
    //return 0 if the name is equal
    //return 1 if it is greater
    int compare(const athlete & obj) const;
    int compare(const std::string & name) const;

    //return 0 if no sport is found
    int add_a_medal(const std::string & sport_name);

    //return 0 if no sport is found
    int add_past_history(const std::string & sport_name, int year);

    //return 0 if the sport to search is not a team sport 
    //return -1 if not sport is found
    int add_a_member(const std::string & name, const athlete & obj);

  private:
    athlete a_athlete;
    game * head;
    node * left;
    node * right;

    int add_a_game(game * & head, sport & a_sport);
    int remove_a_game(game * & head, const std::string & name);
    int display(game * head) const;
};


//Binary search tree
class tree
{
  public:
    tree();
    ~tree();

    //copy the tree
    tree & operator = (const tree & obj);

    //add an athlete
    int add_athlete(const athlete & obj);
    
    //add a game to an athlete
    //argument name is the athlete's name
    //return 0 if no athlete is found
    int add_game(const std::string & athlete_name, sport & obj); 

    //remove an athlete by searching their name in tree
    //return 0 if no athlete is found
    //return 1 if successfully removed
    int remove_athlete(const std::string & name); 

    //remove a game from an athlete
    //return 0 if no matching game found otherwise return 1
    int remove_game(const std::string & athlete_name, const std::string & game_name);

    //remove everything in tree
    //return 0 if tree is empty
    //return 1 if done
    int remove_all();

    //display an athlete by searching their name in tree
    //return -1 if the root is empty
    //return 0 if no matching item
    //return 1 if displayed
    int display(const std::string & name) const;

    //display the whole tree
    //return 0 if the tree is empty otherwise return 1
    int display_all() const;

    int check_exist(const std::string & name) const;
    node * & add_stuff(const std::string & name);
    node * current;

  private:
    node * root;

    //recursions
    int add_athlete(node * & root, const athlete & obj);
    int add_game(node * & root, const std::string & name, sport & obj);
    int remove_athlete(node * & root, const std::string & name);
    int remove_game(node * & root, const std::string & athlete_name,
                    const std::string & game_name);
    int remove_all(node * & root);
    int display(node * root, const std::string & name) const;
    int display_all(node * root) const;

    void copy(node * & root, node * copy_from);
    node * & add_stuff(node * & root, const std::string & name);
    int check_exist(node * root, const std::string & name) const;
    
};
