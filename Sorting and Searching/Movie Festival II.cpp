#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int mxn = 1e5;

int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    vector<vector<int>> time(n, vector<int> (2));
    for(int i = 0; i < n; i++) cin >> time[i][1] >> time[i][0];
    sort(time.begin(), time.end());
    multiset<int> mst;
    for(int i = 0; i < k; i++) mst.insert(0);
    for(int i = 0; i < n; i++) 
    {
        if(time[i][1] < *mst.begin()) continue;
        ans++;
        mst.insert(time[i][0]);
        mst.erase(--mst.upper_bound(time[i][1]));
    }
    cout << ans;
}