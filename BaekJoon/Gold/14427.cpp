#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

long long Find_MinIndex(const vector<int>&arr, int a, int b);

long long Init(vector<int>&arr, vector<long long>&tree, int node, int start, int end) {
    if (start == end)
        return tree[node] = start;
    
    int mid = (start + end) / 2;
    return tree[node] = Find_MinIndex(arr, Init(arr, tree, node * 2, start, mid),
                                      Init(arr, tree, node * 2 + 1, mid + 1, end));
}

void Update(vector<int>&arr, vector<long long>&tree, int node, int start, int end, int index) {
    if (index < start || index > end || start == end) return;
    
    int mid = (start + end) / 2;
    Update(arr, tree, node*2, start, mid, index);
    Update(arr, tree, node*2+1, mid+1, end, index);
    tree[node] = Find_MinIndex(arr, tree[node*2], tree[node*2+1]);
}

long long Find_MinIndex(const vector<int>&arr, int a, int b)
{
    if (arr[a] == arr[b]) return min(a, b);
    else return arr[a] < arr[b] ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N;
    const int h = ceil(log2(N));
    const int treeSize = 1 << (h+1);

    vector<int> arr(N);
    vector<long long> tree(treeSize);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cin >> M;

    Init(arr, tree, 1, 0, N-1);
        
    for (int i = 0; i < M; i++) {
        int order, a, b;
        cin >> order;

        if (order == 1) {
            cin >> a >> b;
            arr[a-1] = b;
            Update(arr, tree, 1, 0, N-1, a-1);
        } else if (order == 2) {
            cout << tree[1]+1 << "\n";
 
        }
    }
    
    return 0;
}