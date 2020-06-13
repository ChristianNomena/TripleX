#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Introduction to the game
    std::cout << "You are a hacker breaking traps on your way for this level " << Difficulty << std::endl;
    std::cout << "You have to resolve keys numbers to break every security code\n\n";
}

bool PlayGame(int Difficulty, int KeySum, int KeyProduct)
{
    PrintIntroduction(Difficulty);

    // Level Trap
    std::cout << "+ There are three keys in the security code\n";
    std::cout << "+ The keys add-up to : " << KeySum << std::endl;
    std::cout << "+ The keys multiply to give : " << KeyProduct << std::endl;

    // Player Guesses
    int GuessA, GuessB, GuessC;

    std::cout << "Guess the Keys with this structure : keyA keyB keyC\n";
    std::cin >> GuessA >> GuessB >> GuessC;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    // Check the player's answer
    if (GuessSum == KeySum && GuessProduct == KeyProduct)
    {
        std::cout << "======= Congratulations ! You're a good hacker keys =======\n\n";
        return true;
    }
    else
    {
        std::cout << "===== Oh no ! That's not the security code, try again =====\n\n";
        return false;
    }
}

 void GenerateSecurityCode(int Difficulty, int* pKeySum, int* pKeyProduct)
{
    // Keys declaration
    const int KeyA = (rand() % (Difficulty + 1)) + 1;
    const int KeyB = (rand() % (Difficulty + 1)) + 1;
    const int KeyC = (rand() % (Difficulty + 1)) + 1;

    const int KeySum = KeyA + KeyB + KeyC;
    const int KeyProduct = KeyA * KeyB * KeyC;

    // Pointer Affectation to change KeySum and KeyProduct in the main function
    *pKeySum = KeySum;
    *pKeyProduct = KeyProduct;
}

int main()
{
    std::cout << "=============== WELCOME TO TRIPLEX ===============\n";
    
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxLevelDifficulty = 10;

    // Pointers Declaration
    int KeySum, KeyProduct;
    int* pKeySum(0), * pKeyProduct(0);

    pKeySum = &KeySum;
    pKeyProduct = &KeyProduct;

    // Initialize Difficulty
    GenerateSecurityCode(LevelDifficulty, pKeySum, pKeyProduct);
    

    while (LevelDifficulty <= MaxLevelDifficulty) // Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty, KeySum, KeyProduct);

        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            // We only regenerate the security code when a level's completed
            ++LevelDifficulty;
            GenerateSecurityCode(LevelDifficulty, pKeySum, pKeyProduct);
        }
    }

    std::cout << "=============== You broke all security codes ===============\n";
    std::cout << "=================== THE GAME IS FINISHED ===================\n";
    std::cout << "=================== THANK YOU FOR PLAYING ==================\n";

    return 0;
}
