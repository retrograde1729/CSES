#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int mxn = 100000;
vector<int> vis(mxn, -1);
vector<vector<int>> edge(mxn);
vector<int> soln;
bool flag = false;
void dfs(int i, int prev)
{
    vis[i] = prev;
    
    for(int node : edge[i])
    {
        if(flag) return;
        if(node == prev) continue;
        if(vis[node] != -1) 
        {
            soln.push_back(node + 1);
            while(i != node) 
            {
                soln.push_back(i + 1);
                i = vis[i];
            }
            soln.push_back(node + 1);
            cout << soln.size() << '\n';
            for(int j : soln) cout << j << ' ';
            flag = true;
            return;
        }
        dfs(node, i);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for(int i = 0; i < n; i++)
    {
        if(vis[i] == -1) dfs(i, i);
        if(soln.size()) return 0;
    }
    
    cout << "IMPOSSIBLE";
}