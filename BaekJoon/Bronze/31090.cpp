#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> list(N);
    for (int i = 0; i < N; i++)
        cin >> list[i];

    for (int num : list)
    {
        const int two = num % 100;
        if ((num + 1) % two == 0)
            cout << "Good" << "\n";
        else cout << "Bye" << "\n";
    }

    return 0;
}
