// 출처 : https://cocoon1787.tistory.com/314
// 몰라서 보고 참고함

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

vector<int> arr;
vector<long long> tree;
int N;
long long result;

long long Init(int node, int start, int end) {
    if (start == end)
        return tree[node] = start;

    int mid = (start + end) / 2;
    int leftIndex = Init(node << 1, start, mid);
    int rightIndex = Init((node << 1)+1, mid+1, end);
    
    return tree[node] = arr[leftIndex] > arr[rightIndex] ? rightIndex : leftIndex;
}

long long FindMinIndex( int node, int start, int end, int left, int right) {

    // 범위가 겹치지 않는 경우
    if (end < left || right < start) return INT_MAX;

    // 완전히 포함되는 경우
    if (left <= start && end <= right) return tree[node];
    
    int mid = (start + end)/2;
    int leftIndex =  FindMinIndex(node << 1, start, mid, left, right);
    int rightIndex = FindMinIndex((node << 1)+1, mid+1, end, left, right);

    if (leftIndex == INT_MAX) return rightIndex;
    else if (rightIndex == INT_MAX) return leftIndex;
    else return arr[leftIndex] > arr[rightIndex] ? rightIndex : leftIndex;
}

void Solve(long long left, long long right) {
    if (left > right) return;

    // 가장 낮은 높이를 가진 인덱스 찾기
    long long index = FindMinIndex(1, 0, N-1, left, right);

    result = max(result, arr[index] * (right - left + 1));

    Solve(left, index-1);
    Solve(index+1, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true)
    {
        result = 0;
        cin >> N;

        if (N == 0) break;
        
        const int h = ceil(log2(N));
        const int treeSize = 1 << (h+1);

        arr.resize(N);
        tree.resize(treeSize);

        for (int i = 0; i < N; i++)
            cin >> arr[i];
        
        Init(1, 0, N-1);
        Solve(0, N-1);
        cout << result << "\n";
    }
    
    return 0;
}