#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int mxn = 2 * 1e5 + 1;
vector<bool> present(mxn, 0);
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    if(arr[0] != 1) cout << 1;
    else
    {
        ll sum = 1;
        for(int i = 1; i < n; i++)
        {
            if(arr[i] <= sum + 1) sum += arr[i];
            else break;
        }
        cout << sum + 1;
    }
}