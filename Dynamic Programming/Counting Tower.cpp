#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7, m = 1e6 + 1;
vector<vector<ll>> dp(m, vector<ll> (2, 0));

void foo()
{
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i < m; i++)
    {
        dp[i][0] = (2LL * dp[i - 1][0] + dp[i - 1][1]) % mod; //state pulled for no vertical separation
        dp[i][1] = (4LL * dp[i - 1][1] + dp[i - 1][0]) % mod; //state pulled for vertical separation
    }
    // Incoming slab can be of 2 type
}

int main()
{
    foo();
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % mod << '\n';
    }

}