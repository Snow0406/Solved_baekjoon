#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//출처: https://www.acmicpc.net/blog/view/9
//세그먼트 트리 공부중

// arr: 배열 arr
// tree: 세그먼트 트리
// node: 세그먼트 트리 노드 번호
// node가 담당하는 합의 범위가 start ~ end
long long Init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
    if (start == end)
        return tree[node] = arr[start];
    else
        return tree[node] = Init(arr, tree, node * 2, start,
                             ((start + end) / 2)) +
                             Init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

void Update(vector<long long>& tree, int node, int start, int end, int index, long long diff)
{
    //[start,end]에 index가 포함되지 않는 경우 리턴
    if (index < start || index > end) return;
    //[start,end]에 index가 포함되는 경우
    tree[node] = tree[node] + diff;
    if (start != end) //근데 리프 노드가 아니면 자식도 바꿔야 함
    {
        Update(tree, node * 2, start, (start + end) / 2, index, diff);
        Update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}

// node가 담당하는 구간이 start~end이고, 구해야하는 합의 범위는 left~right
long long sum(vector<long long>& tree, int node, int start, int end, int left, int right)
{
    //  1. [left,right]와 [start,end]가 겹치지 않는 경우 -
    //  겹치지 않기 때문에, 더 이상 탐색을 이어나갈 필요가 없습니다.
    if (left > end || right < start)
    {
        return 0;
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
    return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(
        tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, K;
    cin >> N >> M >> K;

    vector<long long> arr(N);
    const int h = ceil(log2(N)); //트리의 높이

    //세그먼트 트리의 크기 == 2^(h+1) - 1;
    //1 << (h+1) - 1을 안한 이유는 구현의 편의를 위해 저런식으로 함
    int tree_size = 1 << (h+1); 
    vector<long long> tree(tree_size);
    
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    Init(arr, tree, 1, 0, N-1);
    for (int i = 0; i < M+K; i++)
    {
        int order, left;
        long long right;
        cin >> order >> left >> right;

        if (order == 1)
        {
            //left 인덱스에 right로 바꾸는것
            left -= 1; //1을 뺴는 이유는 배열 인덱스가 0부터 시작해서
            long long diff = right - arr[left];
            arr[left] = right;
            Update(tree, 1, 0, N-1, left, diff);
        } else if (order == 2)
        {
            cout << sum(tree, 1, 0, N-1, left-1, right-1) << "\n";
        }
    }
    return 0;
}
