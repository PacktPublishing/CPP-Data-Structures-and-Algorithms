#include <iostream>

using namespace std;

int Factorial(int n)
{
    if(n == 1)
        return 1;

    return n * Factorial(n - 1);
}

int main()
{
    cout << "Factorial of 6 (6!) is ";
    cout << Factorial(6) << endl;
    return 0;
}
