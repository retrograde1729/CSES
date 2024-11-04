#include<bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 1;
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    int lift[n][30];
    for(int i = 0; i < n; i++) cin >> lift[i][0], --lift[i][0];
    for(int i = 1; i < 30; i++)
    {
        for(int j = 0; j < n; j++)
        {
            lift[j][i] = lift[lift[j][i - 1]][i - 1];
        }
    }
 
    while(q--)
    {
        int x, k, p = 0;
        cin >> x >> k, --x;
        while(k)
        {
            if(k & 1) x = lift[x][p];
            k = k >> 1;
            p++;
        }
 
        cout << x + 1 << '\n';
    }

}