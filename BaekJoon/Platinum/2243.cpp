#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

#define MAX 1000001

vector<long long> arr;
vector<long long> tree;

int Query(int node, int start, int end, int index)
{
    if (start == end) return end;

    int mid = (start + end)/2;
    if (tree[node * 2] >= index)
        return Query(node*2, start, mid, index);
    else
        return Query(node*2+1, mid+1, end, index - tree[node * 2]);
}

void Update(int node, int start, int end, int index, long long value)
{
    if (index < start || index > end) return;
    
    if (start == end)
    {
        tree[node] = value;
        return;
    }
    
    int mid = (start+end)/2;
    Update(node*2, start, mid, index, value);
    Update(node*2+1, mid+1, end, index, value);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    const int h = ceil(log2(MAX));
    const int treeSize = 1 << (h+1);

    arr.resize(MAX);
    tree.resize(treeSize);

    int order;
    long long a, b;
    
    for (int i = 0; i < N; i++)
    {
        cin >> order;

        if (order == 1)
        {
            cin >> a;
            int taste = Query(1, 1, MAX, a);
            cout << taste << "\n";
            Update(1, 1, MAX, taste, arr[taste] - 1);
            arr[taste]--;
        } else
        {
            cin >> a >> b;
            Update(1, 1, MAX, a, arr[a] + b);
            arr[a] += b;
        }
        
    }
    
    return 0;
}