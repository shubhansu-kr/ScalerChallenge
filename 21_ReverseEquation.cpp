// https://practice.geeksforgeeks.org/problems/reversing-the-equation2205

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string reverseEqn (string s)
    {
        stack<string> exp;
        string temp = "";
        for(auto &it: s){
            if (it == '+' || it == '-' || it == '*' || it == '/') {
                exp.push(temp);
                temp = "";
                temp.push_back(it);
                exp.push(temp);
                temp = "";
            }
            else {temp.push_back(it);}
        }
        while(exp.size()){
            temp += exp.top();
            exp.pop();
        }
        return temp;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s1;
    cout << s1.reverseEqn("20-3+5*2");
    return 0;
}