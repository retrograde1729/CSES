#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int mxn = 2e5 + 1;
vector<vector<int>> lift(mxn, vector<int> (31, 0));
vector<int> depth(mxn, 0), path(mxn, 0);
vector<int> adj[mxn];

int lca(int u, int v)
{
    if(depth[u] > depth[v]) swap(u, v);
    int h = depth[v] - depth[u];
    for(int i = 0; i < 31; i++) if(h & (1 << i)) v = lift[v][i];
    if(u == v) return u;
    for(int i = 30; i >= 0; i--) if(lift[u][i] != lift[v][i]) u = lift[u][i], v = lift[v][i];
    return lift[v][0];
}

void dfs(int i, int p)
{
    lift[i][0] = p;
    for(int k = 1; k < 31; k++) lift[i][k] = lift[lift[i][k - 1]][k - 1];
    for(int j : adj[i])
    {
        if(j != p)
        {
            depth[j] = depth[i] + 1;
            dfs(j, i);
        }
    }
}

void find(int i, int p)
{
    for(int j : adj[i])
    {
        if(j != p) 
        {
            find(j, i);
            path[i] += path[j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    for(int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, 0);

    while(m--)
    {
        int a, b;
        cin >> a >> b, --a, --b;
        int x = lca(a, b);
        path[a] += 1, path[b] += 1, path[x] -= 1;
        if(x) path[lift[x][0]] -= 1;
    }

    find(0, -1);

    for(int i = 0; i < n; i++) cout << path[i] << ' ';
}