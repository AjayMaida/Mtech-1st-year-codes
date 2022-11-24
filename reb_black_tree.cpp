#include <bits/stdc++.h>
class node
{
    node *left;
    node *right;
    node *parent;
    int val;

public:
    node(int v)
    {
        val = v;
        parent = NULL;
        right = NULL;
        left = NULL;
    }
};
int main()
{
}