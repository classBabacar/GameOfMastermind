#include "mastermind.h"

void mastermind::differentColorsTutorial()
{
    cout << "There are 7 different colors " << endl;
    cout << "Red: " << RED << "O" << WHITE << endl;
    cout << "Green: " << GREEN << "O" << WHITE << endl;
    cout << "Blue: " << BLUE << "O" << WHITE << endl;
    cout << "Yellow: " << YELLOW << "O" << WHITE << endl;
    cout << "White: " << WHITE << "O" << WHITE << endl;
    cout << "Pink: " << PINK << "O" << WHITE << endl;
    cout << "Cyan: " << CYAN << "O" << WHITE << endl;

    cout << "Are you ready to move on (y/n)?";
    char rsp;
    cin >> rsp;

    if (rsp == 'y')
    {
        cout << endl;
        userGuideline();
    }
    else
    {
        cout << endl;
        differentColorsTutorial();
    }
}

void mastermind::userGuideline()
{
    cout << YELLOW << "The idea to this game is to guess a secret code of 4 or more colors in a limited number of rounds." << endl;
    cout << GREEN << "There are 2 ways a secret code can be made : " << endl;
    cout << BLUE << "1)" << WHITE << " User generated secret code. " << endl;
    cout << RED << "2)" << WHITE << " Ai generated secret code. " << endl;
    cout << endl;
    cout << "In the case that a user generated a secret code that was: y b g r " << endl;
    cout << "It would be Yellow Blue Green Red or equivalently: " << stringToColor("ybgr") << WHITE << endl;
    cout << "Now let's proceed to the scenarios of guessing are you ready to continue (y/n) ?" << endl;
    char rsp;
    cin >> rsp;
    if (rsp == 'y')
    {
        cout << endl;
        scenarioOne();
    }
    else
    {
        cout << endl;
        userGuideline();
    }
}

void mastermind::scenarioOne()
{
    cout << RED << "Let's" << WHITE << " say you guess: y p p p or equivalently: " << stringToColor("yppp") << WHITE << endl;
    cout << "Where the secret code is: " << stringToColor("ybgr") << WHITE << endl;

    cout << "You have guessed " << YELLOW << "1 color" << WHITE << " in the correct position and ";
    cout << YELLOW << "3 colors" << WHITE << " are NOT in the secret code." << endl;
    cout << "You would see a result like this." << displayResult(0, 1, 3);
}

string mastermind::displayResult(int notInSecret, int correctlyPlaced, int incorrectlyPlaced)
{
    cout << endl;
    cout << "----------" << endl;

    //Correctly Placed
    for (int i = 0; i < correctlyPlaced; ++i)
    {
        if (i % 2 == 0)
        {
            cout << WHITE << "+ ";
        }
        cout << GREEN << " O ";
        if (i % 2 == 1)
        {
            cout << WHITE << " + " << endl;
        }
    }

    //Not in the secret code
    for (int i = correctlyPlaced; i < notInSecret + correctlyPlaced; ++i)
    {
        if (i % 2 == 0)
        {
            cout << WHITE << "+ ";
        }
        cout << WHITE << " O ";
        if (i % 2 == 1)
        {
            cout << WHITE << " + " << endl;
        }
    }

    //Not incorrencly placed
    for (int i = correctlyPlaced + notInSecret; i < notInSecret + correctlyPlaced + incorrectlyPlaced; ++i)
    {
        if (i % 2 == 0)
        {
            cout << WHITE << "+ ";
        }
        cout << RED << " O ";
        if (i % 2 == 1)
        {
            cout << WHITE << " + " << endl;
        }
    }

    cout << "----------" << endl;

    return "";
}
string mastermind::stringToColor(string password)
{

    for (int i = 0; i < password.length(); ++i)
    {
        char holder = password[i];
        switch (holder)
        {
        case 'r':
            cout << RED << "O ";
            break;
        case 'g':
            cout << GREEN << "O ";
            break;
        case 'b':
            cout << BLUE << "O ";
            break;
        case 'y':
            cout << YELLOW << "O ";
            break;
        case 'w':
            cout << WHITE << "O ";
            break;
        case 'c':
            cout << CYAN << "O ";
            break;
        case 'p':
            cout << PINK << "O ";
            break;
        default:
            break;
        }
    }
    cout << endl;
    return "";
}