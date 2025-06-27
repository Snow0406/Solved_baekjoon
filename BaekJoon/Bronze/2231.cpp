#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>

using namespace std;

int getValue(int n)
{
    int num = n;
    while (n > 0)
    {
        num += n % 10;
        n /= 10;
    }
    return num;
}

int main()
{
    int N;
    cin >> N;

    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        if (getValue(i) == N)
        {
            result = i;
            break;
        }
    }

    cout << result << endl;
}