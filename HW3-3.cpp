#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'isPossible' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER a
 *  2. INTEGER b
 *  3. INTEGER c
 *  4. INTEGER d
 */

string isPossible(int a, int b, int c, int d) {
    
    // (c0, d0) -> (c1, d1)
    // (1) c1 = c0 + d0, d1 = d0, c1 > d1
    // (2) c1 = c0, d1 = c0 + d0, c1 < d1
    // (3) c1 = d1, c1 = a, d1 = b
    
    // (3)
    if (c==d && a==c && b==d){
        return "Yes";
    }
    
    if (c!=d){
        
        while(c!=d && a<c && b<d){
            
            // (1)
            if(c>d){
                c = c%d;
            }
            // (2)
            else{
                d = d%c;
            }
        }
        
        if(a==c && b==d){
            return "Yes";
        }
        else if(a==c && b<d){
            if ((d-b)%c==0){
                return "Yes";
            }
            else{
                return "No";
            }
        }
        else if(a<c && b==d){
            if ((c-a)%d==0){
                return "Yes";
            }
            else{
                return "No";
            }
        }
        else{
            return "No";
        }
    }
    
    return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_temp;
    getline(cin, a_temp);

    int a = stoi(ltrim(rtrim(a_temp)));

    string b_temp;
    getline(cin, b_temp);

    int b = stoi(ltrim(rtrim(b_temp)));

    string c_temp;
    getline(cin, c_temp);

    int c = stoi(ltrim(rtrim(c_temp)));

    string d_temp;
    getline(cin, d_temp);

    int d = stoi(ltrim(rtrim(d_temp)));

    string result = isPossible(a, b, c, d);

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
