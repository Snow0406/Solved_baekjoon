#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> people(N);
    
    for(int i = 0; i < N; i++)
        cin >> people[i];
    
    vector<long long> dp(N+1, 0);
    
    dp[0] = 0;
    dp[1] = people[0];
    
    for(int i = 2; i <= N; i++) {
        dp[i] = dp[i-1] + people[i-1];
        dp[i] = min(dp[i], dp[i-2] + max(people[i-1], people[i-2]));
    }
    
    cout << dp[N] << "\n";
    
    return 0;
}