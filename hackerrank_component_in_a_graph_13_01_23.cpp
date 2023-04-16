#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<int> vis;
void dfs(int curr, int par, vector<pair<int, string>> &res)
{
    vis[curr] = 1;
    for (auto child : v[curr])
    {
        if (vis[child] && child != par)
        {
            res.push_back({vis[child], " CYCLE FORMED!"});
            continue;
        }
        dfs(child, curr, res);
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n ,x ;
    cin >> n>>x;
    v.resize(n + 2);
    vis.resize(n + 2,0);
    vector<pair<int, string>> res;
    int v1, v2;
    int component = 1;
    while (x--)
    {
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        dfs(i, 0, res);
        component++;
    }
    cout << component << endl;
    for (auto it : res)
    {
        cout << it.first << it.second << endl;
    }
    return 0;
}
