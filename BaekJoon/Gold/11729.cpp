#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int n, int start, int mid, int end)
{
    if (n == 1)
    {
        cout << start << " " << end << "\n";
        return;
    } else
    {
        hanoi(n - 1, start, end, mid);
        cout << start << " " << end << "\n";
        hanoi(n - 1, mid, start, end);
    }
    
}

int main()
{
    int N;
    cin>>N;
    cout << static_cast<int>(pow(2, N)) - 1 << "\n";
    hanoi(N, 1, 2, 3);
    return 0;
}
