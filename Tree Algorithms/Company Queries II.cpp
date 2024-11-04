#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int mxn = 2e5 + 1;
vector<vector<int>> lift(mxn, vector<int> (31, 0));
vector<int> depth(mxn, 0);
vector<int> adj[mxn];

int lca(int u, int v)
{
    if(depth[u] > depth[v]) swap(u, v);
    int h = depth[v] - depth[u];
    for(int i = 0; i < 31; i++) if(h & (1 << i)) v = lift[v][i];
    if(u == v) return v;
    for(int i = 31; i >= 0; i--) if(lift[u][i] != lift[v][i]) u = lift[u][i], v = lift[v][i];
    return lift[v][0];
}

int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++) cin >> lift[i][0], --lift[i][0];

    for(int i = 1; i < 31; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(lift[j][i - 1]) lift[j][i] = lift[lift[j][i - 1]][i - 1];
        }
    }

    for(int i = 1; i < n; i++)
    {
        adj[lift[i][0]].push_back(i);
    }

    queue<int> qu;
    qu.push(0);
    depth[0] = 0;

    while(qu.size())
    {
        int node = qu.front();
        qu.pop();

        for(int i : adj[node])
        {
            depth[i] = depth[node] + 1;
            qu.push(i);
        }
    }

    while(q--)
    {
        int u, v;
        cin >> u >> v, --u, --v;
        cout << lca(u, v) + 1 << '\n';  
    }
}