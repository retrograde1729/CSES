#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int mxn = 1e5;
vector<int> to[mxn], fro[mxn];
int vis[mxn] = {0};

void dfs_to(int i)
{
    if(vis[i]) return;
    vis[i] = 1;
    for(int j : to[i]) dfs_to(j);
}

void dfs_fro(int i)
{
    if(vis[i]) return;
    vis[i] = 1;
    for(int j : fro[i]) dfs_fro(j);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0, u, v; i < m; i++) 
    {
        cin >> u >> v, --u, --v;
        to[u].push_back(v);
        fro[v].push_back(u);
    }
    dfs_to(0);
    for(int i = 0; i < n; i++) if(!vis[i]) {cout << "NO \n" << 1 << ' ' << i + 1; return 0;}
    for(int i = 0; i < n; i++) vis[i] = 0;
    dfs_fro(0);
    for(int i = 0; i < n; i++) if(!vis[i]) {cout << "NO \n" << i + 1 << ' ' << 1; return 0;}
    cout << "YES";
}