#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int mxn = 2e5 + 1;
vector<int> adj[mxn];
vector<vector<int>> dist(mxn, vector<int> (2, 0));

int dfs(int i, int p)
{
    for(int j : adj[i])
    {
        if(j == p) continue;
        int x = dfs(j, i);
        if(x >= dist[i][1])
        {
            dist[i][0] = dist[i][1];
            dist[i][1] = x;
        }
        else if(x > dist[i][0]) dist[i][0] = x;
    }

    return dist[i][1] + 1;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, -1);
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, dist[i][0] + dist[i][1]);
    cout << ans;
}