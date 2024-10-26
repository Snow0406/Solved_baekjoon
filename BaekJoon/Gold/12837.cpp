#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> arr;
vector<long long> tree;

void Update(int node, int start, int end, int index, int diff)
{
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    int mid = (start+end)/2;
    if (start == end) return;
        Update(node*2, start, mid, index, diff);
        Update(node*2+1, mid+1, end, index, diff);
}

long long Sum(int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start+end)/2;
    return Sum(node*2, start, mid, left, right) + Sum(node*2+1, mid+1, end, left, right);
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

    arr.resize(N);
    tree.resize(treeSize);
    
    for (int i = 0; i < Q; i++)
    {
        int order;
        long long a, b;
        cin >> order >> a >> b;

        if (order == 1)
        {
            Update(1, 1, N, a, b);
        } else cout << Sum(1, 1, N, a, b) << "\n";
        
    }
    
    return 0;
}