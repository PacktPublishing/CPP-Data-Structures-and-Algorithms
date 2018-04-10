// Project: Palindrome.cbp
// File   : Palindrome.cpp

#include <iostream>
#include <algorithm>

using namespace std;

bool IsPalindrome(
    string str)
{
    // Palindrome is not case sensitive
    // so we convert all characters
    // to uppercase
    transform(
        str.begin(),
        str.end(),
        str.begin(),
        ::toupper);

    // Palindrome does not care about space
    // so we remove all spaces if any
    str.erase(
        remove(
            str.begin(),
            str.end(),
            ' '),
            str.end());

    // --- Palindrome detector ---
    // Starting from leftmost and rightmost elements
    // of the str
    int left = 0;
    int right = str.length() - 1;

    // Comparing the current leftmost
    // and rightmost elements
    // until all elements are checked or
    // until unmatched characters are found
    while(right > left)
    {
        if(str[left++] != str[right--])
        {
            return false;
        }
    }

    // If all characters which are compared
    // are same, it must be palindrome
    return true;
    // --- End of palindrome detector ---
}

int main()
{
    cout << "Palindrome" << endl;

    // Input string
    string str;
    cout << "Input string -> ";
    getline(cin, str);

    // Check if it is palindrome
    cout << "'" << str << "' is ";
    if(IsPalindrome(str))
    {
        cout << "a palindrome";
    }
    else
    {
        cout << "NOT a palindrome";
    }
    cout << endl;

    return 0;
}
