#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int convert(int num) {
    if (num == 0) return 0;
    else if(num > 0) return 1;
    else return -1;
}

int Init(vector<int>&arr, vector<int>&tree, int node, int start, int end) {
    if (start == end)
        return tree[node] = convert(arr[start]);
    
    int mid = (start + end) / 2;
    return tree[node] = Init(arr, tree, node*2, start, mid) * Init(arr, tree, node*2+1, mid + 1, end);
}

void Update(vector<int>&arr, vector<int>&tree, int node, int start, int end, int index, int newValue) {
    if (index < start || index > end) return;
    
    if (start == end) {
        arr[index] = newValue;
        tree[node] = convert(newValue);
        return;
    }
    
    int mid = (start + end) / 2;
    Update(arr, tree, node*2, start, mid, index, newValue);
    Update(arr, tree, node*2+1, mid+1, end, index, newValue);
    
    tree[node] = tree[node*2] * tree[node*2+1];
}

int Query(vector<int>&tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return 1;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return Query(tree, node*2, start, mid, left, right) * Query(tree, node*2+1, mid+1, end, left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    while (cin >> N >> K) {
        const int h = ceil(log2(N));
        const int treeSize = 1 << (h+1);

        vector<int> arr(N);
        vector<int> tree(treeSize);

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Init(arr, tree, 1, 0, N-1);
        
        string result = "";
        for (int i = 0; i < K; i++) {
            char order;
            int a, b;
            cin >> order >> a >> b;

            if (order == 'C') {
                Update(arr, tree, 1, 0, N-1, a-1, b);
            } else if (order == 'P') {
                int queryResult = Query(tree, 1, 0, N-1, a-1, b-1);
                if (queryResult == 0) result += "0";
                else if (queryResult > 0) result += "+";
                else result += "-";
            }
        }

        cout << "답이다 이새깨 ! " << result << "\n";
    }
    
    return 0;
}