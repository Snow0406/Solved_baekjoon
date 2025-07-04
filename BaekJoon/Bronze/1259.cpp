#include <iostream>
#include <string>

using namespace std;

bool check(string num)
{
    int len = num.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (num[i] != num[len - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    string str;
    while (cin >> str && str != "0")
    {
        cout << (check(str)? "yes" : "no") << endl;
    }

    return 0;
}