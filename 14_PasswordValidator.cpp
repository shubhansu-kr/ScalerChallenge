#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Its length is at least 6.
// It contains at least one digit.
// It contains at least one lowercase English character.
// It contains at least one uppercase English character.
// It contains at least one special character. The special characters are: !@#$%^&*()-+

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int isUpper = 1, isLower = 1, isDigit = 1, isSpecial = 1;
    string sp = "!@#$%^&*()-+";
    for(auto &it: password) {
        if (it <= 'z' && it >= 'a') isLower = 0;
        else if (it <= 'Z' && it >= 'A') isUpper = 0;
        else if (it <= '9' && it >= '0') isDigit = 0;
        else if (sp.find(it) != string::npos) isSpecial = 0;
    }
    int res = isLower + isUpper + isDigit + isSpecial;
    n += res;
    if (n < 6) {res += (6-n);}
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
