#include "mastermind.h"

mastermind::mastermind()
{
    attempts = 10;
    char availableColors[] = {'r', 'g', 'b', 'y', 'w', 'p', 'c'};
    for (int i = 0; i < 7; ++i)
    {
        colors[i] = availableColors[i];
    }
}
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
//uh
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
    cout << endl;
    int chooser = rand() % 3;

    cout << "Scenario #1" << endl;
    cout << RED << "Let's" << WHITE << " say you guess: y p p p or equivalently: " << stringToColor("yppp") << WHITE << endl;
    cout << "Where the secret code is: " << stringToColor("ybgr") << WHITE << endl;

    cout << "You have guessed " << YELLOW << "1 color" << WHITE << " in the correct position and ";
    cout << YELLOW << "3 colors" << WHITE << " you guessed are NOT in the secret code." << endl;

    cout << "You would see a result like the following: ";
    cout << endl;

    displayResult(3, 1, 0, 0, 4, chooser);

    cout << endl;
    cout << endl;

    cout << RED << "Note: " << WHITE << " Order of result isn't correlated to order of color, however these are both equivalent: " << endl;
    cout << endl;

    chooser = rand() % 3;
    displayResult(3, 1, 0, 0, 4, chooser);

    cout << endl;

    cout << WHITE << " Are you ready to continue (y/n) ?" << endl;
    char rsp;
    cin >> rsp;
    if (rsp == 'y')
    {
        cout << endl;
        scenarioTwo();
    }
    else
    {
        cout << endl;
        scenarioOne();
    }
}
void mastermind::scenarioTwo()
{
    cout << endl;
    int chooser = rand() % 3;

    cout << "Scenario #2" << endl;
    cout << RED << "Let's" << WHITE << " say you guess: y p p p or equivalently: " << stringToColor("yppp") << WHITE << endl;
    cout << "Where the secret code is: " << stringToColor("bygr") << WHITE << endl;

    cout << "You have guessed " << YELLOW << "1 color" << WHITE << " right but it's in the wrong position and ";
    cout << YELLOW << "3 colors" << WHITE << " you guessed again are NOT in the secret code." << endl;

    cout << "You would see a result like the following: ";
    cout << endl;

    displayResult(3, 0, 1, 0, 4, chooser);

    cout << endl;
    cout << endl;

    cout << RED << "Note: " << WHITE << " Order of result isn't correlated to order of color, however these are both equivalent: " << endl;
    cout << endl;

    chooser = rand() % 3;
    displayResult(3, 0, 1, 0, 4, chooser);

    cout << endl;

    cout << WHITE << " Are you ready to continue (y/n) ?" << endl;
    char rsp;
    cin >> rsp;
    if (rsp == 'y')
    {
        cout << endl;
        scenarioThree();
    }
    else
    {
        cout << endl;
        scenarioTwo();
    }
}

void mastermind::scenarioThree()
{
    cout << endl;
    int chooser = rand() % 3;

    cout << "Scenario #3" << endl;
    cout << RED << "Let's" << WHITE << " say you guess: b p y r or equivalently: " << stringToColor("bpyr") << WHITE << endl;
    cout << "Where the secret code is: " << stringToColor("bygr") << WHITE << endl;

    cout << "You have guessed " << YELLOW << "2 colors" << WHITE << " in the right position and ";
    cout << YELLOW << "1 color" << WHITE << " is NOT in the secret code and ";
    cout << YELLOW << "1 color" << WHITE << " is in the wrong position." << endl;

    cout << "Can you imagine what the result would look like, Once you are ready?(y/n) " << endl;
    char ans;
    cin >> ans;
    if (ans == 'y')
    {
        displayResult(1, 2, 1, 0, 4, chooser);

        cout << endl;
        cout << endl;

        cout << RED << "Note: " << WHITE << " Order of result isn't correlated to order of color, however these are both equivalent: " << endl;
        cout << endl;
        chooser = rand() % 3;
        displayResult(1, 2, 1, 0, 4, chooser);
        cout << endl;
    }
    else
    {
        return scenarioThree();
    }

    cout << WHITE << "Now you should be ready to play mastermind. Thank You." << endl;
    //Have a function call to the menu
}

void mastermind::displayResult(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize, int chooser)
{
    if (chooser == 0)
    {
        resultPatternOne(notInSecret, correctlyPlaced, incorrectlyPlaced, counter, colorSize);
    }
    else if (chooser == 1)
    {
        resultPatternTwo(notInSecret, correctlyPlaced, incorrectlyPlaced, counter, colorSize);
    }
    else
    {
        resultPatternThree(notInSecret, correctlyPlaced, incorrectlyPlaced, counter, colorSize);
    }
}
void mastermind::resultPatternOne(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize)
{
    if (counter % 2 == 0)
    {
        cout << BLUE << " + ";
        if (counter >= 2)
        {
            if (colorSize == 0)
            {
                return;
            }
            cout << endl;
            cout << BLUE << " + ";
            counter = 0;
        }
    }

    if (notInSecret > 0) //
    {
        cout << WHITE << " O ";
        return resultPatternOne(notInSecret - 1, correctlyPlaced, incorrectlyPlaced, counter + 1, colorSize - 1);
    }
    else if (correctlyPlaced > 0)
    {
        cout << GREEN << " O ";
        return resultPatternOne(notInSecret, correctlyPlaced - 1, incorrectlyPlaced, counter + 1, colorSize - 1);
    }
    else if (incorrectlyPlaced > 0)
    {
        cout << RED << " O ";
        return resultPatternOne(notInSecret, correctlyPlaced, incorrectlyPlaced - 1, counter + 1, colorSize - 1);
    }
}

void mastermind::resultPatternTwo(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize)
{
    if (counter % 2 == 0)
    {
        cout << BLUE << " + ";
        if (counter >= 2)
        {
            if (colorSize == 0)
            {
                return;
            }
            cout << endl;
            cout << BLUE << " + ";
            counter = 0;
        }
    }

    if (correctlyPlaced > 0)
    {
        cout << GREEN << " O ";
        return resultPatternTwo(notInSecret, correctlyPlaced - 1, incorrectlyPlaced, counter + 1, colorSize - 1);
    }
    else if (incorrectlyPlaced > 0)
    {
        cout << RED << " O ";
        return resultPatternTwo(notInSecret, correctlyPlaced, incorrectlyPlaced - 1, counter + 1, colorSize - 1);
    }
    else if (notInSecret > 0) //
    {
        cout << WHITE << " O ";
        return resultPatternTwo(notInSecret - 1, correctlyPlaced, incorrectlyPlaced, counter + 1, colorSize - 1);
    }
}

void mastermind::resultPatternThree(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize)
{
    if (counter % 2 == 0)
    {
        cout << BLUE << " + ";
        if (counter >= 2)
        {
            if (colorSize == 0)
            {
                return;
            }
            cout << endl;
            cout << BLUE << " + ";
            counter = 0;
        }
    }

    if (incorrectlyPlaced > 0)
    {
        cout << RED << " O ";
        return resultPatternThree(notInSecret, correctlyPlaced, incorrectlyPlaced - 1, counter + 1, colorSize - 1);
    }
    else if (notInSecret > 0) //
    {
        cout << WHITE << " O ";
        return resultPatternThree(notInSecret - 1, correctlyPlaced, incorrectlyPlaced, counter + 1, colorSize - 1);
    }
    else if (correctlyPlaced > 0)
    {
        cout << GREEN << " O ";
        return resultPatternThree(notInSecret, correctlyPlaced - 1, incorrectlyPlaced, counter + 1, colorSize - 1);
    }
}

//Making sure the string has valid colors
bool mastermind::checkValidColors(string userGuess)
{
    int totalColors = 7;
    bool tracker;
    for (int i = 0; i < userGuess.size(); ++i)
    {
        tracker = false;
        for (int j = 0; j < totalColors; ++j)
        {
            if (userGuess[i] == colors[j])
            {
                tracker = true;
            }
        }
        if (tracker == false)
        {
            return false;
        }
    }
    return true;
}

//Parsing the users guess to make sure it doesnt debunk
string mastermind::authenticateGuess(int totalColors)
{
    cout << WHITE << "What do you think the secret is : ";
    string userGuess;
    cin >> userGuess;

    cout << endl;
    //Filer longer input than string also having valid colors in string
    while ((!checkValidColors(userGuess)) || (userGuess.size() != totalColors))
    {
        cout << "Sorry that was an invalid input. " << RED << "Try again." << endl;
        cout << WHITE << "What do you think the secret is : ";
        cin >> userGuess;
        cout << endl;
    }

    cout << "Your choice: " << stringToColor(userGuess);
    cout << WHITE << "Are you comfortable with this choice? (y/n) : ";
    char rsp;
    cin >> rsp;

    if (tolower(rsp) == 'y')
    {
        return userGuess;
    }
    else
    {
        string tmp = authenticateGuess(totalColors);
    }
}
//Goals:
//1 : Mkae a display for guessed color and result  in colors
//2 : Keep on adding guesses visually pleasing
void mastermind::aiPlay(int totalColors)
{
    int start = 0;
    string secretCode = generateSecret(totalColors); // Ai Chosen Guess
    string userGuess;                                // Storing user guesses

    userGuess = authenticateGuess(totalColors);
    //while (start < attempts)
    ///{
    //     cout << start << endl;
    //     start++;
    //}
}
string mastermind::generateSecret(int totalColors)
{
    string secretCode;
    int random;

    for (int i = 0; i < totalColors; ++i)
    {
        random = rand() % 7;
        secretCode += colors[random];
    }
    cout << "secret code is " << secretCode << endl;
    // cout << "attempts" << attempts << endl;
    stringToColor(secretCode);
    return secretCode;
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