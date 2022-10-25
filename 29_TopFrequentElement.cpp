// https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:

    bool myComp (pair<int, int> p1, pair<int, int> p2){
        return p1.second < p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto &it: nums) mp[it]++; 

        vector<pair<int, int>> pt;
        for(auto &it: mp){
            pt.emplace_back(pair<int, int>({it.first, it.second}));
        }
        
        sort(pt.begin(), pt.end(), myComp);
        vector<int> ans;
        for(auto &it: pt){
            if (ans.size() == k) return ans;
            ans.emplace_back(it.first);
        }
        return ans; 
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Cannot use sort on maps; 
    return 0;
}