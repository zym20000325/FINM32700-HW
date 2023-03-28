#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'pthFactor' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER n
 *  2. LONG_INTEGER p
 */

long pthFactor(long n, long p) {
        
    vector<long> factor;
    
    for (int i = 1; i<=sqrt(n); ++i) {

        if (n%i == 0) {
            
            factor.push_back(i);
   
            if (i!=sqrt(n)){
                factor.push_back(n/i);
            }
        }
    }
    
    sort(factor.begin(), factor.end());
    
    long factor_length = factor.size();
        
    if (factor_length >= p){
        return factor[p-1];
    }
    else{
        return 0;
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    string p_temp;
    getline(cin, p_temp);

    long p = stol(ltrim(rtrim(p_temp)));

    long result = pthFactor(n, p);

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
