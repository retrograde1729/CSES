#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int k = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if(c == '*') dp[i][j] = -1;
        }
    }
    if(dp[0][0] != -1) dp[0][0] = 1;
    if(n > 1)
    {
        if(dp[1][0] != -1) dp[1][0] += dp[0][0];
        if(dp[0][1] != -1) dp[0][1] += dp[0][0];
    }

    for(int j = 1; j < n; j++)
    {
        if(dp[0][j] == -1) continue;
        if(n > 1 && dp[1][j] != -1) dp[1][j] += dp[0][j];
        if(n > j + 1 && dp[0][j + 1] != -1) dp[0][j + 1] += dp[0][j];
    }

    for(int i = 1; i < n; i++)
    {
        if(dp[i][0] == -1) continue;
        if(n > 1 && dp[i][1] != -1) dp[i][1] += dp[i][0];
        if(n > i + 1 && dp[i + 1][0] != -1) dp[i + 1][0] += dp[i][0];
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(dp[i][j] == -1) continue;
            if(n > i + 1 && dp[i + 1][j] != -1) dp[i + 1][j] = (dp[i][j] + dp[i + 1][j]) % k;
            if(n > j + 1 && dp[i][j + 1] != -1) dp[i][j + 1] = (dp[i][j] + dp[i][j + 1]) % k;
        }
    }

    (dp[n - 1][n - 1] > 0) ? cout << dp[n - 1][n - 1] << '\n' : cout << 0 << '\n';
}