#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> list;
    vector<int> prev(n, -1);
    vector<int> last_idx;

    for (int i = 0; i < n; i++)
    {
        const int idx = lower_bound(list.begin(), list.end(), v[i]) - list.begin();

        // 새로운 최대값일때
        if (idx == list.size())
        {
            list.push_back(v[i]);
            last_idx.push_back(i);
        }
        else
        {
            // 해당 위치의 값을 더 유리한 값으로 교체 (같거나 작은 값)
            list[idx] = v[i];
            last_idx[idx] = i;
        }

        // 이전 원소 찾기 (수열 복원할때 사용하기 위해)
        if (idx > 0)
        {
            prev[i] = last_idx[idx - 1];
        }
    }

    cout << list.size() << endl;

    // 실제 LIS 복원하기
    vector<int> lis;
    int current = last_idx.back();

    // 역순으로 따라가면서 LIS 구성
    while (current != -1)
    {
        lis.push_back(v[current]);
        current = prev[current];
    }

    const int len = lis.size();
    for (int i = len - 1; i >= 0; i--)
    {
        cout << lis[i];
        if (i != 0) cout << " ";
    }

    return 0;
}