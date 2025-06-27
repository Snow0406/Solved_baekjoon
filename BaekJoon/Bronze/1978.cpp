#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool is_prime(int n)
{
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main()
{
    int N;
    scanf("%d", &N);

    int num = 0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        if (is_prime(num)) count++;
    }
    printf("%d\n", count);
}