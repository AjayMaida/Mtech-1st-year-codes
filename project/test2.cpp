#include <bits/stdc++.h>
int main(int argc, char *argv[])
{
    std::string path = argv[1];

    std::ifstream file(path);
    std::string line, key;
    std::vector<std::pair<std::string, std::string>> file_vec;
    std::vector<int> freq_count(500);
    std::vector<int> freq;
    for (int i = 0; i < 500; i++)
    {
        freq_count[i] = 0;
    }
    int count = 0;
    while (std::getline(file, line))
    {
        if (!line.empty())
        {
            int offset = line.find_first_of(",");
            key = line.substr(1, offset - 1);
            freq_count[stoi(key)] += 1;
            file_vec.push_back({key, line});
        }
    }
    int dup = 0;
    int maX = 0;
    for (int i = 0; i < freq_count.size(); i++)
    {
        maX = std::max(maX, freq_count[i]);
        if (freq_count[i] != 0)
            freq.push_back(i);
        if (freq_count[i] > 1)
        {
            dup++;
        }
    }

    std::cout << "num of duplicates : " << dup << "\n";
    std::cout << "max value : " << maX;
    random_shuffle(file_vec.begin(), file_vec.end());
    file.close();
    std::ofstream ofs;
    ofs.open(path, std::ofstream::out | std::ofstream::trunc);
    std::cout << file_vec.size();
    for (auto i : file_vec)
    {
        // std::cout << i.second << "\n";
        // int idx=rand()%freq.size();
        // std::string num= +"("+std::to_string(freq[idx])+",";
        // ofs<<num;
        // ofs << i.second.substr(1,i.second.size()) << "\n";
         ofs << i.second<< "\n";
    }
    ofs.close();
}