#include <iostream>

using namespace std;

int SumOfDivision(
    int nArr[], int n, int mArr[], int m)
{
    int total = 0;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            total += (nArr[i] * mArr[j]);
        }
    }

    return total;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
