#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> list(N);
    for (int i = 0; i < N; i++)
        cin >> list[i];

    sort(list.begin(),list.end());

    for (const int value : list)
        cout << value << "\n";
    
    return 0;
}