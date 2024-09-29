#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int N, X;
    cin >> N >> X;

    vector<int> list;
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;

        if (A < X) list.push_back(A);
        else continue;
    }

    for (const int num : list)
        cout << num << " ";
    
    return 0;
}