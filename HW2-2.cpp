#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countPowerNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */
 

int countPowerNumbers(int l, int r) {
    
    unordered_set<int> powers;
    powers.insert(0);
    powers.insert(1);
    
    for (int i = 2; i<= r ;++i){
        for (int j = 2; ; ++j){
            if (pow(i,j) <= r){
                powers.insert(pow(i,j));
            }
            else {
                break;
            }
        }
    }
    
    unordered_set<int> sum_powers;
    for (int i : powers) {
        for (int j : powers) {
            int sum = i + j;
            sum_powers.insert(sum);
        }
    }
    
    int count = 0;
    
    for (int x = l; x <= r; ++x) {
        if (sum_powers.count(x)) {
            count++;
        }
    }
    
    return count;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string r_temp;
    getline(cin, r_temp);

    int r = stoi(ltrim(rtrim(r_temp)));

    int result = countPowerNumbers(l, r);

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
