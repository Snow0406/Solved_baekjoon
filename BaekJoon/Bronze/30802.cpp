#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>

// 처음에는 cmath의 ceil 이용해서 했는데 계속 실패가 떠서
// ceil(a/b) = floor((a+b-1)/b)의 공식 이용해서 성공

using namespace std;

int main()
{
    int N, T, P;
    int size[6];
    scanf("%d", &N);
    for (int& i : size)
        scanf("%d", &i);
    scanf("%d %d", &T, &P);

    int nT = 0;
    for (int i = 0; i < 6; i++)
    {
        nT += (size[i] + T - 1) / T;
    }
    printf("%d\n", nT);
    printf("%d %d", N / P, N % P);
}