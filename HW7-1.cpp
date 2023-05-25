#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countPatterns' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */
 
int mod(int base, int exp, int mod_n) {
    
    long res = 1;
    long baseL = base;
    long modL = mod_n;
    
    while (exp > 0) {
        if (exp & 1) {
            res = (res * baseL) % modL;
        }
        baseL = (baseL * baseL) % modL;
        exp >>= 1;
    }
    
    return static_cast<int>(res);
}

int mul(int a, int b, int c) {

    int res = 0;
    
    while (b > 0) {
        if (b & 1) {
            res = (res + a) % c;
        }
        a = (a * 2) % c;
        b >>= 1;
    }
    
    return res;
}

int countPatterns(int n) {
        
    long mod_n = 1e9 + 7;
    
    long mod24 = mod(24, n, mod_n);
    long mod8 = mod(8, n, mod_n);
    long mod3 = mod(3, n, mod_n);
    long mod2 = mod(2, n, mod_n);
    
    long res = (mod24 + mod_n - (mul(mod8, 9, mod_n) % mod_n) + (mod3 * 18) % mod_n + (mod2 * 9) % mod_n - 24 + mod_n) % mod_n;
    
    return static_cast<int>(res);
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    int result = countPatterns(n);

    fout << result << "\n";

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
