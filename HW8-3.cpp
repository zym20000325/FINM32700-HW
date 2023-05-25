#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'numDuplicates' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY name
 *  2. INTEGER_ARRAY price
 *  3. INTEGER_ARRAY weight
 */
 
int numDuplicates(vector<string> name, vector<int> price, vector<int> weight) {
    
    vector<tuple<string, int, int>> products;
    
    int counter = 0;

    for (size_t i = 0; i < name.size(); ++i) {
        tuple<string, int, int> x(name[i], price[i], weight[i]);
        products.push_back(x);
    }

    size_t l1 = products.size();
    set<tuple<string, int, int>> products_set(products.begin(), products.end());
    size_t l2 = products_set.size();

    return static_cast<int>(l1 - l2);  
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string name_count_temp;
    getline(cin, name_count_temp);

    int name_count = stoi(ltrim(rtrim(name_count_temp)));

    vector<string> name(name_count);

    for (int i = 0; i < name_count; i++) {
        string name_item;
        getline(cin, name_item);

        name[i] = name_item;
    }

    string price_count_temp;
    getline(cin, price_count_temp);

    int price_count = stoi(ltrim(rtrim(price_count_temp)));

    vector<int> price(price_count);

    for (int i = 0; i < price_count; i++) {
        string price_item_temp;
        getline(cin, price_item_temp);

        int price_item = stoi(ltrim(rtrim(price_item_temp)));

        price[i] = price_item;
    }

    string weight_count_temp;
    getline(cin, weight_count_temp);

    int weight_count = stoi(ltrim(rtrim(weight_count_temp)));

    vector<int> weight(weight_count);

    for (int i = 0; i < weight_count; i++) {
        string weight_item_temp;
        getline(cin, weight_item_temp);

        int weight_item = stoi(ltrim(rtrim(weight_item_temp)));

        weight[i] = weight_item;
    }

    int result = numDuplicates(name, price, weight);

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
