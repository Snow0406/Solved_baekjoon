#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    cin >> n >> l;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    deque<pair<int, int>> dq;

    for (int i = 0; i < n; i++)
    {
        // 뒤에서부터 현재 값보다 큰 원소를 제거
        while (!dq.empty() && dq.back().first >= arr[i]) dq.pop_back();

        // 원소 추가
        dq.push_back({arr[i], i});

        // D 범위에 벗어난 원소들 제거
        while (!dq.empty() && dq.front().second <= i - l) dq.pop_front();

        cout << dq.front().first << " ";
    }

    return 0;
}
