#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int mxn = 2e5 + 1;
vector<int> soln(mxn, -1);
vector<int> adj[mxn];

void dfs(int i, int par)
{
    int x = 0;
    for(int j : adj[i])
    {
        if(j != par)
        {
            x++;
            if(soln[j] == -1) dfs(j, i);
            x += soln[j];
        }
    }
    soln[i] = x;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1, j; i <= n - 1; i++)
    {
        cin >> j, --j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    dfs(0, -1);
    for(int i = 0; i < n; i++) cout << soln[i] << ' ';
}