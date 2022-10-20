#include <bits/stdc++.h>

bool checkcycle(int node, std::vector<std::set<int>> &edge, std::vector<int> &vis, std::vector<int> &dfsvis)
{
    vis[node] = 1;
    dfsvis[node] = 1;
    for (auto i : edge[node])
    {
        if (!vis[i])
        {
            if (checkcycle(i, edge, vis, dfsvis))
            {
                return true;
            }
        }
        else if (dfsvis[i])
        {
            std::cout << "\n-----------Cycle is present between node " << i << " & " << node << "\n";
            return true;
        }
    }
    dfsvis[node] = 0;
    return false;
}
//funtion to check cycle in graph
bool iscycle(int n, std::vector<std::set<int>> &edge)
{
    std::vector<int> vis(n + 1, 0);
    std::vector<int> dfsvis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (checkcycle(i, edge, vis, dfsvis))
                return true;
        }
    }
    return false;
}
//function to print topological order of transaction
void topol(std::vector<int> &indeg, std::vector<std::set<int>> &edge, int n)
{
    std::queue<int> pq;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            pq.push(i);
        }
    }
    int cnt = 0;
    std::cout << "\nSerializable order:   ";
    while (!pq.empty())
    {
        cnt++;
        int x = pq.front();
        pq.pop();
        std::cout << "T" << x << " ";
        for (auto i : edge[x])
        {
            indeg[i]--;
            if (indeg[i] == 0)
                pq.push(i);
        }
    }
}
void removSpace(std::string &str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

int main()
{
    std::cout << "\n\n----------------------------------------------------------------------\n\n\n";
    std::fstream file("inputfile.txt");
    std::string mystring;
    int count = 0;
    int num_trans = 0;
    if (file.is_open())
    {
        while (file.good() && count < 3)
        {
            std::getline(file, mystring);
            removSpace(mystring);
            // std::cout << mystring << "\n";
            if (!count)
            {
                num_trans = (mystring.length() + 1 - 6) / 3;
            }

            count++;
        }

        std::vector<std::pair<int, std::string>> trans;

        while (file)
        {
            std::getline(file, mystring);

            removSpace(mystring);
            trans.push_back(std::make_pair((mystring[1] - 48), mystring.substr(3, 6)));
        }
        std::cout << "-----------------schedule-------------------\n";
        for (auto i : trans)
        {
            std::cout << "T" << i.first << " " << i.second << "\n";
        }
        if (num_trans == 1)
        {
            std::cout << "Conflict serislizable \n";
            std::cout << "its serializability order is :"
                      << "\n";
            return 0;
        }

        std::vector<std::set<int>> edge(num_trans + 1);
        std::pair<int, int> x;
        for (int i = 0; i < trans.size(); i++)
        {
            for (int j = i + 1; j < trans.size(); j++)
            {
                if (trans[i].second[0] == 'R')
                {
                    if (trans[i].first != trans[j].first && trans[j].second[0] == 'W' and trans[i].second[2] == trans[j].second[2])
                        edge[trans[i].first].insert(trans[j].first);
                }
                if (trans[i].second[0] == 'W')
                {
                    if (trans[i].first != trans[j].first && trans[j].second[2] == trans[i].second[2])
                        edge[trans[i].first].insert(trans[j].first);
                }
            }
        }
        std::vector<int> indeg(num_trans + 1, 0);
        indeg[0] = -1;
        std::cout << "\n-------------conflicts--------------\n";
        std::cout << "from -->  to\n";
        for (int i = 1; i <= num_trans; i++)
        {
            std::cout << "  " << i << "  -->  ";
            for (auto it : edge[i])
            {

                indeg[it]++;
                std::cout << it << " ";
            }
            std::cout << "\n";
        }

        bool flag = iscycle(num_trans, edge);
        flag ? std::cout << "\n       Not Conflict Serializable\n" : std::cout << "\n      Conflict Serilizable\n";

        if (flag == 1)
        {
            std::cout << "\n\n\n\n";
            return 0;
        }
        topol(indeg, edge, num_trans);
        std::cout << "\n\n\n\n";
    }
    else
    {
        std::cout << "can't open file!!";
    }
}
