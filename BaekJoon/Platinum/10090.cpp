// 참고 : https://nakuri.tistory.com/m/96

#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N;
vector<int> arr;
vector<int> tree(1000010 * 4);

void update(int node, int start, int end, int index)
{
    if (start > index || index > end) return;
    if (start == end)
    {
        tree[node]++;
        return;
    }

    int mid = (start+end)/2;
    update(node*2, start, mid, index);
    update(node*2+1, mid+1, end, index);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int node, int start, int end, int left, int right)
{
    if (start > right || left > end) return 0;
    if (start >= left && end <= right) return tree[node];

    int mid = (start+end)/2;
    return query(node*2, start, mid, left, right) + query(node*2+1, mid+1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    arr.resize(N);

    long long result = 0;
    int input;
    for (int i = 1; i <= N; i++)
    {
        cin >> input;
        update(1, 1, N, input);
        result += query(1, 1, N, input+1, N);
    }

    cout << result << "\n";
    
    return 0;
}

