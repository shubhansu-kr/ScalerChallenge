// https://practice.geeksforgeeks.org/problems/largest-square-in-a-binary-matrix-with-at-most-k-1s-for-multiple-queries

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestSquare(vector<vector<int>> M, int R, int C, int K, int Q, int q_i[], int q_j[])
    {
        vector<vector<int>> dp(R + 1, vector<int>(C + 1));

        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
                dp[i][j] = M[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        vector<int> ans(Q);
        for (int q = 0; q < Q; q++)
        {
            int x = q_i[q] + 1, y = q_j[q] + 1, val = M[x - 1][y - 1], side = 1;

            while (x - side >= 0 and y - side >= 0 and x <= R and y <= C)
            {
                val = dp[x][y] + dp[x - side][y - side] - dp[x - side][y] - dp[x][y - side];
                if (val <= K) ans[q] = side;
                else break; 
                x += 1;
                y += 1;
                side += 2;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> largestSquare(vector<vector<int>> M, int R, int C, int K, int Q, int q_i[], int q_j[])
    {
        // code here
        K = ceil(sqrt(K));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}