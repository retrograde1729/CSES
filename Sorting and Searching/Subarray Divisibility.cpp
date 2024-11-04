#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    ll n, ans = 0;
    cin >> n;
    vector<int> arr(n), prefix(n, 0);
    map<int,int> mp;
    for(int i = 0; i < n; i++) cin >> arr[i], arr[i] %= n;
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) prefix[i] = (prefix[i - 1] + arr[i] + n) % n;
    mp[0] = 1;
    for(int i = 0; i < n; i++) ans += mp[prefix[i]], mp[prefix[i]]++;
    cout << ans;
}