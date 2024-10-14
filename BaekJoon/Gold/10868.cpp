#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

//세그먼트 트리 공부중

int Init(vector<int>& arr, vector<int>& tree, int node, int start, int end)
{
    if (start == end)
        return tree[node] = arr[start];
    else
        return tree[node] = min(Init(arr, tree, node * 2, start,
                             ((start + end) / 2)),
    Init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end));
}

int FindMin(vector<int>& tree, int node, int start, int end, int left, int right)
{
    //  1. [left,right]와 [start,end]가 겹치지 않는 경우 -
    //  겹치지 않기 때문에, 더 이상 탐색을 이어나갈 필요가 없습니다.
    if (left > end || right < start)
    {
        return INT_MAX;
    }
    //  2. [left,right]가 [start,end]를 완전히 포함하는 경우
    // 구해야하는 합의 범위는 [left,right]인데, [start,end]는 그 범위에 모두 포함되고,
    // 그 node의 자식도 모두 포함되기 때문에 더 이상 호출을 하는 것은 비효율적
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    //  3. [start,end]가 [left,right]를 완전히 포함하는 경우
    //  4. [left,right]와 [start,end]가 겹쳐져 있는 경우 (1, 2, 3 제외한 나머지 경우)
    return min(FindMin(tree, node * 2, start, (start + end) / 2, left, right),
    FindMin(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    const int h = ceil(log2(N)); //트리의 높이

    //세그먼트 트리의 크기 == 2^(h+1) - 1;
    //1 << (h+1) - 1을 안한 이유는 구현의 편의를 위해 저런식으로 함
    int tree_size = 1 << (h+1); 
    vector<int> tree(tree_size);
    
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    Init(arr, tree, 1, 0, N-1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << FindMin(tree, 1, 0, N-1, a-1, b-1) << "\n";
    }
    return 0;
}
