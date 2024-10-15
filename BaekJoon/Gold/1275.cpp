#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long Init(vector<long long>&arr, vector<long long>&tree, int node, int start, int end)
{
    if (start == end)
        return tree[node] = arr[start];
    
    return tree[node] =
            Init(arr, tree, node*2, start, (start+end)/2) + Init(arr, tree, node*2+1, (start+end)/2 + 1, end);
}

void Update(vector<long long>&tree, int node, int start, int end, int index, long long diff)
{
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end)
    {
        Update(tree, node*2, start, (start+end)/2, index, diff);
        Update(tree, node*2+1, (start+end)/2+1, end, index, diff);
    }
}

long long Sum(vector<long long>&tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    return Sum(tree, node*2, start, (start+end)/2, left, right) + Sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    
    vector<long long> arr(N);

    const int h = ceil(log2(N));
    const int treeSize = 1 << (h+1);
    vector<long long> tree(treeSize);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    Init(arr, tree, 1, 0, N-1);
    for (int i = 0; i < Q; i++)
    {
        int x, y;
        long long a, b;
        cin >> x >> y >> a >> b;

        int left, right;

        if (x < y)
            { left = x; right = y; }
        else
            { left = y; right = x; }

        cout << Sum(tree, 1, 0, N-1, left-1, right-1) << "\n";
        
        Update(tree, 1, 0, N-1, a - 1, b - arr[a - 1]);
        arr[a-1] = b;
    }
    
    return 0;
}