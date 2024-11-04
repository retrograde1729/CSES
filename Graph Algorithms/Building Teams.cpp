#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int mxn = 100000;

vector<int> color(mxn, -1);
vector<vector<int>> edge(mxn);

bool dfs(int i, int c)
{
    if(color[i] != -1) return (color[i] == c) ? true : false;
    bool flag = true;
    color[i] = c;
    for(int node : edge[i])
    {
        if(c == 1) flag &= dfs(node, 2);
        else flag &= dfs(node, 1);
    }

    return flag;
}

int main()
{
    int n, m;
    cin >> n >> m;
    bool flag = true;
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
        if(color[i] == -1)
        {
            flag &= dfs(i, 1);
        }
    }

    if(flag) for(int i = 0; i < n; i++) cout << color[i] << ' ';
    else cout << "IMPOSSIBLE" << '\n';
}