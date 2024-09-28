#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        long long N, C;
        cin >> N >> C;
        if (N % C == 0)
            cout << N/C << "\n";
        else  cout << N/C + 1 << "\n";
    }

    return 0;
}
