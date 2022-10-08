// https://practice.geeksforgeeks.org/problems/killing-spree3020/1?page=1&difficulty[]=1&category[]=Divide%20and%20Conquer&sortBy=accuracy

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    long long int killinSpree(long long int n)
    {
        // Code Here
        // My power is n so all i need to find is no. of term upto which sum 
        // is greater than n and return the no. of terms -1

        long long int i = 1;
        while(n > 0) {
            long long int x = i * i;
            if (x > n) return i - 1;
            n -= x;
            ++i;
        }
        return i;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}