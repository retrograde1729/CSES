#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int start = 0, end = n - 1, ans = 0;

    while(start <= end)
    {
        ans++;
        if(arr[start++] + arr[end--] > x) start--;
    }   
    cout << ans; 
}