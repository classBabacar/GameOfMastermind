#include <iostream>
#include "colors.h"
#include "mastermind.h"

using namespace std;

int main()
{
     srand(time(NULL));

     mastermind obj;
     string matcher = "rgbywcp";
     int choice;

     cout << endl;
     while (choice != 5)
     {
          cout << WHITE << "Mastermind : " << obj.stringToColor(matcher) << endl;
          cout << RED << "1 - Tutorial for Mastermind." << endl;
          cout << BLUE << "2 - Human v AI." << endl;
          cout << PINK << "3 - Donald Knuth's Algorithm. (Not implemented yet)" << endl;
          cout << GREEN << "4 - Swaszek's Algorithm. " << endl;
          cout << YELLOW << "5 - Exit." << endl;
          cout << WHITE << "Enter your choice : ";
          cin >> choice;

          cout << endl;
          switch (choice)
          {
          case 1:
               obj.differentColorsTutorial();
               break;
          case 2:
               cout << "How many pegs would you like to play with (Recommendation : 4)? : ";
               int pegs;
               cin >> pegs;
               obj.aiPlay(pegs);
               break;

          case 4:
               cout << RED << "Before we start you should know this algorithm uses ALL SEVEN COLORS!!!" << endl;
               cout << WHITE << "Which are: " << YELLOW << "rgbywpc or equivalently -> " << obj.stringToColor("rgbywpc") << endl;
               cout << endl;
               obj.swaszekAlgorithm();
          case 5:
               cout << WHITE << "Thank you for playing the game" << endl;
               cout << endl;

          default:
               break;
          }
     }
}
