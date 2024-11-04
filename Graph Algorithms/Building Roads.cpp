#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int mxn = 1e5;
vector<int> parent(mxn), sizes(mxn);

void init()
{
    for(int i = 0; i < mxn; i++)
    {
        parent[i] = i;
        sizes[i] = 1;
    }
}

int find(int x)
{
    return (parent[x] == x) ? x : parent[x] = find(parent[x]);
}

void bind(int x, int y)
{
    int rx = find(x), ry = find(y);
    if(rx != ry)
    {
        if(sizes[rx] < sizes[ry]) swap(rx, ry);
        parent[ry] = rx;
        sizes[rx] += sizes[ry];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        bind(u, v);
    }

    vector<int> connect;
    set<int> s;
    for(int i = 0; i < n; i++) if(s.find(find(i)) == s.end()) {connect.push_back(find(i)); s.insert(find(i));}

    cout << connect.size() - 1 << '\n';
    for(int i = 0; i < connect.size() - 1; i++) cout << connect[i] + 1 << ' ' << connect[i + 1] + 1 << '\n';
}