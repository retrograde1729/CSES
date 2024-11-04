#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int mxn = 2e5 + 1;
vector<vector<int>> dp(mxn, vector<int> (2, 0));
vector<int> adj[mxn];

void dfs(int i, int par)
{
    int val = mxn;
    bool flag = false;
    for(int j : adj[i])
    {
        if(j != par) 
        {
            flag = true;
            dfs(j, i);
            dp[i][0] += dp[j][1];
            val = min(val, dp[j][1] - dp[j][0]);
        }
    }
    if(flag) dp[i][1] = dp[i][0] - val + 1;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);
    cout << dp[0][1];
}