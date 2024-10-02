#include <iostream>
#include <stack>
#include <string>

/*
 * 비트 마스킹
 * https://hagisilecoding.tistory.com/54
 */

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string cmd;
    stack<int> list;
    int N, M = 0;
    cin >> N;

    while (N--)
    {
        cin >> cmd;

        if (cmd == "push")
        {
            cin >> M;
            list.push(M);
        }
        else if (cmd == "pop")
        {
            cin >> M;
            printf(list.pop());
        }
        else if (cmd ==  "check")
        {
            cin >> M;
            cout << ((S & (1 << M)) ? 1 : 0) << "\n";
        }
        if (cmd ==  "toggle")
        {
            cin >> M;
            (S & (1 << M)) ? S &= ~(1 << M) : S |= (1 << M);
        }
        else if (cmd ==  "all")
            S |= (1 << 21) - 1;
        else if (cmd ==  "empty")
            S = 0;
    }
    return 0;
}