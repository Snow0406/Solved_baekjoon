#include <iostream>

using namespace std;

/*
 * 0 바퀴: 1개 (1)
 * 1 바퀴: 6개 (7)
 * 2 바퀴: 12개 (19)
 * 3 바퀴: 18개 (37)
 * 4 바퀴: 24개 (61)
 */

int main()
{
    int N;
    cin >> N;

    if (N == 1)
    {
        cout << "1";
        return 0;
    }
    
    int layer = 0;
    int num = 1;
    while (true)
    {
        layer++;
        num += layer * 6;
        if (N <= num)
        {
            cout << layer + 1 << endl;
            break;
        }
    }

    return 0;
}