#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

//세그먼트 트리 공부중

int InitMin(vector<int>& arr, vector<int>& tree, int node, int start, int end)
{
    if (start == end)
        return tree[node] = arr[start];
    else
        return tree[node] = min(InitMin(arr, tree, node * 2, start,
                             ((start + end) / 2)),
    InitMin(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end));
}

int FindMin(vector<int>& tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return INT_MAX;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    return min(FindMin(tree, node * 2, start, (start + end) / 2, left, right),
    FindMin(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int InitMax(vector<int>& arr, vector<int>& tree, int node, int start, int end)
{
    if (start == end)
        return tree[node] = arr[start];
    else
        return tree[node] = max(InitMax(arr, tree, node * 2, start,
                             ((start + end) / 2)),
    InitMax(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end));
}

int FindMax(vector<int>& tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return INT_MIN;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    return max(FindMax(tree, node * 2, start, (start + end) / 2, left, right),
    FindMax(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    const int h = ceil(log2(N)); 
    const int tree_size = 1 << (h+1); 
    vector<int> treeMin(tree_size);
    vector<int> treeMax(tree_size);

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    InitMin(arr, treeMin, 1, 0, N-1);
    InitMax(arr, treeMax, 1, 0, N-1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << FindMin(treeMin, 1, 0, N-1, a-1, b-1) << "\n";
        cout << FindMax(treeMax, 1, 0, N-1, a-1, b-1) << "\n";
    }
    return 0;
}
