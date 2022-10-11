// https://practice.geeksforgeeks.org/problems/print-anagrams-together

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (auto &it : string_list)
        {
            string x = it;
            sort(x.begin(), x.end());
            mp[x].emplace_back(it);
        }
        for (auto &it : mp)
        {
            res.emplace_back(it.second);
        }
        sort(res.begin(), res.end(), [](vector<string> &v1, vector<string> &v2)
             { return v1[0] < v2[0]; });
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}