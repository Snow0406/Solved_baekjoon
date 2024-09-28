#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    char list[11] = {};
    cin >> list;
    
    while (N != 0)
    {
        list[N%10]++;
        N /= 10;
    }

    int maxNum = 0;
    for (int num : list)
        cout << list << "\n";
        //max(num, maxNum);
    
    cout << maxNum << "\n";
    
    return 0;
}
