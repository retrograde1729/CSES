#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(auto& i : c) cin >> i;
    sort(c.begin(), c.end());
    vector<int> dp(x + 1, inf);
    dp[0] = 0;
    for(int i = 1; i < x + 1; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(c[j] > i) break;
            else dp[i] = min(dp[i - c[j]] + 1, dp[i]);
        }
    }

    if(dp[x] == inf) cout << -1 << '\n';
    else cout << dp[x] << '\n';
}