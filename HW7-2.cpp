#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'countChoices' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER libSize
 *  2. INTEGER betweenRepeats
 *  3. INTEGER numSongs
 */


// reference: https://leetcode.com/problems/number-of-music-playlists/editorial/

int countChoices(int libSize, int betweenRepeats, int numSongs){
    
    int MOD = 1e9 + 7;
    vector<vector<long long>> dp(numSongs + 1, vector<long long>(libSize + 1, 0));
    
    dp[0][0] = 1;
    for (int i = 1; i <= numSongs; ++i) {
        for (int j = 1; j <= libSize; ++j) {
            dp[i][j] += dp[i - 1][j - 1] * (libSize - j + 1);
            dp[i][j] += dp[i - 1][j] * std::max(j - betweenRepeats, 0);
            dp[i][j] %= MOD;
        }
    }

    return static_cast<int>(dp[numSongs][libSize]);
}
 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string libSize_temp;
    getline(cin, libSize_temp);

    int libSize = stoi(ltrim(rtrim(libSize_temp)));

    string betweenRepeats_temp;
    getline(cin, betweenRepeats_temp);

    int betweenRepeats = stoi(ltrim(rtrim(betweenRepeats_temp)));

    string numSongs_temp;
    getline(cin, numSongs_temp);

    int numSongs = stoi(ltrim(rtrim(numSongs_temp)));

    int result = countChoices(libSize, betweenRepeats, numSongs);

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
