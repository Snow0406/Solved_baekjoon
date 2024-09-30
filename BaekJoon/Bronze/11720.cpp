#include <iostream>

using namespace std;

int main()
{
    char list[101];
    int N, res = 0;
    cin >> N >> list;
    
    //'0' == 48
    for (int i = 0; i < N; i++)
        res += list[i] - '0';

    cout << res << "\n";
    
    return 0;
}
