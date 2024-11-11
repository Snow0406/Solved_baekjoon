// 참고 : https://killerwhale0917.tistory.com/11, https://vanilla-sue.tistory.com/67

#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> arr;
vector<int> tree(500010 * 4, 0);

void update(int node, int start, int end, int index)
{
    if (start > index || index > end) return;
    tree[node]++;

    if (start != end)
    {
        int mid = (start+end)/2;
        update(node*2, start, mid, index);
        update(node*2+1, mid+1, end, index);
    }
}

int sum(int node, int start, int end, int left, int right)
{
    if (start > right || left > end) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start+end)/2;
    return sum(node*2, start, mid, left, right) + sum(node*2+1, mid+1, end, left, right);
}

bool compare1(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second < b.second;
}

int main()
{
    cin >> N;
    arr.resize(N);

    for (int i = 0; i < N; ++i)
    {
        arr[i].first = i;     // 선수들의 기본 index
        cin >> arr[i].second; // 선수들의 실력 데이터
    }

    sort(arr.begin(), arr.end(), compare1);

    for (int i = 0; i < N; ++i)
        arr[i].second = i;

    vector<pair<int, int>> res(N);
    for (int i = N-1; i >= 0; --i)
    {
        res[i].first = arr[i].first;
        res[i].second = sum(1, 0, N-1, 0, arr[i].first - 1) + 1;
        update(1, 0, N-1, arr[i].first);
    }

    sort(res.begin(), res.end());
    for (auto num : res)
    {
        cout << num.second << "\n";
    }
    
    return 0;
}

