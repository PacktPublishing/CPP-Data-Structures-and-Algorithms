// Project: Anagram.cbp
// File   : Anagram.cpp

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool IsAnagram(
    string str1,
    string str2)
{
    // Anagram is not case sensitive
    // so we convert all characters
    // to uppercase
    transform(
        str1.begin(),
        str1.end(),
        str1.begin(),
        ::toupper);
    transform(
        str2.begin(),
        str2.end(),
        str2.begin(),
        ::toupper);

    // Anagram does not care about space
    // so we remove all spaces if any
    str1.erase(
        remove(
            str1.begin(),
            str1.end(),
            ' '),
            str1.end());
    str2.erase(
        remove(
            str2.begin(),
            str2.end(),
            ' '),
            str2.end());

    // Then, we sort string1 and string2
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // If they both are anagram,
    // they will be exactly same after sorted
    return str1 == str2;
}

int main()
{
    cout << "Anagram" << endl;

    // Input string1
    string string1;
    cout << "Input string 1 -> ";
    getline(cin, string1);

    // Input string2
    string string2;
    cout << "Input string 2 -> ";
    getline(cin, string2);

    // Check if they are anagram
    cout << "'" << string1 << "' and '";
    cout << string2 << "' are ";
    if(IsAnagram(string1, string2))
    {
        cout << "anagram";
    }
    else
    {
        cout << "NOT anagram";
    }
    cout << endl;

    return 0;
}
