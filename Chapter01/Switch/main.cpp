// Switch.cbp
#include <iostream>

using namespace std;

int main ()
{
    int i, a, b;

    cout << "Operation Mode: " << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "Please enter the operation mode: ";
    cin >> i;

    cout << "Please enter the first number: ";
    cin >> a;
    cout << "Please enter the second number: ";
    cin >> b;

    cout << "The result of ";

    switch(i)
    {
    case 1:
        cout << a << " + " << b << " is " << a + b;
        break;
    case 2:
        cout << a << " - " << b << " is " << a - b;
        break;
    case 3:
        cout << a << " * " << b << " is " << a * b;
        break;
    case 4:
        cout << a << " / " << b << " is " << a / b;
        break;
    }

    cout << endl;
    return 0;
}
