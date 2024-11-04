#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int mxn = 1e5;

int main()
{
    int n;
    cin >> n;
    unordered_set<int> st;
    while(n--)
    {
        int i;
        cin >> i;
        if(st.find(i - 1) != st.end()) st.erase(i - 1); 
        st.insert(i);
    }

    cout << st.size();
}