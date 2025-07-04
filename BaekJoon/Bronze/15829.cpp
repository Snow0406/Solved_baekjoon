#include <iostream>
#include <string>

using namespace std;

int main()
{
    int L;
    string str;
    cin >> L >> str;

    long long r = 31;
    long long M = 1234567891;
    long long pow = 1;
    long long hash = 0;
    
    for (int i = 0; i < L; i++)
    {
        int num = str[i] - 'a' + 1;
        hash = (hash % M + (num * pow) % M) % M; // 여기에 나머지를 두번 하는 이유는 오버플로우를 방지하기 위해서
        pow = (pow * r) % M; // 여기에도 나머지를 하는 이유는 오버플로우를 방지하기 위해서
    }

    /*
     * 모듈로 연산의 수학적 성질
     * (a * b) % m = ((a % m) * (b % m)) % m
     *
     * 위에 있는 식이 가능하기 때문에 for문에도 저런식으로 오버플로우를 방지하기 위에 했음
     */

    cout << hash << endl;

    return 0;
}