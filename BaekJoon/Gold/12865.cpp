#include <iostream>
#include <cmath>

#define MAX 101

using namespace std;

int n, k;
int w[MAX] = {0, };
int v[MAX] = {0, };
int dp[MAX][100001];

int main()
{
    cin >> n >> k;
    //데이터 추가
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int limit = 1; limit <= k; limit++)
    {
        for (int kk = 1; kk <= n; kk++)
        {
            if(w[kk] > limit)
            {
                dp[kk][limit] = dp[kk-1][limit];
            } else {
                dp[kk][limit] = max(dp[kk-1][limit-w[kk]] + v[kk], dp[kk-1][limit]);
            }
        }
    }
    

    cout << dp[n][k];
    return 0;
}

