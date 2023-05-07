#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


// Maximizing Profit from Stocks: Your algorithms have become so good at predicting the market 
// that you now know what the share price of SPT will
// be for a number of minutes going forward. Each minute, your high-frequency 
// trading platform allows you to either buy one share of SPT, sell any number of 
// shares of SPT that you own, or not make any transaction at all. 

// Find the maximum profit you can obtain with an optimal trading strategy. 
// Purchases are negative and sales are positive cash flows in the following equations.

// Example: If predicted prices over the next n = 6 minutes are prices = [3, 4, 5, 3, 5, 2], 
// one way to the best outcome is to purchase a share in each of the first 2 minutes for cash flows -3 + -4 = -7, 
// then sell them at the third minute for 2 * 5 = 10. 
// Purchase a share in the 4th minute for 3 and sell it in the 5th minute for 5. 
// Total profits are -3 – 4 + 10 – 3 + 5 = 5. 
// Another way to the same outcome is to purchase a share in each of the 1st, 2nd and 4th minutes for -3 – 4 – 3 = -10, 
// do nothing at minute 2 then sell all three shares at 5 (total 3 * 5 = 15) on the 5th day, again 
// for a total profit of -10 + 15 = 5. There is no reason to purchase in the last minute as there is no time to sell.


/*
 * Complete the 'maximumProfit' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY price as parameter.
 */

long maximumProfit(vector<int> price) {

    long profit = 0;
    
    auto p = price.cbegin();
    while(p != price.cend()){
        
        auto max_i = max_element(p, price.cend());
        auto i = p;
        
        while (i != max_i){
            profit = profit + *max_i - *i;
            ++i;
        }
        p = max_i+1;
    }

    return profit;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string price_temp_temp;
        getline(cin, price_temp_temp);

        vector<string> price_temp = split(rtrim(price_temp_temp));

        vector<int> price(n);

        for (int i = 0; i < n; i++) {
            int price_item = stoi(price_temp[i]);

            price[i] = price_item;
        }

        long profit = maximumProfit(price);

        fout << profit << "\n";
    }

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
