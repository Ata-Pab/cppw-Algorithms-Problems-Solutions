/******************************************************************************
Rational Arithmetic

https://open.kattis.com/problems/rationalarithmetic

assets/images/rational_arithmetic.png


*******************************************************************************/
#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    int num_operations;
    cin >> num_operations;

    while (num_operations--)
    {
        long long x1, y1, x2, y2;
        char op;

        cin >> x1 >> y1 >> op >> x2 >> y2;

        long long num, den;

        switch (op)
        {
        case '+':
            num = x1*y2 + x2*y1;
            den = y1*y2;
            break;

        case '-':
            num = x1*y2 - x2*y1;
            den = y1*y2;
            break;

        case '*':
            num = x1*x2;
            den = y1*y2;
            break;

        case '/':
            num = x1*y2;
            den = y1*x2;
            break;
        }

        long long g = gcd(abs(num), abs(den));
        num /= g;
        den /= g;

        if (den < 0)
        {
            num = -num;
            den = -den;
        }

        cout << num << "/" << den << endl;
    }

    return 0;
}