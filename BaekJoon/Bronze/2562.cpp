#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define INPUT_N 9

int main ()
{
    vector<int> list(INPUT_N);
    int maxNum = 0;
    
    for (int i = 0; i < INPUT_N; i++)
    {
        cin >> list[i];
        if (list[i] > maxNum)
            maxNum = list[i];
    }

    //cout << "-----------------------" << "\n";

    cout << maxNum << "\n";
    cout << find(list.begin(), list.end(), maxNum) - list.begin() + 1 << "\n";

    return 0;
}