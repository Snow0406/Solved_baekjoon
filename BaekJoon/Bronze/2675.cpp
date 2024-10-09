#include <iostream>
#include <string>

using namespace std;

int main ()
{
    int T, R;
    string str;
    cin >> T;

    while (T--)
    {
        cin >> R >> str;

        for (const char i : str)
        {
            for (int j = 0; j < R; j++)
                cout << i;
        }

        cout << "\n";
    }
    
    return 0;
}