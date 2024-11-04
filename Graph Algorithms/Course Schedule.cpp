#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int mxn = 100000;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> edge[n];
    vector<int> in(n, 0);
    vector<int> soln;
    for(int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v , --u, --v;
        edge[u].push_back(v);
        in[v]++;
    }

    queue<int> qu;
    for(int i = 0; i < n; i++) if(!in[i]) qu.push(i);

    while(qu.size())
    {
        int i = qu.front();
        qu.pop();
        soln.push_back(i);
        for(int j : edge[i]) if(!(--in[j])) qu.push(j);
    }

    for(int i : in) if(i) {cout << "IMPOSSIBLE"; return 0;}
    for(int i : soln) cout << i + 1 << ' ';
}