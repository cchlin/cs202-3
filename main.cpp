#include "node.h"


// CS202
// Cheng Lin
// chlin@pdx.edu
// Program 3
// 08/15/2021


//this main file has a menu to test most functions in the node class.
//And most operator overloading functions are used in those functions
//in the node class so some they are like wrapper functions for those
//operator overloading functions. All the actions are listed in the
//menu.


int main()
{

  using std::cout;
  using std::endl;
  using std::cin;
  using std::getline;

  char response = ' ';
  tree t;

  do
  {
    cout << "A. Add an athlete to the tree" << endl
         << "B. Add a game to an athlete's list" << endl
         << "C. Add one medal to a game of an athlete" << endl
         << "D. Remove an athlete" << endl
         << "E. Remove a game from an athlete" << endl
         << "F. Remove all" << endl
         << "G. Display an athelte" << endl
         << "H. Display all" << endl
         << "Q. Quit" << endl
         << "Select one: "; 
    cin >> response;
    cin.ignore(100, '\n');

    if (toupper(response) == 'A')
    {
      char ans;
      do
      {
        std::string string_name;

        cout << "Enter the name of the athlete: ";
        getline(cin, string_name); 
        
        char char_name[string_name.size() + 1];
        strcpy(char_name, string_name.c_str());  

        athlete a(char_name);

        if (!t.add_athlete(a))
          cout << "Failed to add" << endl;

        cout << "More? Y or N : ";
        cin >> ans;
        cin.ignore(100, '\n');

      } while (toupper(ans) != 'N');
    }

    if (toupper(response) == 'B')
    {
      t.display_all();
      cout << endl;
      char ans = ' ';
      do
      {
        std::string name;
        std::string gender;

        cout << "A. Swim" << endl
             << "B. Judo" << endl
             << "C. Soccer (team)" << endl
             << "Choose one type: ";
        cin >> response;
        cin.ignore(100, '\n');

        if (toupper(response) == 'A')
        {
          //sport * ptr;
          std::string athlete_name;

          cout << "Enter the name of the athlete: ";
          getline(cin, athlete_name);

          if (!t.check_exist(athlete_name))
            cout << "Athlete does not exist in the tree" << endl;
          else
          {
            name = "Swim";
            std::string style;
            std::string course;

            cout << "Enter the gender: ";
            getline(cin, gender);

            cout << "Enter the style: ";
            getline(cin, style);

            cout << "Enter the course: ";
            getline(cin, course);

            char cname[name.size() + 1];
            strcpy(cname, name.c_str());  
            char cgender[gender.size() + 1];
            strcpy(cgender, gender.c_str());  
            char cstyle[style.size() + 1];
            strcpy(cstyle, style.c_str());  
            swim s(cname, cgender, cstyle, course);

            cout << "Add past history" << endl;
            int year = 0;
            char YorN = ' ';
            do
            {
              cout << "What year: ";
              cin >> year;
              cin.ignore(100, '\n');
              s.add_history(year);
              cout << "Add more years? Y or N : ";
              cin >> YorN;
              cin.ignore(100, '\n');
            } while (toupper(YorN) != 'N');
            
            //ptr = &s;

            t.add_game(athlete_name, s);
          }
        }
        if (toupper(response) == 'B')
        {
          //sport * ptr;
          std::string athlete_name;

          cout << "Enter the name of the athlete: ";
          getline(cin, athlete_name);

          if (!t.check_exist(athlete_name))
            cout << "Athlete does not exist in the tree" << endl;
          else
          {
            name = "Judo";
            std::string weight_class;

            cout << "Enter the gender: ";
            getline(cin, gender);

            cout << "Enter the weightclass: ";
            getline(cin, weight_class);

            char cname[name.size() + 1];
            strcpy(cname, name.c_str());  
            char cgender[gender.size() + 1];
            strcpy(cgender, gender.c_str());  
            judo j(cname, cgender, weight_class);

            cout << "Add past history" << endl;
            int year = 0;
            char YorN = ' ';
            do
            {
              cout << "What year: ";
              cin >> year;
              cin.ignore(100, '\n');
              j.add_history(year);
              cout << "Add more years? Y or N : ";
              cin >> YorN;
              cin.ignore(100, '\n');
            } while (toupper(YorN) != 'N');

            //ptr = &j;
            t.add_game(athlete_name, j);
          }
        }
        if (toupper(response) == 'C')
        {
          //sport * ptr;
          std::string athlete_name;

          cout << "Enter the name of the athlete: ";
          getline(cin, athlete_name);

          if (!t.check_exist(athlete_name))
            cout << "Athlete does not exist in the tree" << endl;
          else
          {
            name = "Soccer";
            std::string weight_class;

            cout << "Enter the gender: ";
            getline(cin, gender);

            char cname[name.size() + 1];
            strcpy(cname, name.c_str());  
            char cgender[gender.size() + 1];
            strcpy(cgender, gender.c_str());  
            soccer s(cname, cgender);

            s += athlete_name;
            
            char YorN = ' ';
            do
            {
              cout << "Add a team member" << endl
                   << "Name of the team member: ";
              std::string member;
              getline(cin, member);
              s += member;
              cout << "Add more team member? Y or N : ";
              cin >> YorN;
              cin.ignore(100, '\n');
            } while (toupper(YorN) != 'N');

            //ptr = &s;
            t.add_game(athlete_name, s);

            cout << "Add past history" << endl;
            int year = 0;
            do
            {
              cout << "What year: ";
              cin >> year;
              cin.ignore(100, '\n');
              s.add_history(year);
              cout << "Add more years? Y or N : ";
              cin >> YorN;
              cin.ignore(100, '\n');
            } while (toupper(YorN) != 'N');
          }
        }
        cout << "Add more games? Y or N : ";
        cin >> ans;
        cin.ignore(100, '\n');
      } while (toupper(ans) != 'N');
    }

    if (toupper(response) == 'C')
    {
      t.display_all();
      cout << endl;

      node * obj;
      std::string athlete_name;

      cout << "Enter the name of the athlete: ";
      getline(cin, athlete_name);
      if (!t.check_exist(athlete_name))
        cout << "Athlete does not exist in the tree" << endl;
      else
        obj = t.add_stuff(athlete_name);

      cout << "-----------------" << endl
           << "obj.display()" << endl
           << "-----------------" << endl;
      obj->display();

      std::string game_name;
      cout << "Add a medal to what game: ";
      getline(cin, game_name);

      char ans= ' ';
      do
      {
        if (!obj->add_a_medal(game_name))
          cout << "The game does not exist" << endl;
        else
          obj->display();
        cout << endl;

        cout << "Add 1 more? Y or N: ";
        cin >> ans;
        cin.ignore(100, '\n');
      } while (toupper(ans) != 'N');
    }

    if (toupper(response) == 'D')
    {
      t.display_all();
      cout << endl;

      std::string athlete_name;

      cout << "Enter the name of the athlete: ";
      getline(cin, athlete_name);
      
      if (!t.remove_athlete(athlete_name))
        cout << "The athlete does not exist" << endl;
      else
        t.display_all();
      cout << endl;
    }

    if (toupper(response) == 'E')
    {
      t.display_all();
      cout << endl;
      
      std::string athlete_name;
      std::string game_name;
      
      cout << "Enter the name of the athlete and the name of the game" << endl
           << "Athelte name: ";
      getline(cin, athlete_name);
      if (!t.check_exist(athlete_name))
        cout << "Athlete does not exist in the tree" << endl;
      cout << "Name of the game: ";
      getline(cin, game_name);

      if (!t.remove_game(athlete_name, game_name))
        cout << "No matching" << endl;
      else
        t.display_all();
      cout << endl;
    }

    if (toupper(response) == 'F')
    {
      if (!t.remove_all())
        cout << "Tree is empty" << endl;
      else
        cout << "Everything is removed" << endl;
      cout << endl;
    }

    if (toupper(response) == 'G')
    {
      if (!t.display_all())
        cout << "";
      cout << endl;

      std::string athlete_name;

      cout << "Display a single athlete." << endl
           << "Enter the name: ";
      getline(cin, athlete_name);

      int i = t.display(athlete_name);
      if (i == 0)
        cout << "No matching" << endl;
      else if (i == -1)
        cout << "The tree is empty" << endl;
      else
        cout << "";
      cout << endl;
    }

    if (toupper(response) == 'H')
    {
      cout << "Display all" << endl << endl;
      
      if (!t.display_all())
        cout << "The tree is empty" << endl;
      cout << endl;
    }

  } while (toupper(response) != 'Q');



/*
  std::string s1 = "Soccer";
  char c1[s1.size() + 1];
  strcpy(c1, s1.c_str());  

  std::string s2 = "Male";
  char c2[s2.size() + 1];
  strcpy(c2, s2.c_str());  

  std::string s3 = "A Athlete 1";
  char c3[s3.size() + 1];
  strcpy(c3, s3.c_str());  
  std::string s4 = "B Athlete 2";
  char c4[s4.size() + 1];
  strcpy(c4, s4.c_str());  
  std::string s5 = "C Athlete 3";
  char c5[s5.size() + 1];
  strcpy(c5, s5.c_str());  
  std::string s6 = "D Athlete 4";
  char c6[s6.size() + 1];
  strcpy(c6, s6.c_str());  

  athlete a(c3);
  athlete a2(c4);
  athlete a3(c5);
  athlete a4(c6);


  soccer s(c1, c2);
  s = s + s3;
  s = s4 + s;
  s = s + a3;

  s.add_history(2008);
  s.add_history(2012);
  s.add_history(2016);

  ++s;
  ++s;
  ++s;
  ++s;
  ++s;

  s += a4;

  //cout << s;

  //s = s - c5;
  //s = c3 - s;

  //s -= s6;

  sport * ptr;
  ptr = &s;

  judo j(c1, c2, s3);

  j.add_history(2008);
  j.add_history(2012);
  j.add_history(2016);

  ++j;
  ++j;

  sport * ptr2;
  ptr2 = &j;

  //cout << *ptr;

  //node * n = new node(a3);
  //n->add_a_game(ptr);
  //n->remove_a_game(s1);
  //n->display();
  
  tree t;
  t.add_athlete(a2);
  t.add_athlete(a);
  t.add_athlete(a4);
  t.add_athlete(a3);

  t.add_game("C Athlete 3", ptr);
  t.add_game("C Athlete 3", ptr2);

  //t.remove_athlete("B Athlete 2");

  //t.remove_game("C Athtele 3", "Soccer");

  t.display_all();
  */


  /*
  if (!t.remove_all())
    cout << "Failed remove all" << endl;
  else
    cout << "all removed" << endl;


  cout << endl;
  
  */

  //cout << s;

  //judo test
  /*
  judo j(c1, c2, s3);

  j.add_history(2008);
  j.add_history(2012);
  j.add_history(2016);

  ++j;
  ++j;

  j.change_class("Half-lightweight");

  sport * ptr;

  ptr = &j;
  
  cout << *ptr;
  */

  //swim class test
  /*
  swim s(c1, c2, c3, "100m");

  s.add_history(2016);
  s.add_history(2012);
  s.add_history(2008);

  sport * ptr = new swim;

  ptr = &s;

  cout << *ptr;
  //cout << ptr; <- print the address
  */

  //sport class test
  /*
  sport p(c1, c2);
  p.add_history(2016);
  p.add_history(2012);
  p.add_history(2008);
  //if (!p.delete_history(2016))
  //  cout << "no match" << endl;
  //if (!p.delete_history(2012))
  //  cout << "no match" << endl;
  //if (!p.delete_history(2008))
  //  cout << "no match" << endl;
  //sport p2;
  //p2 = p;
  ++p;
  ++p;
  ++p;
  --p;
  cout << p;
  */


  return 0;
}
