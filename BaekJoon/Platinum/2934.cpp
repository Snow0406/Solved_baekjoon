#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr;
vector<long long> lazy;
vector<long long> tree;

void Update_Lazy(int node, int start, int end)
{
    if (lazy[node] == 0) return;
    tree[node] += (end-start+1) * lazy[node];
    
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
        tree[node] += ( end-start+1 );
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

void Update_Point(int node, int start, int end, int left, int right)
{
    Update_Lazy(node, start, end);

    if (left > end || right < start) return;

    if(start == end)
    {
        tree[node] = 0;
        return;
    }

    int mid = (start+end)/2;
    Update_Point(node*2, start, mid, left, right);
    Update_Point(node*2+1, mid+1, end, left, right);
    tree[node] = tree[node*2] + tree[node*2+1];
}

long long Value(int node, int start, int end, int left, int right) {
    Update_Lazy(node, start, end);
    
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start+end)/2;
    return Value(node*2, start, mid, left, right) + Value(node*2+1, mid+1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;

    arr.resize(100001);
    lazy.resize(100001 * 4, 0);
    tree.resize(100001 * 4, 0);
    
    while (N--)
    {
        int a, b;
        cin >> a >> b;

        // 꽃이 생길 가능성이 있으면
        if (a + 1 < b)
            Update_Range(1, 0, 100000, a, b-2);

        long long result = Value(1, 0, 100000, a-1, a-1) + Value(1, 0, 100000, b-1, b-1);
        cout << result << "\n";

        Update_Point(1, 0, 100000, a-1, a-1);
        Update_Point(1, 0, 100000, b-1, b-1);
    }
    
    return 0;
}