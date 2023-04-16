#include<bits/stdc++.h>
using namespace std;

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    vector<string> result;
    unordered_set<string> wordSet(words.begin(), words.end());
    for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
            if (words[j].find(words[i]) != string::npos) {
                if (check_concatenated(words[j], words[i], wordSet)) {
                    result.push_back(words[j]);
                }
            } else if (words[i].find(words[j]) != string::npos) {
                if (check_concatenated(words[i], words[j], wordSet)) {
                    result.push_back(words[i]);
                }
            }
        }
    }
    return result;
}

bool check_concatenated(string s, string word, unordered_set<string> &wordSet) {
    if (s.length() <= word.length()) {
        return false;
    }
    if (wordSet.find(s) != wordSet.end()) {
        return true;
    }
    for (int i = 1; i < s.length(); i++) {
        string left = s.substr(0, i);
        string right = s.substr(i);
        if (wordSet.find(left) != wordSet.end() && check_concatenated(right, word, wordSet)) {
            return true;
        }
    }
    return false;
}

int main() {
    // Example usage:
    vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    vector<string> concatenated_words = findAllConcatenatedWordsInADict(words);
    for (string word : concatenated_words) {
        cout << word << endl;
    }
    return 0;
}
