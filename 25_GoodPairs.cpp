// https://leetcode.com/problems/number-of-good-pairs/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int count = 0;
        for (auto &it : nums){mp[it]++;}
        for (auto &it : mp)
        {
            if (it.second > 1)
            {
                int a = it.second;
                count += (a * (a-1))/2;
            }
        }
        return count;
    }
    // Dont even need the factorial
    int factorial(int n)
    {
        if (n == 0) return 1;
        int k = 1;
        while (n--){k *= n;}
        return k;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}