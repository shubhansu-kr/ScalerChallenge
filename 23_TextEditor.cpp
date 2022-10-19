// https://www.hackerrank.com/challenges/simple-text-editor/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std ;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q, ch; 
    string s = "";
    cin >> Q;
    stack<string> state;
    while(Q--) {
        cin >> ch;
        if (ch == 1){
            string w; 
            cin >> w;
            state.push(s);
            s += w;
        }
        else if (ch == 2) {
            int k, n;
            cin >> k;
            n = s.size()-k;
            state.push(s);
            s = s.substr(0, n);
        }
        else if (ch == 3){
            int k ; 
            cin >> k;
            cout << s[k-1] << endl;
        }
        else {
            s = state.top();
            state.pop();
        }
    }

    return 0;
}