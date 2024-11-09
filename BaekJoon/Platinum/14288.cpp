#include <iostream>
#include <vector>

using namespace std;

int N, M;

bool type;

int tree[400010];
int lazy[400010];
int tree2[400010];
int lazy2[400010];
vector<int> subList[100002]; // 각 노드의 부하 직원들을 저장

int dfs_start_index[100002];
int dfs_end_index[100002];
int arr[100002];
int dfs_arr[100002];
int dfs_count;

// DFS를 이용하여 오일러 경로 생성
void dfs(int num)
{
    dfs_start_index[num] = ++dfs_count;
    dfs_arr[dfs_count] = arr[num];

    // 그 노드의 부하 직원들 DFS 실행
    for(const int next_sub: subList[num])
        dfs(next_sub);

    dfs_end_index[num] = dfs_count;
}

// DFS Arr 기준으로 세그먼트 트리 만들기
void init_tree(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = dfs_arr[start];
        return;
    }

    int mid = (start+end)/2;
    init_tree(node*2, start, mid);
    init_tree(node*2+1, mid+1, end);
}

void update_lazy(int _tree[], int _lazy[], int node, int start, int end)
{
    if (_lazy[node] == 0) return;
    _tree[node] += lazy[node];

    if (start != end)
    {
        _lazy[node*2] += _lazy[node];
        _lazy[node*2+1] += _lazy[node];
    }

    _lazy[node] = 0;
}

void update_range(int _tree[], int _lazy[], int node, int start, int end, int left, int right, int diff)
{
    update_lazy(_tree, _lazy, node, start, end);

    if (left > end || right < start) return;
    
    if (left <= start && end <= right) {
        _tree[node] += diff;
        if (start != end) {
            _lazy[node*2] += diff;
            _lazy[node*2+1] += diff;
        }
        return;
    }

    int mid = (start+end)/2;
    update_range(_tree, _lazy, node*2, start, mid, left, right, diff);
    update_range(_tree, _lazy, node*2+1, mid+1, end, left, right, diff);
}

int query(int _tree[], int _lazy[], int node, int start, int end, int left, int right)
{
    update_lazy(_tree, _lazy, node, start, end);

    if (left > end || right < start) return 0;
    if (start == end) return _tree[node];

    int mid = (start+end)/2;
    return query(_tree, _lazy,node*2, start, mid, left, right) + query(_tree, _lazy, node*2+1, mid+1, end, left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    type = true;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        int index;
        cin >> index;

        if (index != -1)
            subList[index].push_back(i);
    }

    dfs(1);
    init_tree(1, 1, N);

    for (int i = 0; i < M; i++)
    {
        int order;
        cin >> order;

        if (order == 1)
        {
            int a, x;
            cin >> a >> x;
            
            if (type) update_range(tree, lazy, 1, 1, N, dfs_start_index[a], dfs_end_index[a], x);
            else update_range(tree2, lazy2,1, 1, N, dfs_start_index[a], dfs_start_index[a], x);
            
        } else if (order == 2)
        {
            int a;
            cin >> a;
            cout << query(tree, lazy, 1, 1, N, dfs_start_index[a], dfs_start_index[a]) + query(tree2, lazy2, 1, 1, N, dfs_start_index[a], dfs_end_index[a]) << "\n";
            
        } else type = !type;
    }
    
    return 0;
}
