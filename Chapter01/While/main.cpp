// While.cbp
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int GenerateRandomNumber(int min, int max)
{
    // static used for efficiency,
    // so we only calculate this value once
    static const double fraction =
        1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    // evenly distribute the random number
    // across our range
    return min + static_cast<int>(
        (max - min + 1) * (rand() * fraction));
}

int main()
{
    // set initial seed value to system clock
    srand(static_cast<unsigned int>(time(0)));

    // Computer generate random number
    // between 1 to 100
    int computerNumber = GenerateRandomNumber(1, 100);

    // User inputs a guessed number
    int userNumber;
    cout << "Please enter a number between 1 to 100: ";
    cin >> userNumber;

    // Run the WHILE loop
    while(userNumber != computerNumber)
    {
        cout << userNumber << " is ";
        if(userNumber > computerNumber)
            cout << "greater";
        else
            cout << "lower";
        cout << " than computer's number" << endl;
        cout << "Choose another number: ";
        cin >> userNumber;
    }

    cout << "Yeeaayy.. You've got the number." << endl;
    return 0;
}
