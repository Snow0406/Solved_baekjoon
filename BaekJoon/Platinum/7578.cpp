// 문제 이해 할려고 본거 출처 : https://foxtrotin.tistory.com/164

#include <iostream>

using namespace std;

int N;
int A[500001], B[1000001];
int tree[1000001*4];

void update(int node, int start, int end, int index)
{
    if (start > index || end < index) return;
    if (start == end)
    {
        tree[node] = 1;
        return;
    }

    int mid = (start+end)/2;
    update(node*2, start, mid, index);
    update(node*2+1, mid+1, end, index);
    tree[node] = tree[node*2] + tree[node*2+1];
}

long long sum(int node, int start, int end, int left, int right)
{
    if (end < left || start > right) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start+end)/2;
    return sum(node*2, start, mid, left, right) + sum(node*2+1, mid+1, end, left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        B[num] = i;
    }

    long long result = 0;
    for (int i = 0; i < N; i++)
    {
        result += sum(1, 0, N-1, B[A[i]]+1, N-1);
        update(1, 0, N-1, B[A[i]]);
    }

    cout << result << "\n";

    return 0;
}