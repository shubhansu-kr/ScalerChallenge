// https://leetcode.com/problems/n-queens/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    vector<int> row, d1, d2;
public:
    void set(int n){
        vector<int> row(n, 1), d1(2*n-1, 1), d2(2*n-1, 1);
        this->row = row;
        this->d1 = d1;
        this->d2 = d2;
    }

    vector<vector<string>> solveNQueens(int n) {
        set(n);
        vector<vector<string>> soln;
        vector<string> sub(n, string(n, '.'));
        solve(soln, sub, n);
        return soln;
    }

    void solve(vector<vector<string>> &soln, vector<string> &sub, int &n, int c = 0) {
        if (c == n) {
            soln.emplace_back(sub);
            return;
        };

        for (int r = 0; r < n; ++r)
        {
            if(row[r] && d1[r+c] && d2[(r-c)+n-1]) {
                // valid pos 
                sub[c][r] = 'Q';
                row[r] = 0, d1[r+c] = 0, d2[n+r-c-1] = 0;
                solve(soln, sub, n, c+1);
                sub[c][r] = '.';
                row[r] = 1, d1[r+c] = 1, d2[n+r-c-1] = 1;
            }
        }
        
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}