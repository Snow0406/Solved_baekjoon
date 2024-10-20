#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

struct Node
{
    int num = INT_MAX, index = INT_MAX;
};

bool operator < (const Node &a, const Node &b){
    if(a.num == b.num) return a.index < b.index;
    else return a.num < b.num;
}

Node Init(vector<int>&arr, vector<Node>&tree, int node, int start, int end) {
    if (start == end)
        return tree[node] = {arr[start], start};
    
    int mid = (start + end) / 2;
    return tree[node] = min(Init(arr, tree, node*2, start, mid), Init(arr, tree, node*2+1, mid + 1, end));
}

void Update(vector<Node>&tree, int node, int start, int end, int index, int newValue) {
    if (index < start || index > end) return;
    
    if (start == end) {
        tree[node] = {newValue, index};
        return;
    }
    
    int mid = (start + end) / 2;
    Update(tree, node*2, start, mid, index, newValue);
    Update(tree, node*2+1, mid+1, end, index, newValue);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

Node FindMin(vector<Node>&tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return { INT_MAX, INT_MAX };
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return min(FindMin(tree, node*2, start, mid, left, right), FindMin(tree, node*2+1, mid+1, end, left, right));
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
    vector<Node> tree(treeSize);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cin >> M;

    Init(arr, tree, 1, 0, N-1);
        
    for (int i = 0; i < M; i++) {
        int order, a, b;
        cin >> order >> a >> b;

        if (order == 1) {
            Update(tree, 1, 0, N-1, a-1, b);
        } else if (order == 2) {
            cout << FindMin(tree, 1, 0, N-1, a-1, b-1).index + 1 << "\n";
 
        }
    }
    
    return 0;
}