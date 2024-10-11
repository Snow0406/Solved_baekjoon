#include <iostream>

using namespace std;

int main()
{
    int num, count = 0;
    bool arr[42] = { };

    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        arr[num % 42] = true;
    }

    for (bool i : arr)
    {
        if (i)
            count++;
    }
    cout << count << "\n";
}
