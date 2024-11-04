#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> apar(n);
    vector<ll> need(m);

    for(int i = 0; i < n; i++) cin >> apar[i];
    for(int i = 0; i < m; i++) cin >> need[i];
    sort(apar.begin(), apar.end());
    sort(need.begin(), need.end());

    int i = 0, j = 0, ans = 0;

    while(i < n && j < m)
    {
        ll high = need[j] + k, low = need[j] - k;
        if(apar[i] <= high && apar[i] >= low) {ans++; i++; j++;}
        else if(apar[i] > high) j++;
        else i++;
    }

    cout << ans;
}