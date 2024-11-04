#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    int n, room = 0;
    cin >> n;
    vector<vector<int>> time;
    multiset<pair<int, int>> mst;
    for(int i = 0, x, y; i < n; i++) {cin >> x >> y; time.push_back({x, y, i});}
    sort(time.begin(), time.end());
    vector<int> soln(n, 0);
    for(int i = 0; i < n; i++)
    {
        auto it = mst.lower_bound({time[i][0], 0});
        if(it != mst.begin()) 
        {
            --it;
            mst.erase(it);
            mst.insert({time[i][1], it->second});
            soln[time[i][2]] = it->second;
        }
        else
        {
            mst.insert({time[i][1], ++room});
            soln[time[i][2]] = room;
        }
    }

    cout << mst.size() << '\n';
    for(int i : soln) cout << i << ' ';    
}