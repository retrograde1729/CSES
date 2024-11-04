#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
 
int look(vector<vector<ll>>& arr, ll target) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1; 
 
    while (left <= right) {
        int mid = left + (right - left) / 2;
 
        if (arr[mid][0] < target) {
            result = mid; 
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
 
    return result;
}
 
int main()
{
    int n;
    cin >> n;
    vector<vector<ll>> time(n, vector<ll> (3));
    for(int i = 0; i < n; i++) cin >> time[i][1] >> time[i][0] >> time[i][2];
    sort(time.begin(), time.end());
 
    vector<ll> dp(n, 0);
    dp[0] = time[0][2];
 
    for(int i = 1; i < n; i++)
    {
        int index = look(time, time[i][1]);
        if(index == -1) dp[i] = max(dp[i - 1], time[i][2]);
        else dp[i] = max(dp[index] + time[i][2], dp[i - 1]);
    }
 
    cout << dp[n - 1];
}