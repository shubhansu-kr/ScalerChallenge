// https://leetcode.com/problems/check-if-n-and-its-double-exist/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_set<int> st;
        for(auto &it: arr){
            if (it == 0){
                if (st.count(it)) return true;
            }
            st.insert(it);
        }
        for(auto &it: arr){
            if (it && st.count(it*2)) return true;
        }
        return false;
    }
};

class Solution
{
    // WA: 7 1 14 11 0
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        for (auto &it : arr)
        {
            mp[it]++;
        }
        for (auto &it : mp)
        {
            cout << it.first << " " << it.second << "\n";
            int check = it.first * 2;
            cout << check << "\n";
            if (check == 0 && mp[check] == 1){
                continue;
            }
            if (mp[check]){
                return true;
            }
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {-2,0,10,-19,4,6,-8};

    Solution Obj1; 
    cout << Obj1.checkIfExist(nums);
    return 0;
}