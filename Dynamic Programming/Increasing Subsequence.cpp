#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;  
const int inf = 1e8;

int find(vector<int>& lis, int val)
{
    int l = 0, h = lis.size() - 1, m = 0;
    while(l < h)
    {
        m = l + (h - l) / 2;
        if(lis[m] > val) h = m;
        else if(lis[m] < val) l = m;
        else return m;
        if(h - 1 == m)
        {
            return h;
        }
    }

    return m;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> lis;
    lis.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if(arr[i] > lis[lis.size() - 1]) {lis.push_back(arr[i]); continue;}
        int index = find(lis, arr[i]);
        lis[index] = arr[i];
    }

    cout << lis.size() << '\n';
    
}