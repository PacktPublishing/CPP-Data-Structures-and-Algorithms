// Looping.cbp
#include <iostream>

using namespace std;

void Looping(int n)
{
    int i = 0;

    while(i < n)
    {
        cout << i << endl;
        i = i + 1;
    }
}

int main()
{
    Looping(100);
    return 0;
}
