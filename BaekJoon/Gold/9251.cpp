#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    a = "0" + a;
    b = "0" + b;

    vector<vector<int>> dp;
    dp.resize(a.size(), vector<int>(b.size()));

    for (int i = 0; i < static_cast<int>(a.size()); i++)
    {
        for (int j = 0; j < static_cast<int>(b.size()); j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[static_cast<int>(a.size())-1][static_cast<int>(b.size())-1] << "\n";
    
    
    return 0;
}