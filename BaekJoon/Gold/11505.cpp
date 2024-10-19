#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long Init(vector<long long>&arr, vector<long long>&tree, int node, int start, int end) {
    if (start == end)
        return tree[node] = arr[start];
    
    int mid = (start + end) / 2;
    return tree[node] = (Init(arr, tree, node*2, start, mid) * Init(arr, tree, node*2+1, mid + 1, end)) % 1000000007;
}

void Update(vector<long long>&tree, int node, int start, int end, int index, long long newValue) {
    if (index < start || index > end) return;
    
    if (start == end) {
        tree[node] = newValue;
        return;
    }
    
    int mid = (start + end) / 2;
    Update(tree, node*2, start, mid, index, newValue);
    Update(tree, node*2+1, mid+1, end, index, newValue);
    
    tree[node] = (tree[node*2] * tree[node*2+1]) % 1000000007;
}

long long Multi(vector<long long>&tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return 1;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return (Multi(tree, node*2, start, mid, left, right) * Multi(tree, node*2+1, mid+1, end, left, right)) % 1000000007;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
        const int h = ceil(log2(N));
        const int treeSize = 1 << (h+1);

        vector<long long> arr(N);
        vector<long long> tree(treeSize);

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Init(arr, tree, 1, 0, N-1);
        
        for (int i = 0; i < M+K; i++) {
            int order;
            long long a, b;
            cin >> order >> a >> b;

            if (order == 1) {
                Update(tree, 1, 0, N-1, a-1, b);
            } else if (order == 2) {
                cout  << Multi(tree, 1, 0, N-1, a-1, b-1) << "\n";
 
            }
        }
    
    return 0;
}