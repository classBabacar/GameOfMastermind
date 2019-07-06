#include <iostream>
#include "colors.h"
#include "mastermind.h"

using namespace std;

// void stringToColor(string matcher);

int main()
{
     srand(time(NULL));

     mastermind obj;
     string matcher = "rgbywcp";

     cout << "GAME NOT COMPLETE YET!!!!" << endl;
     int choice;
     while (choice != 4)
     {
          cout << WHITE << "Mastermind : " << obj.stringToColor(matcher) << endl;
          cout << RED << "1 - Tutorial for Mastermind." << endl;
          cout << BLUE << "2 - Human v AI." << endl;
          cout << PINK << "3 - Donald Knuth AI." << endl;
          cout << YELLOW << "4 - Exit." << endl;
          cout << WHITE << "Enter your choice : ";
          cin >> choice;

          cout << endl;
          switch (choice)
          {
          case 1:
               obj.differentColorsTutorial();
               break;
          case 2:
               obj.aiPlay(4); // Right now im going to hard code this number but change it eventually
               break;

          default:
               break;
          }
     }
     /*cout << WHITE << "Welcome to " << YELLOW << "Mastermind!!!" << endl;
    cout << WHITE << endl;*/
     // cout << endl;
     // cout << "----------" << endl;
     // cout << "+ " << GREEN << " O " << GREEN << " O " << WHITE << " + " << endl;
     // cout << "+ " << GREEN << " O " << WHITE << " O " << WHITE << " + " << endl;
     // cout << "----------" << endl;
     // cout << endl;
     //cout << WHITE << "hi" << endl;*/
}
