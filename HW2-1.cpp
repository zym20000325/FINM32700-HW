#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'countPalindromes' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
 
int countPalindromes(string s) {
    
    int length = s.length();
    int result = 0;
    
    int left, right;
    
    for (int i = 0; i < length; ++i) {
        
        // odd length
        left = i;
        right = i;
        
        while (left >= 0 && right < length && s[left] == s[right]) {
            result++;
            left--;
            right++;
        }
        
        //even length
        left = i;
        right = i+1;
        
        while (left >= 0 && right < length && s[left] == s[right]) {
            result++;
            left--;
            right++;
        }
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = countPalindromes(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
