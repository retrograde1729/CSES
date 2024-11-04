#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int mxn = 2e5 + 1;
vector<vector<int>> lift(mxn, vector<int> (31, -1));


int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++) cin >> lift[i][0], --lift[i][0];

    for(int i = 1; i < 31; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(lift[j][i - 1] != -1) lift[j][i] = lift[lift[j][i - 1]][i - 1];
        }
    }
    
    while(q--)
    {
        int x, k;
        cin >> x >> k, --x;
        int p = 0;
        while(k)
        {
            if(k & 1) x = lift[x][p];
            if(x == -1) break;
            k = k >> 1;
            p++;
        }
        (x == -1) ? cout << -1 << '\n' : cout << x + 1 << '\n';
    }
}