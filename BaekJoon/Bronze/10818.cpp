#include <iostream>

using namespace std;

int min_value = 1000001;
int max_value = -1000001;

int main()
{
    int N;
    cin >> N;

    int value;
    for (int i = 0; i< N; i++)
    {
        cin >> value;

        if (value < min_value)
            min_value = value;
        if (value > max_value)
            max_value = value;
    }

    cout << min_value << " " << max_value;
    return 0;
}