#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> arr;
vector<pair<int, int>> tree;

pair<int, int> Init(int node, int start, int end)
{
    if (start == end)
    {
        if (arr[start] % 2 == 0)
            return tree[node] = { 0, 1 };
        else
            return tree[node] = { 1, 0 };
    }

    int mid = (start+end)/2;
    auto left = Init(node*2, start, mid);
    auto right = Init(node*2+1, mid+1, end);
    return tree[node] = { left.first + right.first, left.second + right.second };
}

void Update(int node, int start, int end, int index, int odd, int even)
{
    if (index < start || index > end) return;
    
    tree[node].first = tree[node].first + odd;
    tree[node].second = tree[node].second + even;

    if (start == end) return;
    
    int mid = (start+end)/2;
    Update(node*2, start, mid, index, odd, even);
    Update(node*2+1, mid+1, end, index, odd, even);
}

int treeCount(int node, int start, int end, int left, int right, bool isOdd)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return isOdd ? tree[node].first : tree[node].second;

    int mid = (start+end)/2;
    int leftCount = treeCount(node*2, start, mid, left, right, isOdd);
    int rightCount = treeCount(node*2+1, mid+1, end, left, right, isOdd);
    
    return leftCount + rightCount;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N;

    const int h = ceil(log2(N));
    const int treeSize = 1 << (h+1);

    arr.resize(N+1);
    tree.resize(treeSize);

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    Init(1, 1, N);
    
    cin >> Q;
    
    for (int i = 0; i < Q; i++)
    {
        int order, a, b;
        cin >> order >> a >> b;

        if (order == 1)
        {
            // 배열에 있는건 짝수인데 홀수로 바꿀때
            if (arr[a] % 2 == 0 && b % 2 != 0)
                Update(1, 1, N, a, 1, -1);
            // 배열에 있는건 홀수인데 짝수로 바꿀때
            else if (arr[a] % 2 != 0 && b % 2 == 0)
                Update(1, 1, N, a, -1, 1);
            arr[a] = b;
        } else cout << treeCount(1, 1, N, a, b, (order != 2)) << "\n";
        
    }
    
    return 0;
}