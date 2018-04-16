// Project: Coin_Change_Problem.cbp
// File   : Coin_Change_Problem.cpp

#include <iostream>
#include <vector>

using namespace std;

void MinimalChangeCoin(double changingNominal)
{
    // All denominations of U.S. Currency
    double denom[] =
        {0.01, 0.05, 0.10, 0.25, 1, 2, 5, 10, 20, 50, 100};
    int totalDenom = sizeof(denom) / sizeof(denom[0]);

    // Initialize result as a vector
    vector<double> result;

    // Traverse through all denomination
    for (int i = totalDenom - 1; i >= 0; --i)
    {
        // Find denominations
        while (changingNominal >= denom[i])
        {
           changingNominal -= denom[i];
           result.push_back(denom[i]);
        }

        // If there's no any denomination
        // that can be given just exit the loop
        if (changingNominal < denom[0])
            break;
    }

    // Print result
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
    cout << endl;
}

int main()
{
    cout << "Coin Change Problem" << endl;

    // Initialize the change nominal
    float change = 17.61;

    // Getting the minimal
    cout << "Minimal number of change for ";
    cout << change << " is " << endl;
    MinimalChangeCoin(change);

    return 0;
}
