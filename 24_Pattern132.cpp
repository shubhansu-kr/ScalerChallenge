// https://leetcode.com/problems/132-pattern/

#include <bits/stdc++.h>
using namespace std;

class Solution3
{
    // Stack: Optimised
public:
    bool find132pattern(vector<int> &nums)
    {
        int s3 = INT_MIN;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] < s3)
                return true;
            else
                while (!st.empty() && nums[i] > st.top())
                {
                    s3 = st.top();
                    st.pop();
                }
            st.push(nums[i]);
        }
        return false;
    }
};

class Solution2
{
    // Stack
public: 
    bool find132pattern(vector<int> &nums)
    {
        vector<int> mini(nums.size());
        mini[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            mini[i] = min(mini[i-1], nums[i]);
        }
        
        stack<int> st;
        for (int i = nums.size()-1; i >= 0; --i)
        {
            if (nums[i] > mini[i]){
                while(!st.empty() && st.top() <= mini[i]){
                    st.pop();
                }
                if (!st.empty() && st.top() < nums[i]) return true;
                st.push(nums[i]);
            }
        }
        return false;
    }
};

class Solution1
{
    // BruteForce: Optimised: Maintain Min Element: TLE
public:
    bool find132pattern(vector<int> &nums)
    {
        int mini = nums[0];
        for (int j = 1; j < nums.size(); ++j)
        {
            for (int k = j+1; k < nums.size(); ++k)
            {
                if (nums[j] > nums[k] && nums[k] > mini) return true;
            }
            mini = min(mini, nums[j]);
        }
        return false;
    }
};

class Solution
{
    // BruteForce: Complete Iteration: TLE
public:
    bool find132pattern(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i+1; j < nums.size(); ++j)
            {
                for (int k = j+1; k < nums.size(); ++k)
                {
                    if (nums[j] > nums[k] && nums[k] > nums[i]) return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}