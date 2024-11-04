#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int mxn = 100000;
vector<int> vis(mxn, -1);
vector<vector<int>> edge(mxn);
vector<int> soln;
int jump = 0;
bool flag = false;
set<int> cyclic;
set<int> acyclic;

void dfs(int i, int prev)
{
    vis[i] = prev;
    cyclic.insert(i);
    for(int node : edge[i])
    {
        if(flag) return;
        if(acyclic.find(node) != acyclic.end()) continue;
        if(cyclic.find(node) != cyclic.end()) 
        {
            soln.push_back(node + 1);
            while(i != node) 
            {
                soln.push_back(i + 1);
                i = vis[i];
            }
            soln.push_back(node + 1);
            reverse(soln.begin(), soln.end());
            cout << soln.size() << '\n';
            for(int j : soln) cout << j << ' ';
            flag = true;
            return;
        }
        dfs(node, i);
        if(!flag) cyclic.erase(node);
    }
    acyclic.insert(i);
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
    }

    for(int i = 0; i < n; i++)
    {
        flag = false;
        if(vis[i] == -1) dfs(i, i);
        cyclic.clear();
        if(soln.size()) return 0;
    }
    
    cout << "IMPOSSIBLE";
}