// Project: BinaryString_To_Decimal.cbp
// File   : BinaryString_To_Decimal.cpp

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int BinaryStringToDecimal(
    string binaryString)
{
    // Initial result
    int decNumber = 0;

    // variable for current power base
    int n;

    // Declare reverse iterator
    string::reverse_iterator it;

    // Iterate all characters in binaryString
    // from the last character to the first character
    for (
        it = binaryString.rbegin(), n = 0;
        it != binaryString.rend();
        ++it, ++n)
    {
        // if character '1' is found
        // add decNumber with power of current base
        char c = *it;
        if(c == '1')
        {
           decNumber += pow(2, n);
        }
    }

    // return the decimal
    return decNumber;
}

int main()
{
    cout << "Binary String To Decimal" << endl;

    // Input binary string
    string binaryString;
    cout << "Input binary string -> ";
    getline(cin, binaryString);

    // Convert to decimal
    int decNumber = BinaryStringToDecimal(
        binaryString);

    // Show the result to user
    cout << "Decimal of '" << binaryString;
    cout << "' is " << decNumber << endl;

    return 0;
}
