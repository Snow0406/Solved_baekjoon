#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int list[5], re = 0;
    cin >> list[0] >> list[1] >> list[2] >> list[3] >> list[4];

    for (int i : list)
    {
        re += pow(i, 2);
    }
    
    cout << re % 10 << "\n";
}