
#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, t, A[10000];
int main()
{
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s.size() <= 3)
        {
            cout << 1 << endl;
            continue;
        }
        int t = 0;
        int j = 0;
        while (j < s.size())
        {
            set<char> st;
            while (j<s.size())
            {
                st.insert(s[j++]);
                if(st.size()>3){
                    j--;break;
                }
            }
            t++;
        }
        cout << t << endl;
    }
}
