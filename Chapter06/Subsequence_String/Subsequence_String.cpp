// Project: Subsequence_String.cbp
// File   : Subsequence_String.cpp

#include <iostream>

using namespace std;

bool IsSubSequence(
    string str1,
    string str2,
    int x,
    int y)
{
    // If all characters in str1
    // have been checked,
    // it means that the str1 is subsequence
    // of str2
    if (x == 0)
    {
        return true;
    }

    // There is some characters in str2
    // that don't matched with str1
    // so return false
    if (y == 0)
    {
        return false;
    }

    // If last characters of two strings are matching,
    // continue to check another character
    if (str1[x - 1] == str2[y - 1])
    {
        return IsSubSequence(str1, str2, x - 1, y - 1);
    }
    // If not, check the second last of str2
    else
    {
        return IsSubSequence(str1, str2, x, y - 1);
    }
}

int main()
{
    cout << "Subsequence String" << endl;
    cout << "Check if 1st string is a ";
    cout << "subsequence of 2nd string" << endl;

    // Input first string
    string string1;
    cout << "Input 1st string -> ";
    getline(cin, string1);

    // Input second string
    string string2;
    cout << "Input 2nd string -> ";
    getline(cin, string2);

    // Check if str1 is subsequence of str2
    cout << "'" << string1 << "' is ";
    if(IsSubSequence(
        string1,
        string2,
        string1.size(),
        string2.size()))
    {
        cout << "subsequence";
    }
    else
    {
        cout << "NOT subsequence";
    }
    cout << " of '" << string2;
    cout << "'" << endl;

    return 0;
}
