#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<vector<ll>> dp(n, vector<ll> (m + 1, 0));
    int x[3] = {-1, 0, 1};
    if(!arr[0]) for(int i = 1; i <= m; i++) dp[0][i] = 1;
    else dp[0][arr[0]] = 1;
    
    for(int i = 1; i < n; i++)
    {
        if(arr[i]) dp[i][arr[i]] = 1;
        else 
        {
            for(int j = m; j > 0; j--)
            {
                for(int k = 0; k < 3; k++)
                {
                    if(j + x[k] > m) continue;
                    dp[i][j] = (dp[i - 1][j + x[k]] + dp[i][j]) % mod;
                }
            }
        }
    }

    ll ans = 1;
    bool flag = true;

    for(int i = 0; i < n - 1; i++)
    {
        if(!arr[i] && arr[i + 1]) 
        {
            // flag = true;
            ll temp = 0;
            for(int j = 0; j < 3; j++)
            {
                if(arr[i + 1] + x[j] > m) continue;
                temp = (temp + dp[i][arr[i + 1] + x[j]]) % mod;
                // cout << dp[i][arr[i + 1] + x[j]] << ' ' << i << ' ' << arr[i + 1] + x[j] << '\n';
            }
            
            ans = (ans * temp) % mod;
        }
    }
    
    if(!arr[n - 1])
    {
        // flag = true;
        ll temp = 0;
        for(int j = m; j > 0; j--)
        {
            temp = (temp + dp[n - 1][j]) % mod;
            // cout << j << ' ' << dp[n - 1][j] << '\n';
        }

        ans = (ans * temp) % mod;
    }
    
    for(int i = 1; i < n; i++)
    {
        if(arr[i] && arr[i - 1] && abs(arr[i] - arr[i - 1]) > 1) 
        {
            flag = false;
            break;
        }
    }

    (flag) ? cout << ans << '\n' : cout << 0 << '\n';
}