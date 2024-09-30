#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = N; j > 0; j--)
        {
            if (i >= j)
                 cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
