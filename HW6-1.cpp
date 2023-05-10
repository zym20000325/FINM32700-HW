#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'minMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY maze
 *  2. INTEGER x
 *  3. INTEGER y
 */


// reference: my homework in FINM32500

int minMoves(vector<vector<int>> maze, int x, int y) {
    
    int m = maze.size();
    int n = maze[0].size();

    if (maze[0][0] == 1) {
        return -1;
    }

    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    queue<tuple<int, int, int, int>> q;
    int count = 0;
    int coin_map[m][n];
    memset(coin_map, -1, sizeof(coin_map));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (maze[i][j] == 2) {
                coin_map[i][j] = count++;
            }
        }
    }

    bool visited[m][n][1 << count];
    memset(visited, false, sizeof(visited));
    int first_coin_set = 0;
    if (maze[0][0] == 2) {
        first_coin_set |= 1 << coin_map[0][0];
    }
    q.push({0, 0, first_coin_set, 0});
    visited[0][0][first_coin_set] = true;
    int finished = (1 << count) - 1;

    while (!q.empty()) {
        auto [row, col, grabbed_coins, steps] = q.front();
        q.pop();

        if (row == x && col == y && grabbed_coins == finished) {
            return steps;
        }

        for (auto [dr, dc] : dirs) {
            int u = row + dr;
            int v = col + dc;

            if (u >= 0 && u < m && v >= 0 && v < n && maze[u][v] != 1) {
                int new_grabbed_coins = grabbed_coins;
                if (maze[u][v] == 2) {
                    int coin_id = coin_map[u][v];
                    new_grabbed_coins |= 1 << coin_id;
                }

                if (!visited[u][v][new_grabbed_coins]) {
                    visited[u][v][new_grabbed_coins] = true;
                    q.push({u, v, new_grabbed_coins, steps + 1});
                }
            }
        }
    }

    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string maze_rows_temp;
    getline(cin, maze_rows_temp);

    int maze_rows = stoi(ltrim(rtrim(maze_rows_temp)));

    string maze_columns_temp;
    getline(cin, maze_columns_temp);

    int maze_columns = stoi(ltrim(rtrim(maze_columns_temp)));

    vector<vector<int>> maze(maze_rows);

    for (int i = 0; i < maze_rows; i++) {
        maze[i].resize(maze_columns);

        string maze_row_temp_temp;
        getline(cin, maze_row_temp_temp);

        vector<string> maze_row_temp = split(rtrim(maze_row_temp_temp));

        for (int j = 0; j < maze_columns; j++) {
            int maze_row_item = stoi(maze_row_temp[j]);

            maze[i][j] = maze_row_item;
        }
    }

    string x_temp;
    getline(cin, x_temp);

    int x = stoi(ltrim(rtrim(x_temp)));

    string y_temp;
    getline(cin, y_temp);

    int y = stoi(ltrim(rtrim(y_temp)));

    int result = minMoves(maze, x, y);

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
