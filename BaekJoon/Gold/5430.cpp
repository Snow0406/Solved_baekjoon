#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
    int T, N;
    cin >> T;

    while (T--)
    {
        string command, _array;
        cin >> command;
        cin >> N;
        cin >> _array;
        deque<int> dq;

        bool err = false;
        bool _reverse = false;
        string temp;
        
        for (int i = 0; i < _array.length(); i++)
        {
            if(isdigit(_array[i]))
                temp += _array[i];
            else if(!temp.empty())
            {
                dq.push_back(stoi(temp));
                temp = "";
            }
        }

        for (const char c : command)
        {
            if (c == 'R')
                _reverse = !_reverse;
            else if (c == 'D')
            {
                if (dq.empty())
                {
                    err = true;
                    break;
                }
                else
                {
                    if (_reverse) dq.pop_back();
                    else dq.pop_front();
                }
            }
        }

        if (err) cout << "error" << "\n";
        else
        {
            if (_reverse) reverse(dq.begin(), dq.end());
            cout << "[";
            for (int i = 0; i < dq.size(); i++)
            {
                if (i == dq.size() - 1)
                    cout << dq[i];
                else cout << dq[i] << ",";
            }
            cout << "]" << "\n";
        }
    }

    return 0;
}