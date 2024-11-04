#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int mxn = 1e5;

int main()
{
    int n;
    cin >> n;
    map<int,int> mp;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int i = 0, j = 0, ans = 0;
    while(j < n)
    {
        mp[v[j++]]++;
        while(i <= j && mp[v[j - 1]] > 1) mp[v[i++]]--;
        ans = max(ans, j - i);
    }

    cout << ans;
}