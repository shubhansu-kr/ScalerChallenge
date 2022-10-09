// https://www.codechef.com/submit/XOR_PAL

#include <bits/stdc++.h>
using namespace std ;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N;
    cin >> T;
    string s;
    while(T--) {
        cin >> N;
        cin >> s;
        int count = 0;
        for (int i = 0; i < N/2; ++i)
        {
            if (s[i] != s[N-i-1]) ++count;
        }
        count = count / 2 + count % 2;
        cout << count << "\n";
    }

    return 0;
}