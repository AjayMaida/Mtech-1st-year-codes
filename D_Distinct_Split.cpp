#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp1, mp2;
    for (auto &it : s)
        mp2[it]++;
    int mx = mp2.size();
    for (int i = 0; s[i]; i++)
    {
        mp1[s[i]]++;
        if (mp2.find(s[i]) != mp2.end())
        {
            if (--mp2[s[i]] == 0)
                mp2.erase(s[i]);
        }
        mx = max(mx, (int)(mp1.size() + mp2.size()));
    }
    cout << mx << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}