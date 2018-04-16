#include <iostream>

using namespace std;

int count(int S[], int m, int n)
{
    int x, y;

    // Base саѕе (n = 0)
    int table[n + 1][m];

    // Fіll thе еntеrіеѕ for 0 vаluе саѕе
    // (n = 0)
    for (int i = 0; i < m; ++i)
        table[0][i] = 1;

    // Fill rеѕt оf the table еntrіеѕ іn bоttоm
    // up mаnnеr
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            //solutions соunt іnсludіng S[j]
            x = (i - S[j] >= 0) ?
                table[i - S[j]][j] :
                0;

            //ѕоlutіоnѕ соunt excluding S[j]
            y = (j >= 1) ? table[i][j-1] : 0;

            // tоtаl соunt
            table[i][j] = x + y;
        }
    }

    return table[n][m-1];
}

int main()
{
    cout << "Coin Change Dynamic Programming" << endl;

    int S[] = {2, 5, 3, 6};
    int size = 4;
    int n = 10;

    cout << count(S, size, n) << endl;
    return 0;
}
