#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<long long> arr;
vector<long long> lazy;
vector<long long> tree;

long long Init(int node, int start, int end)
{
    if (start == end)
        return tree[node] = arr[start];
    else
    {
        int mid = (start+end)/2;
        return tree[node] = Init(node*2,start,mid) ^ Init(node*2+1,mid+1,end);
    }
}

void Update_Lazy(int node, int start, int end)
{
    // 업데이트 해야되는 데이터가 없으면
    if (lazy[node] == 0) return;

    if ((end-start+1) % 2 == 1)
        tree[node] ^= lazy[node];
    
    // 리프 노드가 아니라면 자식 노드도 업데이트
    if (start != end)
    {
        lazy[node*2] ^= lazy[node];
        lazy[node*2+1] ^= lazy[node];
    }
    lazy[node] = 0;
}

void Update_Range(int node, int start, int end, int left, int right, int diff)
{
    Update_Lazy(node, start, end);
    
    if (left > end || right < start) return;
    
    if (left <= start && end <= right) {
        if((end - start + 1) % 2 == 1)
            tree[node] ^= diff;
        if (start != end) {
            lazy[node*2] ^= diff;
            lazy[node*2+1] ^= diff;
        }
        return;
    }
    int mid = (start+end)/2;
    Update_Range(node*2, start, mid, left, right, diff);
    Update_Range(node*2+1, mid+1, end, left, right, diff);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}

long long Query(int node, int start, int end, int left, int right) {
    Update_Lazy(node, start, end);
    
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start+end)/2;
    int leftQuery = Query(node*2, start, mid, left, right);
    int rightQuery = Query(node*2+1, mid+1, end, left, right);
    return leftQuery ^ rightQuery;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, M;
    cin >> N;

    int h = static_cast<int>(ceil(log2(N)));
    int treeSize = (1 << (h+1));

    arr.resize(N);
    lazy.resize(treeSize, 0);
    tree.resize(treeSize, 0);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    Init(1, 0, N-1);

    cin >> M;

    int order, a, b, c;
    while (M--)
    {
        cin >> order >> a >> b;

        if (order == 1)
        {
            cin >> c;
            Update_Range(1, 0, N-1, a, b, c);
        } else if (order == 2)
        {
            cout << Query(1, 0, N-1, a, b) << "\n";
        }
    }
    
    return 0;
}