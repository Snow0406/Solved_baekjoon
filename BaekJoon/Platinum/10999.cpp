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
        return tree[node] = Init(node*2,start,mid) + Init(node*2+1,mid+1,end);
    }
}

void Update_Lazy(int node, int start, int end)
{
    // 업데이트 해야되는 데이터가 없으면
    if (lazy[node] == 0) return;
    tree[node] += (end-start+1) * lazy[node];

    // 리프 노드가 아니라면 자식 노드도 업데이트
    if (start != end)
    {
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

void Update_Range(int node, int start, int end, int left, int right, long long diff)
{
    Update_Lazy(node, start, end);
    
    if (left > end || right < start) return;
    
    if (left <= start && end <= right) {
        tree[node] += ( end-start+1 )* diff;
        if (start != end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    int mid = (start+end)/2;
    Update_Range(node*2, start, mid, left, right, diff);
    Update_Range(node*2+1, mid+1, end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

long long Sum(int node, int start, int end, int left, int right) {
    Update_Lazy(node, start, end);
    
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start+end)/2;
    return Sum(node*2, start, mid, left, right) + Sum(node*2+1, mid+1, end, left, right);
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    int h = static_cast<int>(ceil(log2(N)));
    int treeSize = (1 << (h+1));

    M += K;

    arr.resize(N);
    lazy.resize(treeSize, 0);
    tree.resize(treeSize, 0);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    Init(1, 0, N-1);

    while (M--)
    {
        int order;
        cin >> order;

        if (order == 1)
        {
            int s, e;
            long long value;
            cin >> s >> e >> value;
            Update_Range(1, 0, N-1, s-1, e-1, value);
        } else if (order == 2)
        {
            int s, e;
            cin >> s >> e;
            cout << Sum(1, 0, N-1, s-1, e-1) << "\n";
        }
    }
    
    return 0;
}