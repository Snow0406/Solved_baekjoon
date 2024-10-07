#include <iostream>
#include <string>
using namespace std;

int main()
{
    int arr[10] = {};
    int a, b, c;

    cin >> a >> b >> c;
    int res = a * b * c;

    string str = to_string(res);

    for (char number : str) {
        arr[number - '0']++;
    }
    for (int result : arr)
    {
        cout << result << "\n";
    }
    return 0;
}
