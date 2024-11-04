#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
ll mxn = 1e15;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    ll dp[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) 
        {
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = mxn;
        }
    }
    for(int i = 0; i < m; i++)
    {
        ll u, v, d;
        cin >> u >> v >> d;
        dp[u][v] = min(d, dp[--u][--v]);
        dp[v][u] = dp[u][v];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(j != k) dp[j][k] = min(dp[j][i] + dp[i][k], dp[j][k]);
            }
        }
    }

    while(q--)
    {
        int t, f;
        cin >> t >> f;
        if(dp[--t][--f] < mxn ) cout << dp[t][f] << '\n';
        else cout << -1 << '\n';
    }
}