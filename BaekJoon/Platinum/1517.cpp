// 출처 : https://restudycafe.tistory.com/379
// 몰라서 보고 참고함

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

// struct Node
// {
//     int value, index;
//     bool operator < (const Node &other) const
//     {
//         return value < other.value;
//     }
// };

vector<pair<long, long>> arr;
vector<int> tree;
int N, value;
long long result;

// 이 문제의 세그먼트 트리는 일반적인 최소/최대값을 저장하는게 아니라서 Init 함수가 필요없음

void Update( int node, int start, int end, int index) {

    // 리프 노드에 도달했을떄
    if (start == end)
    {
        tree[node] = 1;
        return;
    }
    
    int mid = (start + end)/2;

    // 업데이트할 인덱스가 왼쪽에 있을떄
    if (index <= mid)
        Update(node*2, start, mid, index);
    else
        Update((node*2)+1, mid+1, end, index);

    // 부모 노드 갱신
    tree[node] = tree[node*2] + tree[(node*2)+1];
}

// 주어진 구간 left, right 애서 처리된 숫자의 개수를 반환하는 함수
long long Query(int node, int start, int end, int left, int right) {

    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];

    long long mid = (start+end)/2;
    long long leftQuery = Query(node*2, start, mid, left, right);
    long long rightQuery = Query((node*2)+1, mid+1, end, left, right);
    return leftQuery + rightQuery;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
        
    const int h = ceil(log2(N));
    const int treeSize = 1 << (h+1);

    arr.resize(N);
    tree.resize(treeSize);

    // for (int i = 0; i < N; i++)
    // {
    //     cin >> value;
    //     arr.push_back({value, i});
    // }
    for (int i = 0; i < N; i++)
    {
        cin >> value;
        arr[i] = {value, i};
    }
    
    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++)
    {
        // result += (Query(1, 0, N - 1, arr[i].index + 1, N - 1));
        // Update(1, 0, N-1, arr[i].index);
        result += (Query(1, 0, N - 1, arr[i].second + 1, N - 1));
        Update(1, 0, N-1, arr[i].second);
    }

    cout << result << "\n";
    
    return 0;
}