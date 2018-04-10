// Project: Pattern_Searching.cbp
// File   : Pattern_Searching.cpp

#include <iostream>
#include <vector>

using namespace std;

vector<int> SearchPattern(
    string targetString,
    string patternString)
{
    vector<int> vecIndex;

    // Retrieve string length
    int strLen = targetString.size();
    int patLen = patternString.size();

    // Only perform the following procedure
    // if pattern string is not longer than
    // target string
    if(patLen <= strLen)
    {
        // Iterate through target string elements
        // from the beginning until
        // the last possible element where
        // pattern is at the last position
        for(int i = 0; i <= strLen - patLen; ++i)
        {
            int j;

            // Start comparing pattern string
            for(j = 0; j < patLen; ++j)
            {
                // Quit from inner for-loop
                // if character is not matched
                if(targetString[i + j] !=
                    patternString[j])
                {
                    break;
                }
            }

            // If inner for-loop is done
            // it means that pattern is found
            // in the target string
            if(j == patLen)
            {
                // store the index in vector
                vecIndex.push_back(i);
            }
        }
    }

    // Return the vector
    return vecIndex;
}

int main()
{
    cout << "Pattern Searching" << endl;

    // Input target string
    string targetStr;
    cout << "Input target string -> ";
    getline(cin, targetStr);

    // Input pattern string
    string patternStr;
    cout << "Input pattern string -> ";
    getline(cin, patternStr);

    // Find the pattern
    vector<int> myvector = SearchPattern(
        targetStr,
        patternStr);

    // Show the result to user
    cout << "'" << patternStr << "' is ";
    if(myvector.size() > 0)
    {
        cout << "found at index ";
        for (
            vector<int>::iterator it = myvector.begin();
            it != myvector.end();
            ++it)
        {
            cout << *it << " ";
        }
    }
    else
    {
        cout << "NOT found";
    }
    cout << endl;

    return 0;
}

