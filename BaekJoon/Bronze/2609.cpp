#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return a > b ? gcd(b, a % b) : gcd(a, b % a);
}

int main()
{
    int A, B;
    cin >> A >> B;

    cout << gcd(A, B) << endl;
    cout << (A * B) / gcd(A, B) << endl;
    return 0;
}