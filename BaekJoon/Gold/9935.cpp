#include <algorithm>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    cin >> A;
    cin >> B;

    stack<char> s;
    const int bLen = B.length();
    string temp;

    for (char i : A)
    {
        s.push(i);
        if (s.top() == B[bLen - 1] && s.size() >= bLen)
        {
            for (int j = 0; j < bLen; j++)
            {
                temp += s.top();
                s.pop();
            }

            reverse(temp.begin(), temp.end());
            if (temp != B)
            {
                for (char ch : temp) s.push(ch);
            }
            temp = "";
        }
    }

    if (s.empty()) cout << "FRULA" << endl;
    else
    {
        string result;
        while (!s.empty()) {
            result += s.top();
            s.pop();
        }

        reverse(result.begin(), result.end());
        cout << result << endl;
    }

    return 0;
}