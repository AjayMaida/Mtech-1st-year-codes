#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vll v(n + 2);
        for (int i = 1; i <= n; i++)
            cin >> v[i];

        vector<vector<int>> pre(n + 2, vector<int>(33,0));
        cout << "after this\n";
        for (int i = 1; i <= n; i++)
        {
            int c = 0;
            while (v[i])
            {
                v[i] /= 2;
                ++c;
            }
            for (int j = 1; j < 33; j++)
            {
                if (j == c)
                {
                    pre[i][j] = pre[i - 1][j] + 1;
                }
                else
                {
                    pre[i][j] = pre[i - 1][j];
                }
            }
        }
        cout << "after this\n";
        for (auto it : pre)
        {
            for (auto i : it)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        int q;
        cin >> q;
        while (q--)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            int c = 0;
            while (x)
            {
                x /= 2;
                c++;
            }
            int ans = r - l + 1 - (pre[r][c] - pre[l - 1][c]);
            cout << ans << "\n";
        }
    }
    return 0;
}
