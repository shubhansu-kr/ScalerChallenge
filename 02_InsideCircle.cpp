// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i)
        {
            int count = 0; 
            for (int j = 0; j < points.size(); ++j)
            {
                int a = abs(queries[i][0] - points[j][0]);
                int b = abs(queries[i][1] - points[j][1]);

                int d = sqrt(a*a + b*b);
                if (d <= queries[i][2]) ++count;
            }
            ans[i] = count;
        }
        return ans;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}