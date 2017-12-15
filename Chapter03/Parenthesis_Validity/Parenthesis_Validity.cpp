// Project: Parenthesis_Validity.cbp
// File   : Parenthesis_Validity.cpp
#include <iostream>
#include <cstring>
#include "../Stack/include/Stack.h"

using namespace std;

bool IsValid (char expression[])
{
    int n = strlen(expression);

    Stack<char> stackChar = Stack<char>();

    for (int i = 0; i < n; ++i)
    {
        // If input is opened parenthesis
        // just store it in the stack
        if(expression[i] == '{')
        {
            stackChar.Push('{');
        }
        else if(expression[i] == '[')
        {
            stackChar.Push('[');
        }
        else if(expression[i] == '(')
        {
            stackChar.Push('(');
        }
        // Check when the input
        // is closed parenthesis
        else if (
            expression[i] == '}' ||
            expression[i] == ']' ||
            expression[i] == ')')
        {
            // If the stack is empty
            // or the last parenthesis is different
            // than the one we are closed,
            // then the expression is wrong
            if(expression[i] == '}' &&
               (stackChar.IsEmpty() || stackChar.Top() != '{'))
               return false;
            else if(expression[i] == ']' &&
               (stackChar.IsEmpty() || stackChar.Top() != '['))
               return false;
            else if(expression[i] == ')' &&
               (stackChar.IsEmpty() || stackChar.Top() != '('))
               return false;
            else
                stackChar.Pop();
        }
    }

    // If the stack is empty,
    // the expression is valid
    // otherwise it's invalid
    if (stackChar.IsEmpty())
        return true; //
    else
        return false;
}

int main()
{
    // Prepare array for storing
    // the expression
    char expr[1000];

    // Ask user to input the expression
    cout << "Please type the parenthesis expression ";
    cout << "then press ENTER!" << endl;
    cin >> expr;

    // Check the validity
    bool bo = IsValid(expr);

    // Notify the user
    cout << endl;
    cout << "The " << expr << " expression is ";
    if(bo)
        cout << "valid";
    else
        cout << "invalid";
    cout << endl;

    return 0;
}

