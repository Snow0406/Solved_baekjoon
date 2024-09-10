#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int A, B;
        cin >> A >> B;

        int limit = ceil((A + B) / 4.0);
        if ((A > B && B*3 < A) || (A < B && A*3 < B)) cout << "-1" << "\n";
        else cout << limit << "\n";
    }


    return 0;
}