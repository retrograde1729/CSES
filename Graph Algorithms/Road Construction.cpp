#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int mxn = 1e5;
int max_size = 0;
int c = 0;
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
        max_size = max(max_size, sizes[rx]);
        c++;
    }
}
int main()
{
    init();
    ll n, m;
    cin >> n >> m;
    for(int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v, --u, --v;
        bind(u, v);
        cout << n - c << ' ' << max_size << '\n';
    } 
}