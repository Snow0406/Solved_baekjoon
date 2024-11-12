// 참고 : https://justicehui.github.io/icpc/2018/11/25/BOJ3653/, https://velog.io/@rootachieve/백준-3653-영화-수집

#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int T, N, M, order, index1;
vector<int> arr, tree;

void update(int node, int start, int end, int index, int diff)
{
    if (start > index || index > end) return;
    tree[node] += diff;

    if (start != end)
    {
        int mid = (start+end)/2;
        update(node*2, start, mid, index, diff);
        update(node*2+1, mid+1, end, index, diff);
    }
}

int sum(int node, int start, int end, int left, int right)
{
    if (start > right || left > end) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start+end)/2;
    return sum(node*2, start, mid, left, right) + sum(node*2+1, mid+1, end, left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;

    while (T--)
    {
        cin >> N >> M;
        arr = vector<int>(N+M+10);
        tree = vector<int>((N+M+10)*4);

        // 왜 앞부분부터 안하면 나중에 사용하고 나서 위로 올릴때 그때 사용할꺼라
        for (int i = M+1; i <= N+M; i++)
        {
            update(1, 1, N+M, i, 1);
            arr[i-M] = i;
        }

        int index1 = M;

        for (int i = 0; i < M; i++)
        {
            cin >> order;
            cout << sum(1, 1, N+M, 1, arr[order]-1) << " ";
            update(1, 1, N+M, arr[order], -1);
            arr[order] = index1--;
            update(1, 1, N+M, arr[order], 1);
        }
        cout << "\n";
    }
    
    return 0;
}

