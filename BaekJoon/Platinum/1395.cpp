#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<long long> lazy;
vector<long long> tree;

void Update_Lazy(int node, int start, int end)
{
    // 업데이트 해야되는 데이터가 없으면
    if (lazy[node] == 0 || lazy[node] % 2 == 0) return;
    
        tree[node] = (end-start+1) - tree[node];

        // 리프 노드가 아니라면 자식 노드도 업데이트
        if (start != end)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }   
    lazy[node] = 0;
}

void Update_Range(int node, int start, int end, int left, int right)
{
    Update_Lazy(node, start, end);
    
    if (left > end || right < start) return;
    
    if (left <= start && end <= right) {
        tree[node] = (end-start+1) - tree[node];
        if (start != end) {
            lazy[node*2] += 1;
            lazy[node*2+1] += 1;
        }
        return;
    }
    int mid = (start+end)/2;
    Update_Range(node*2, start, mid, left, right);
    Update_Range(node*2+1, mid+1, end, left, right);
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;

    int h = static_cast<int>(ceil(log2(N)));
    int treeSize = (1 << (h+1));
    
    lazy.resize(treeSize, 0);
    tree.resize(treeSize, 0);

    int order, s, e;
    while (M--)
    {
        cin >> order >> s >> e;

        if (order == 0)
        {
            Update_Range(1, 1, N, s, e);
        } else if (order == 1)
        {
            cout << Sum(1, 1, N, s, e) << "\n";
        }
    }
    
    return 0;
}