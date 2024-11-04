#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int mxn = 1e5;

bool customComparator(const vector<int>& a, const vector<int>& b) 
{
    if (a[0] == b[0]) return a[1] > b[1]; 
    return a[0] < b[0];     
}

int main()
{ 
    int n;
    cin >> n;
    vector<vector<int>> range;
    multiset<int> mst1, mst2;
    for(int i = 0, x, y; i < n; i++) {cin >> x >> y; range.push_back({x, y, i}); mst1.insert(y), mst2.insert(y);}
    sort(range.begin(), range.end(), customComparator);
    vector<bool> contain(n, 0), contained(n, 0);
    for(int i = n - 1; i >= 0; i--)
    {
        mst2.erase(mst2.find(range[i][1]));
        if(mst2.lower_bound(range[i][1]) != mst2.end()) contained[range[i][2]] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        mst1.erase(mst1.find(range[i][1]));
        if(mst1.upper_bound(range[i][1]) != mst1.begin()) contain[range[i][2]] = 1;
    }
    for(bool b : contain) cout << b << ' ';
    cout << '\n';
    for(bool b : contained) cout << b << ' ';
}