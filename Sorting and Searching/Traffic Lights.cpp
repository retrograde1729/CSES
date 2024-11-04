#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int mxn = 1e5;

int main()
{
    int n, k;
    cin >> n >> k;
    set<int> st;
    st.insert(0);
    st.insert(n);
    vector<int> v(k), soln(k, 0);
    for(int i = 0; i < k; i++) {cin >> v[i]; st.insert(v[i]);}
    auto it1 = st.begin(), it2 = next(it1);
    while(it2 != st.end()) {soln[k - 1] = max(soln[k - 1], *(it2++) - *(it1++));}
    for(int i = k - 1; i > 0; i--)
    {
        auto it = st.find(v[i]), pre = prev(it), nex = next(it);
        st.erase(it);
        soln[i - 1] = max(soln[i], *nex - *pre);
    }
    for(int i : soln) cout << i << ' '; 
}