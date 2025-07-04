#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int N;
    float arr[1000] = { 0, };

    cin >> N;
    
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    // MAX 구하기
    float maxNum = 0;
    float avg = 0;
    for (int i = 0; i < N; i++)
        maxNum = max(arr[i], maxNum);

    // 새로운 점수 구하기
    for (int i = 0; i < N; i++)
        arr[i] = (arr[i] / maxNum) * 100;

    // 새로운 평균값 구하기
    for (int i = 0; i < N; i++)
        avg += arr[i];

    cout << avg / N << endl;
    return 0;
}