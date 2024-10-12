#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string str;
    int T;
    cin >> T;

    while (T--)
    {
        cin >> str;
        int score = 0;
        int o_count = 1;

        for (char i : str)
        {
            if(i == 'O') score += o_count++;
            else if (i == 'X') o_count = 1;
        }

        cout << score << "\n";
    }
}