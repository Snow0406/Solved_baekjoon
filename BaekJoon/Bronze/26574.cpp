#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int N;
    cin >> N;

    vector<int> list(N);
    for (int i = 0; i < N; i++)
        cin >> list[i];

    for (int num : list)
        cout << num << " " << num << "\n";
    
    return 0;
}