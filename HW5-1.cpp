// Is this a tree?

// Sample input: (B,D) (D,E) (A,B) (C,F) (E,G) (A,C)
// Sample output: (A(B(D(E(G))))(C(F)))


///////////////////////////////// Method1 /////////////////////////////////

#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'sExpression' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING nodes as parameter.
 */
 
 
// reference1: https://github.com/cheatsheet1999/FrontEndCollection/blob/main/JS-Algo/Is%20this%20a%20tree.md

// reference2: https://github.com/mokshjawa/Java-Practice/blob/master/GetSExpression.java
 
bool recursion(char node, bool graph[][26], bool visited[]) {
    
    if (visited[node - 'A']){
        return true;
    }

    visited[node - 'A'] = true;

    for (int i = 0; i < 26; i++) {
        if (graph[node - 'A'][i]){
            if (recursion(i + 'A', graph, visited)){
                return true;
            }
        }
    }

    return false;
}

bool checkE1(bool graph[][26])
{
    for (int i = 0; i < 26; i++){
        int count = 0;

        for (int j = 0; j < 26; j++){
            if (graph[i][j]){
                count++;
            }
        }

        if (count > 2){
            return true;
        }
    }

    return false;
}

bool checkE2(string nodes, bool graph[][26], set<char>& node){
    
    for (int i = 1; i < nodes.length(); i += 6){
        int parent = nodes[i] - 'A';
        int child = nodes[i + 2] - 'A';

        if (graph[parent][child]){
            return true;
        }

        graph[parent][child] = true;

        node.insert(nodes[i]);
        node.insert(nodes[i + 2]);
    }

    return false;
}

static string get_sExpression(char root, bool graph[][26])
{
    string l = "";
    string r = "";

    for (int i = 0; i < 26; i++){
        
        if (graph[root - 'A'][i]){
            
            l = get_sExpression(i + 'A', graph);

            for (int j = i + 1; j < 26; j++){
                
                if (graph[root - 'A'][j]){
                    r = get_sExpression(j + 'A', graph);
                    break;
                }
            }
            break;
        }
    }
    
    string result = "(" + string(1, root) + l + r + ")";

    return result;
}

string sExpression(string nodes)
{
    bool graph[26][26] = {};
    set<char> node;
    
    bool E2 = checkE2(nodes, graph, node);
    
    bool E1 = checkE1(graph);

    if (E1){
        return "E1";
    }
    else if (E2){
        return "E2";
    }

    int numRoots = 0;
    char root = ' ';

    for (char n : node){
        bool found = false;

        for (int i = 0; i < 26; i++){
            if (graph[i][n - 'A']){
                found = true;
                break;
            }
        }

        if (!found){
            numRoots++;
            root = n;

            bool visited[26] = {};

            if (recursion(n, graph, visited)){
                return "E3";
            }
        }
    }

    if (numRoots == 0){
        return "E3";
    }
    else if (numRoots > 1){
        return "E4";
    }
    else if (root == ' '){
        return "E5";
    }
    
    string result = get_sExpression(root, graph);

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nodes;
    getline(cin, nodes);

    string result = sExpression(nodes);

    fout << result << "\n";

    fout.close();

    return 0;
}



///////////////////////////////// Method2 /////////////////////////////////

#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;
#include<map>
#include<vector>
#include<string>

string Recursion(map<char, vector<char>> mymap, char curr) {
    string output = "(";
    output += curr;
    int s = mymap[curr].size();
    if (s == 1) {
        output += Recursion(mymap, mymap[curr][0]);
    } else if (mymap[curr].size() == 2) {
        if (mymap[curr][0] < mymap[curr][1]) {
            output += Recursion(mymap, mymap[curr][0]);
            output += Recursion(mymap, mymap[curr][1]);
        } else {
            output += Recursion(mymap, mymap[curr][1]);
            output += Recursion(mymap, mymap[curr][0]);
        }
    }
    output += ")";
    return output;
}

bool E1(map<char, vector<char>> mymap, set<char> children, set<char> parent) {
    for (auto itr : mymap) {
        if (itr.second.size() > 2) {
            return true;
        }
    }
    return false;
}

bool E2(map<char, vector<char>> mymap, set<char> children, set<char> parent) {
    for (auto itr : mymap) {
        set<char> check = {};
        for (auto vector_itr : itr.second) {
            if (check.find(vector_itr) == check.end()) {
                check.insert(vector_itr);
            } else {
                return true;
            }
        }
    }
    return false;
}

vector<char> find_root(map<char, vector<char>> mymap, set<char> children, set<char> parent) {
    vector<char> output = {};
    for (auto itr : parent) {
        if (children.find(itr) == children.end()) {
            output.push_back(itr);
        }
    }
    return output;
}

bool E3(map<char, vector<char>> mymap, map<char, vector<char>> mymap_reverse, set<char> children, set<char> parent) {
    if (find_root(mymap,children,parent).size() == 0) {
        return true;
    }
    for (auto itr : mymap_reverse) {
        if (itr.second.size() > 1) {
            return true;
        }
    }
    return false;
}

bool E4(map<char, vector<char>> mymap, set<char> children, set<char> parent) {
    if (find_root(mymap, children, parent).size() >= 2) {
        return true;
    }
    return false;
}

string sExpression(string nodes) {

    map<char, vector<char>> mymap;
    map<char, vector<char>> mymap_reverse;
    set<char> parent;
    set<char> children;

    istringstream iss(nodes);
    vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
    for (auto element : results) {

        char p = element[1];
        char c = element[3];
        parent.insert(p);
        children.insert(c);
        if (mymap.find(p) == mymap.end()) {
            vector<char> v = {c};
            mymap[p] = v;
        } else {
            mymap[p].push_back(c);
        }
        if (mymap_reverse.find(c) == mymap_reverse.end()) {
            vector<char> v = {p};
            mymap_reverse[c] = v;
        } else {
            mymap_reverse[c].push_back(p);
        }
    }

    if (E2(mymap, children, parent)) {
        return "E2";
    } else if (E1(mymap, children, parent)) {
        return "E1";
    } else if (E3(mymap, mymap_reverse, children, parent)) {
        return "E3";
    } else if (E4(mymap, children, parent)) {
        return "E4";
    }

    return Recursion(mymap, find_root(mymap, children, parent)[0]);

}

//string sExpression(string nodes)
//{
//
//}




