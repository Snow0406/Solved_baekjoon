#include <iostream>

using namespace std;

int main ()
{
    int H, M;
    cin >> H >> M;

    int m = M - 45;

    if (m >= 0) //설정된 시간의 분이 45분보다 크면
        cout << H << " " << m << "\n";
    else
    {
        if (H == 0)
            cout << 23 << " " << m + 60 << "\n";
        else
            cout << H-1 << " " << m + 60 << "\n";
    }

    return 0;
}