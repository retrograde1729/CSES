#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7, m = 1e6 + 1;
vector<int> dp(m, inf);

void solve()
{
    dp[0] = 0;
    for(int i = 1; i < m; i++)
    {
        int x = i;
        while(x)
        {
            dp[i] = min(dp[i], dp[i - (x % 10)]);
            x /= 10;
        }
        ++dp[i];
    }
}

int main()
{
    solve();
    int n;
    cin >> n;
    cout << dp[n] << '\n';
}