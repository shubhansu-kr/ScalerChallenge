// https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1?page=1&difficulty[]=0&category[]=Divide%20and%20Conquer&sortBy=accuracy

#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int modi = (int)1e9+7;    
    long long power(int N,int R)
    {
        return recr(N, R);  
    }
    long long recr(long long a, long long b){
        if(b == 0){return 1;}
        if(b == 1){return a%modi;}
        if(b < 0){b = -1 * b;a = 1/a;}
        long long ans = 0;
        if(b%2 == 0){ans = (recr((a%modi * a%modi)%modi, (b / 2)))%modi;}
        else{ans = (a%modi * recr((a%modi * a%modi)%modi,(b/2)%modi))%modi;}
        return ans;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}