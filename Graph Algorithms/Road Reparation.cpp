#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int mxn = 1e5;
int par[mxn], sizes[mxn];
void init()
{
    for(int i = 0; i < mxn; i++)
    {
        par[i] = i;
        sizes[i] = 1;
    }
}
int find(int x) {return (par[x] == x) ? x : par[x] = find(par[x]);}
void bind(int x, int y)
{
    int rx = find(x), ry = find(y);
    if(rx != ry)
    {
        if(sizes[rx] < sizes[ry]) swap(rx, ry);
        sizes[rx] += sizes[ry];
        par[ry] = rx;
    }
}
int main()
{
    init();
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> path;
    for(int i = 0, u, v, w; i < m; i++) cin >> u >> v >> w, path.push_back({w, --u, --v});
    sort(path.begin(), path.end());
    ll ans = 0;
    for(int i = 0; i < m; i++) if(find(path[i][1]) != find(path[i][2])) bind(path[i][1], path[i][2]), ans += path[i][0];
    for(int i = 0; i < n - 1; i++) if(find(i) != find(i + 1)) {cout << "IMPOSSIBLE"; return 0;}
    cout << ans;
}