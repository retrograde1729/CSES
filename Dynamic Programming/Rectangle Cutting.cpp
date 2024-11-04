#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;  
const int inf = 1e8;

int main()
{
    int l, b;
    cin >> l >> b;
    int dp[l][b];

    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < b; j++)
        {
            dp[i][j] = inf;
        }
    }

    dp[0][0] = 0;
    for(int i = 1; i < l; i++) dp[i][0] = i;
    for(int i = 1; i < b; i++) dp[0][i] = i;

    for(int i = 1; i < l; i++)
    {
        for(int j = 1; j < b; j++)
        {
            if(i == j) dp[i][j] = 0;
            else
            {
                for(int k = 1; k <= max(i, j); k++)
                {
                    if(j - k >= 0)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k - 1] + 1);
                    }
                    if(i - k >= 0)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k - 1][j] + 1);
                    }
                }
            }
        }
    }
    
    // for(int i = 0; i < l; i++)
    // {
    //     for(int j = 0; j < b; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[l - 1][b - 1] << '\n';
}