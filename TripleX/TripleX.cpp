#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // The game background story
    std::cout << "\n\n room number: " << Difficulty;
    std::cout << "\n\nYou were sitting at your computer, when suddenly you got knocked out from behind\n";
    std::cout << "you woke up in a weird place with a lock on the wall and a note\n";
    std::cout << "\"this house has 5 rooms they are locked, you need to open the doors with a code in order to survive, fail and you die\"\n"; 
    std::cout << "Good Luck!\n\n";
}

bool BPlayGame(int Difficulty)
{
    
    PrintIntroduction(Difficulty);

   // the  constant variables
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty; 
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;  
    const int CodeProduct = CodeA * CodeB * CodeC; 

    //expresion of the variables 
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to: " << CodeProduct << '\n'; 

/* 
    std::cout << "Code A: " << CodeA << std::endl;// Debug
    std::cout << "Code B " << CodeB << std::endl;// Debug
    std::cout << "Code C " << CodeC << std::endl;// Debug
 */

    // Player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC; 
 
    // check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) 
    {
        std::cout << "\nGood Job, You survived the " << Difficulty;
        std::cout << " room";
        return true;
    }
    else
    {
        std::cout << "\nYou Died and respawned in the room that you died in";
        return false;
    }
}

int main()
{

    bool PlayAgain = true;

    while (PlayAgain = true)
    {

        system("cls");

        int LevelDifficulty = 1;
        int const MaxLevel = 5;

        srand(time(NULL));

        while (LevelDifficulty <= MaxLevel) // loop game until all levels are completed
        {
            bool BlevelComplete = BPlayGame(LevelDifficulty);
            std::cin.clear(); // clears any errors
            std::cin.ignore(); // Discard the buffer

            if (BlevelComplete)
            {
            ++LevelDifficulty;
            }
        }

        system("cls");

        std::cout << "\n\nDo you want to play again? (y/n)\n";
        char answer;
        std::cin >> answer;
        if (answer != 'y')
        {
            PlayAgain = false;
        }
    }
    
    

    std::cout << "\n\nyou survived the house and can return home, see you soon ;)";
    
    return 0; 
}