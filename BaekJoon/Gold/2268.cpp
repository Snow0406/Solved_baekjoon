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

    const int h = ceil(log2(N));
    const int treeSize = 1 << (h+1);

    vector<long long> arr(N);
    vector<long long> tree(treeSize);

    Init(arr, tree, 1, 0, N-1);
    for (int i = 0; i < Q; i++)
    {
        int order;
        long long a, b;
        cin >> order >> a >> b;

        if (order == 0)
        {
            if (a > b)
                swap(a, b);
            cout << Sum(tree, 1, 0, N-1, a-1, b-1) << "\n";   
        } else if (order == 1)
        {
            Update(tree, 1, 0, N-1, a - 1, b - arr[a - 1]);
            arr[a-1] = b;   
        }
    }
    
    return 0;
}