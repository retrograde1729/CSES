#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    ll ans = 0, i = 0, j = 0;
    map<int,int> mp;
    while(j < n)
    {
        mp[arr[j++]]++;
        while(mp.size() > k) if(!(--mp[arr[i++]])) mp.erase(arr[i - 1]);
        ans += j - i;
    }
    
    cout << ans;
}