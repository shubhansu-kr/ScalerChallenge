// https://leetcode.com/problems/search-insert-position/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int f = 0, r = nums.size()-1;
        int m ;
        while(f <= r) {
            m = f + (r-f)/2;
            if (nums[m] == target) return m;
            if (nums[m] < target) {
                f = m + 1;
            }
            else {
                r = m-1;
            }
        }
        return f;
    }
};

int main () {

    vector<int> v = {1, 2, 4, 5, 6};
    int t = 2;
    Solution Obj1;
    cout << Obj1.searchInsert(v, t);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}