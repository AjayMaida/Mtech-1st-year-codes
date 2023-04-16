
#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, t, A[10000];
int main()
{
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        int c = 0,i=0;
        vector<int> v1;
        while(i<n)
        {
            // cout << v1.size();
            while (i<n && v1.size() == v[i])
            {
                v1.push_back(v[i++]);
            }
            if(i && i<n && v1.size()==v[i-1])c++;
            if (i < n)
                v1.push_back(v[i++]);
        }
        cout <<c << endl;
    }
}
