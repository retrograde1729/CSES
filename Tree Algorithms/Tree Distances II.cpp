#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int mxn = 2e5 + 1;
vector<int> adj[mxn];
vector<ll> dist(mxn, 0);
vector<ll> node(mxn, 0);

void dfs1(int i, int p)
{   
    for(int j : adj[i])
    {
        if(j == p) continue;
        dfs1(j, i);
        dist[i] += dist[j];
        node[i] += node[j] + 1;
    }
    dist[i] += node[i];
}

void dfs2(int i, int p, int n)
{
    dist[i] = dist[p] + n - 2ll * (node[i] + 1);
    for(int j : adj[i])
    {
        if(j == p) continue;
        dfs2(j, i, n);
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
    for(int i : adj[0]) dfs2(i, 0, n);
    for(int i = 0; i < n; i++) cout << dist[i] << ' ';
}