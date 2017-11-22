// Pairing
#include <iostream>

using namespace std;

void Pairing(int n)
{
    int i = 0;

    while(i < n)
    {
        int j = 0;

        while(j < n)
        {
            cout << i << ", " << j << endl;
            j = j + 1;
        }
        i = i + 1;
    }
}

int main()
{
    Pairing(10);
    return 0;
}
