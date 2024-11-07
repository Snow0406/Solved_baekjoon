#include <iostream>
#include <vector>

using namespace std;

int N, M;

int tree[2000000];
int lazy[2000000];
vector<int> subList[500001]; // 각 노드의 부하 직원들을 저장

int dfs_start_index[500001];
int dfs_end_index[500001];
int arr[500001];
int dfs_arr[500001];
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

void update_lazy(int node, int start, int end)
{
    if (lazy[node] == 0) return;
    tree[node] += lazy[node];

    if (start != end)
    {
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }

    lazy[node] = 0;
}

void update_range(int node, int start, int end, int left, int right, long long diff)
{
    update_lazy(node, start, end);

    if (left > end || right < start) return;
    
    if (left <= start && end <= right) {
        tree[node] += diff;
        if (start != end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }

    int mid = (start+end)/2;
    update_range(node*2, start, mid, left, right, diff);
    update_range(node*2+1, mid+1, end, left, right, diff);
}

void query(int node, int start, int end, int index)
{
    update_lazy(node, start, end);

    if (index > end || index < start) return;
    if (start == end)
    {
        cout << tree[node] << "\n";
        return;
    }

    int mid = (start+end)/2;
    query(node*2, start, mid, index);
    query(node*2+1, mid+1, end, index);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

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
        int order, a;
        cin >> order >> a;

        if (order == 1)
        {
            long long x;
            cin >> x;
            // dfs_start_index[a] + 1 을 하는 이유는 나 빼고 부하들만 월급 넣어야 되서
            update_range(1, 1, N, dfs_start_index[a], dfs_end_index[a], x);
        } else
        {
            query(1, 1, N, dfs_start_index[a]);
        }
    }
    
    return 0;
}
