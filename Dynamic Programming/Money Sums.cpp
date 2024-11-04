#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;  
const int inf = 1e8;

int main()
{
    int n, sum = 0;
    cin >> n;
    vector<int> coins(n, 0);
    for(int i = 0; i < n; i++) 
    {
        cin >> coins[i];
        sum += coins[i];
    }
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = sum; j >= coins[i]; j--)
        {
            if(!dp[j]) dp[j] = dp[j - coins[i]];
        }
    }

    cout << accumulate(dp.begin(), dp.end(), 0) - 1 << '\n';
    for(int i = 1; i <= sum; i++) if(dp[i]) cout << i << ' ';
}