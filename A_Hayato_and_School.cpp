#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int count = 0;
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
        if (v[i] & 1)
            v1.push_back(i + 1);
        else
            v2.push_back(i + 1);
    if (v1.size() >= 3)
    {
        printf("YES\n%d %d %d\n", v[0], v[1], v[2]);
        return;
    }

    if (v1.size() >= 1 && v2.size() >= 2)
    {
        printf("YES\n%d %d %d\n", v1[0], v2[0], v2[1]);
        return;
    }
    cout << "NO\n";
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}