// Project: Subsequence_Generator.cbp
// File   : Subsequence_Generator.cpp

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<string> GenerateSubsequences(
    string str)
{
    // Return value is stored
    // on vecString
    vector<string> vecString;

    // Retrieve str length
    int strLen = str.size();

    // bitCounter is used to check
    // character position
    int bitCounter = pow(2, strLen);

    // Check from 000..001 to 111..111
    // Empty subset is ignored
    for (int i = 1; i < bitCounter; ++i)
    {
        // Temporary variable
        // to store current subsequence
        string subsequence = "";

        // Construct the new subsequence string
        for (int j = 0; j < strLen; j++)
        {
            // Check if j-th bit in the bitCounter is set
            // If so, pick j-th character from str
            if (i & (1 << j))
            {
                subsequence += str[j];
            }
        }

        // Put it to vector
        vecString.push_back(subsequence);
    }

    // Return the vector
    return vecString;
}

int main()
{
    cout << "Subsequence Generator" << endl;

    // Input string
    string str;
    cout << "Input string -> ";
    getline(cin, str);

    // Generate subsequences
    vector<string> myvector = GenerateSubsequences(
        str);

    // Show the result to user
    cout << "All subsequences of '" << str;
    cout << "':" << endl;
    for (
        vector<string>::iterator it = myvector.begin();
        it != myvector.end();
        ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
