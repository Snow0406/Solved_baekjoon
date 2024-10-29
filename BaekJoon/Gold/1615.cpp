#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

// 참고 : https://junuuu.tistory.com/371

using namespace std;

pair<long long, long long> arr[2000000];
vector<long long> tree;

long long Query(long long node, long long start, long long end, long long left, long long right)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    long long mid = (start+end)/2;
    return Query(node*2, start, mid, left, right) + Query(node*2+1, mid+1, end, left, right);
}

void Update(long long node, long long start, long long end, long long index, long long value)
{
    if (index < start || index > end) return;
    
    if (start == end)
    {
        if (index == start)
            tree[node]++;
        return;
    }
    
    long long mid = (start+end)/2;
    Update(node*2, start, mid, index, value);
    Update(node*2+1, mid+1, end, index, value);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N, M, count = 0;
    cin >> N >> M;

    const int h = ceil(log2(M));
    const int treeSize = 1 << (h+1);
    
    tree.resize(treeSize);

    for (int i = 0; i < M; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr, arr + M);
    
    for (int i = 0; i < M; i++)
    {
        count += Query(1, 0, N-1, arr[i].second, N-1);
        Update(1, 0, N-1, arr[i].second - 1, 1);
    }

    cout << count << "\n";
    
    return 0;
}