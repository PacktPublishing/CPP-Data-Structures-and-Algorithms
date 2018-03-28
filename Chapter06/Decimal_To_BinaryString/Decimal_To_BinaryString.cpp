// Project: Decimal_To_BinaryString.cbp
// File   : Decimal_To_BinaryString.cpp

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string DecimalToBinaryString(
    int decimalNumber)
{
    // Initial result
    string binaryString = "0";

    // Only perform this procedure
    // if decimalNumber is greater than 0
    if(decimalNumber > 0)
    {
        // Reset result
        binaryString = "";

        // Declare a variable for division process
        div_t dv{};

        // Initialize the division quot
        dv.quot = decimalNumber;

        // Perform these procedure
        // until the quot is 0
        do
        {
            dv = div(dv.quot, 2);
            binaryString = to_string(dv.rem) + binaryString;
        }
        while(dv.quot);
    }

    // return the binary string
    return binaryString;
}

int main()
{
    cout << "Decimal To Binary String" << endl;

    // Input a decimal number
    int decNum;
    cout << "Input a decimal number -> ";
    cin >> decNum;

    // Convert to binary string
    string binaryString = DecimalToBinaryString(decNum);

    // Show the result to user
    cout << "Binary string of " << decNum;
    cout << " is '" << binaryString;
    cout << "'" << endl;

    return 0;
}
