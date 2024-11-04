#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    set<int> st;
    while(n--) 
    {
        int x;
        cin >> x;
        st.insert(x);
    }

    cout << st.size();
}