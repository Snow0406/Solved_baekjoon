#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> coin(N+1);
    vector<int> dp(K+1);

    for (int i = 0; i < N; i++)
        cin >> coin[i];

    dp[0] = 1; //0 코인을 만드는 경우의 수가 1임 (코인을 아예 안 넣는것도 경우의 수에 포함)
    for (int i = 0; i < N; i++)
    {
        for (int j = coin[i]; j <= K; j++)
        {
            dp[j] = dp[j] + dp[j - coin[i]]; //그 코인을 이용한 경우의 수 업데이트
            /*
             * 예시
             *
             * j = 3
             * dp[3] = dp[3] + dp[0]
             * 기존 3원 만드는 경우의 수에 0원 만드는 경우의 수 더하기
             *
             * j = 4
             * dp[4] = dp[4] + dp[1]
             * 기존 4원 만드는 경우의 수에 1원 만드는 경우의 수 더하기
             *
             * j = 5
             * dp[5] = dp[5] + dp[2]
             * 기존 5원 만드는 경우의 수에 2원 만드는 경우의 수 더하기
             */
        }
    }
    cout << dp[K] << endl;
}

