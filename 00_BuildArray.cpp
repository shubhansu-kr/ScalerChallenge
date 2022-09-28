// https://leetcode.com/problems/build-array-from-permutation/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans; 
        for(int i = 0; i < nums.size(); ++i) {
            ans.emplace_back(nums[nums[i]]);
        }
        return ans;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}