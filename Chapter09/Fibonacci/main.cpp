#include <iostream>
#include <vector>

using namespace std;

long long fib(int n)
{
    if (n <= 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

long long fib2(int n)
{
    if(n <= 1)
        return 1;

    long long last = 1;
    long long nextToLast = 1;
    long long answer = 1;

    for(int i = 2; i <=n; ++i)
    {
        answer = last + nextToLast;
        nextToLast = last;
        last = answer;
    }

    return answer;
}

int main()
{
    cout << "Fibonacci" << endl;

    cout << fib2(10) << endl;
    return 0;
}
