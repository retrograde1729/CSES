#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int mxn = 2e5 + 1;
vector<int> adj[mxn];
vector<vector<int>> dist(mxn, vector<int> (2, 0));
vector<vector<int>> node(mxn, vector<int> (2, 0));
vector<int> soln(mxn, 0);

int dfs1(int i, int p)
{
    for(int j : adj[i])
    {
        if(j == p) continue;
        int x = dfs1(j, i);
        if(x >= dist[i][1])
        {
            dist[i][0] = dist[i][1];
            dist[i][1] = x;
            node[i][0] = node[i][1];
            node[i][1] = j;
        }
        else if(x > dist[i][0]) dist[i][0] = x, node[i][0] = j;
    }

    return dist[i][1] + 1;
}

void dfs2(int val, int i, int p)
{
    soln[i] = max(val + 1, dist[i][1]);
    for(int j : adj[i]) 
    {
        if(j != p) 
        {
            if(j == node[i][1]) dfs2(max(val + 1, dist[i][0]), j, i);
            else dfs2(soln[i], j, i);
        }
    }
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
    
    dfs1(0, -1);
    dfs2(-1, 0, -1);
    for(int i = 0; i < n; i++) cout << soln[i] << ' ';
}