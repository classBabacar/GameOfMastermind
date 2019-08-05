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

//************************************************************************
// Function: userGuideline()
// Purpose:  Explaining game
//************************************************************************
void mastermind::userGuideline()
{
    cout << YELLOW << "The idea to this game is to guess a secret code of 4 or more colors in a limited number of rounds." << endl;
    cout << GREEN << "There are 2 ways a secret code can be made : " << endl;
    cout << BLUE << "1)" << WHITE << " User generated secret code. " << endl;
    cout << RED << "2)" << WHITE << " Ai generated secret code. " << endl;
    cout << endl;
    cout << "In the case that a user generated a secret code that was: y b g r " << endl;
    cout << "It would be Yellow Blue Green Red or equivalently: " << stringToColor("ybgr") << WHITE << endl
         << endl;
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

//************************************************************************
// Function: scenarioOne()
// Purpose:  A given game scenario of the game to help teach
//************************************************************************
void mastermind::scenarioOne()
{
    cout << endl;
    int chooser = rand() % 3;

    cout << "Scenario #1" << endl;
    cout << RED << "Let's" << WHITE << " say you guess: y p p p or equivalently: " << stringToColor("yppp") << WHITE << endl;
    cout << "Where the secret code is: " << stringToColor("ybgr") << WHITE << endl
         << endl;

    cout << "You have guessed " << YELLOW << "1 color" << WHITE << " in the correct position and ";
    cout << YELLOW << "3 colors" << WHITE << " you guessed are NOT in the secret code." << endl;

    cout << "You would see a result like the following: ";
    cout << endl;

    displayResult(3, 1, 0, 0, 4, chooser);

    cout << endl;
    cout << endl;

    cout << RED << "Note: " << WHITE << "Order of result isn't correlated to order of color, so these are both equivalent: " << endl;
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

//************************************************************************
// Function: scenarioTwo()
// Purpose:  A given game scenario of the game to help teach
//************************************************************************
void mastermind::scenarioTwo()
{
    cout << endl;
    int chooser = rand() % 3;

    cout << "Scenario #2" << endl;
    cout << RED << "Let's" << WHITE << " say you guess: y p p p or equivalently: " << stringToColor("yppp") << WHITE << endl;
    cout << "Where the secret code is: " << stringToColor("bygr") << WHITE << endl
         << endl;

    cout << "You have guessed " << YELLOW << "1 color" << WHITE << " right but it's in the wrong position and ";
    cout << YELLOW << "3 colors" << WHITE << " you guessed are NOT in the secret code." << endl;

    cout << "You would see a result like the following: ";
    cout << endl;

    displayResult(3, 0, 1, 0, 4, chooser);

    cout << endl;
    cout << endl;

    cout << RED << "Note: " << WHITE << "Order of result isn't correlated to order of color, so these are both equivalent: " << endl;
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

//************************************************************************
// Function: scenarioThree()
// Purpose:  A given game scenario of the game to help teach
//************************************************************************
void mastermind::scenarioThree()
{
    cout << endl;
    int chooser = rand() % 3;

    cout << "Scenario #3" << endl;
    cout << RED << "Let's" << WHITE << " say you guess: b p y r or equivalently: " << stringToColor("bpyr") << WHITE << endl;
    cout << "Where the secret code is: " << stringToColor("bygr") << WHITE << endl
         << endl;

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

        cout << RED << "Note: " << WHITE << "Order of result isn't correlated to order of color, so these are both equivalent: " << endl;
        cout << endl;
        chooser = rand() % 3;
        displayResult(1, 2, 1, 0, 4, chooser);
        cout << endl;
    }
    else
    {
        return scenarioThree();
    }
    cout << endl;
    cout << WHITE << "Now you should be ready to play mastermind. Thank You." << endl;
    cout << endl;
}

//************************************************************************
// Function: displayResult(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize, int chooser)
// Purpose:  This function choose 1 of 3 output sequences that are left to random.
//           1. This helps with users trying to read game patterns that I set through algorithms
//           2. A user playing the game can't try to edge on the game
//************************************************************************
void mastermind::displayResult(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize, int randomizer)
{
    if (randomizer == 0)
    {
        resultPatternOne(notInSecret, correctlyPlaced, incorrectlyPlaced, counter, colorSize);
    }
    else if (randomizer == 1)
    {
        resultPatternTwo(notInSecret, correctlyPlaced, incorrectlyPlaced, counter, colorSize);
    }
    else
    {
        resultPatternThree(notInSecret, correctlyPlaced, incorrectlyPlaced, counter, colorSize);
    }
}

//************************************************************************
// Function: equalDisplay(counter by reference, total number of pegs used )
// Purpose:  Function to display the results in a normal fashion
//************************************************************************
void mastermind::setDisplay(int &counter, int colorSize){
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
}

//Output #1
void mastermind::resultPatternOne(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize)
{
    setDisplay(counter,colorSize);
    if (notInSecret > 0) 
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

//Output #2
void mastermind::resultPatternTwo(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize)
{
    setDisplay(counter,colorSize);
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
    else if (notInSecret > 0)
    {
        cout << WHITE << " O ";
        return resultPatternTwo(notInSecret - 1, correctlyPlaced, incorrectlyPlaced, counter + 1, colorSize - 1);
    }
}

//Output #3
void mastermind::resultPatternThree(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize)
{
    setDisplay(counter,colorSize);
    if (incorrectlyPlaced > 0)
    {
        cout << RED << " O ";
        return resultPatternThree(notInSecret, correctlyPlaced, incorrectlyPlaced - 1, counter + 1, colorSize - 1);
    }
    else if (notInSecret > 0)
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

//************************************************************************
// Function: checkValidColors(string userGuess)
// Purpose:  Making sure the user guess consists of only valid colors
//************************************************************************
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

//************************************************************************
// Function: authenticateGuess(int totalColors)
// Purpose:  The user input packaged that also verifies if their guess is legal
//************************************************************************
string mastermind::authenticateGuess(int totalColors)
{
    helpUserSeeColors(totalColors);
    cout << WHITE << "What do you think the secret is : ";
    string userGuess;
    cin >> userGuess;

    cout << endl;
    while ((!checkValidColors(userGuess)) || (userGuess.size() != totalColors))
    {
        helpUserSeeColors(totalColors);
        cout << "Sorry, that's an invalid input. " << RED << "Try again." << endl;
        cout << WHITE << "What do you think the secret is : ";
        cin >> userGuess;
        cout << endl;
    }

    cout << "Your choice: " << stringToColor(userGuess) << endl;
    cout << WHITE << "Are you comfortable with this choice? (y/n) : ";
    char rsp;
    cin >> rsp;

    if (tolower(rsp) == 'y')
    {
        return userGuess;
    }
    else
    {
       return authenticateGuess(totalColors);
    }
}

//************************************************************************
// Function: displayFeedback(int totalColors)
// Purpose:  Displaying all of the users previous guesses
//************************************************************************
void mastermind::displayFeedback(int totalColors)
{
    for (int i = 0; i < myPieces.size(); ++i)
    {
        cout << " +--------------------------------+" << endl;
        cout << " +" << setw(5) << " Choice: " << myPieces[i].userGuess << setw(2) << " -> " << setw(6) << stringToColor(myPieces[i].userGuess) << WHITE << endl;
        displayResult(myPieces[i].notinSecret, myPieces[i].correctlyPlaced, myPieces[i].incorrectlyPlaced, 0, totalColors, myPieces[i].chosenOutput);
        cout << endl;
        cout << WHITE << " +" << setw(5) << " Tries Left: " << myPieces[i].tries << endl;
        cout << WHITE << " +--------------------------------+" << endl;
    }
}

//************************************************************************
// Function: helpUserSeeColors()
// Purpose:  To help the user remember all the available colors to choose from
//************************************************************************
void mastermind::helpUserSeeColors(int totalColors)
{
    cout << endl;
    cout << "You must choose " << totalColors << " colors" << endl;
    cout << "---------------------------" << endl;
    cout << RED << "(r) ";
    cout << GREEN << "(g) ";
    cout << BLUE << "(b) ";
    cout << YELLOW << "(y) ";
    cout << WHITE << "(w) ";
    cout << PINK << "(p) ";
    cout << CYAN << "(c) ";
    cout << WHITE << endl;
    cout << endl;
}

//************************************************************************
// Function: whoMessage(char isWho)
// Purpose:  Function to return a winner or loser message
//************************************************************************
string mastermind::resultMessage(char isWho)
{
    string rsp;
    if (isWho == 'w')
    {
        rsp = "Congrats you guessed the secret correctly.\n";
    }
    else
    {
        rsp = "Sorry, you lose...keep on trying";
    }

    return rsp;
}

//************************************************************************
// Function: aiPlay(int totalColors)
// Purpose:  Game Loop
//************************************************************************
void mastermind::aiPlay(int totalColors)
{
    int randomizer;
    int tries = 1;
    bool gameOver = false;

    string secretCode = generateSecret(totalColors); // Ai Chosen Guess
    string userGuess;

    while (tries <= attempts && gameOver == false)
    {
        randomizer = rand() % 3;
        userGuess = authenticateGuess(totalColors);

        if (userGuess == secretCode)
        {
            cout << BLUE << resultMessage('w') << WHITE << endl;
            gameOver = true;
        }
        else
        {
            playerChose playerInstance = setPlayerInstance(userGuess, secretCode, attempts - tries, randomizer);
            myPieces.push_back(playerInstance);
            displayFeedback(totalColors);
            tries++;
        }
    }
    if (gameOver == false)
    {
        cout << RED << resultMessage('l') << WHITE << endl;
        cout << "The secret code was : " << secretCode << " -> " << stringToColor(secretCode) << endl;
        cout << endl;
    }
}

//************************************************************************
// Function: checkSet(int wordLocation, set<int> coordinateSet)
// Purpose:  Making sure that no 2 coordinates are used because the game only allows unique sets
//************************************************************************
bool mastermind::checkSet(int wordLocation, set<int> coordinateSet)
{
    set<int>::iterator it;
    for (it = coordinateSet.begin(); it != coordinateSet.end(); it++)
    {
        if (wordLocation == *it)
        {
            return false;
        }
    }
    return true;
}

//************************************************************************
// Function: resultAlgorithm(string userGuess, string secretCode, int totalColors)
// Purpose:  Algorithm to determine how many correctly,incorrecly placed pegs and the ones that arent in at all
//************************************************************************
getResults mastermind::resultAlgorithm(string userGuess, string secretCode, int totalColors)
{
    //Set to store coordinates of a letter in a string to eliminate repetitive colors
    set<int> repeatedUserPosition;
    set<int> repeatedSecretPosition;

    int samePosition = 0; // In the secret code and correct position
    for (int i = 0; i < totalColors; ++i)
    {
        if (userGuess[i] == secretCode[i])
        {
            samePosition++;
            repeatedUserPosition.insert(i);
            repeatedSecretPosition.insert(i);
        }
    }

    int wrongPosition = 0; // In the secret code but wrong position
    int notinKey = 0;      // Not in the secret code at all

    for (int i = 0; i < userGuess.size(); i++)
    {
        char capture = userGuess[i];
        for (int j = 0; j < secretCode.size(); ++j)
        {
            if ((capture == secretCode[j]) && checkSet(i, repeatedUserPosition) && checkSet(j, repeatedSecretPosition))
            {
                repeatedUserPosition.insert(i);
                repeatedSecretPosition.insert(j);
                wrongPosition++;
            }
        }
    }

    //Returning the struct
    getResults player;
    player.correctlyPlaced = samePosition;
    player.incorrectlyPlaced = wrongPosition;

    // By process of deduction, if color is not in the same position or wrong position then we can say it's not in the code.
    player.notinSecret = totalColors - samePosition - wrongPosition;
    return player;
}

//************************************************************************
// Function: setPlayerInstance(string userGuess, string secretCode, int tries, int chooser)
// Purpose:  A struct that packages all the info of a user such as : guess, tries left, and info about pegs
//************************************************************************
playerChose mastermind::setPlayerInstance(string userGuess, string secretCode, int tries, int randomizer)
{
    playerChose event;
    event.userGuess = userGuess;
    event.chosenOutput = randomizer;

    int totalColors = userGuess.size();
    getResults player = resultAlgorithm(userGuess, secretCode, totalColors);

    event.correctlyPlaced = player.correctlyPlaced;
    event.notinSecret = player.notinSecret;
    event.incorrectlyPlaced = player.incorrectlyPlaced;
    event.tries = tries;

    return event;
}

//************************************************************************
// Function: generateSecret(int totalColors)
// Purpose:  Randomly choose a secretCode
//************************************************************************
string mastermind::generateSecret(int totalColors)
{
    string secretCode;
    int random;

    for (int i = 0; i < totalColors; ++i)
    {
        random = rand() % 7;
        secretCode += colors[random];
    }
    return secretCode;
}

//************************************************************************
// Function: stringToColor(string password)
// Purpose:  Displaying colored pegs
//************************************************************************
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
    return "";
}
