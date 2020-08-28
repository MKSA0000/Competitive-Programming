#include"../INCLUDES.h"

pii add(const pair<int,int>& obj1, const pair<int,int>& obj2) {
    int x = obj1.first + obj2.first;
    int y = obj1.second + obj2.second;
    pii ret = { x,y };
    return ret;
}

template<typename T>
int BFS(vector<vector<T>> & table, pii start) { // {(distance from Start, x-coordinate of max_dist,y-coordinate of max_dist}
    queue<pii> q;
    vector<pii> move = {{1, 0}, { -1, 0 }, { 0,1 }, { 0,-1 } };
    vvi dp(table.size(), vi(table[0].size(), pint_INF));
    dp[start.first][start.second] = 0;
    q.push(start);
    int max = 0;
    pii ret;

    while (!q.empty()) {
        pii u = q.front(); q.pop();
        for (int i = 0; i < move.size(); i++) {
            pii temp = add(u,move[i]);
            if (0 <= temp.first and temp.first < table.size() and 0 <= temp.second and temp.second < table[0].size()) {
                if (table[temp.first][temp.second] == '.' and dp[temp.first][temp.second] == pint_INF) {
                    dp[temp.first][temp.second] = dp[u.first][u.second] + 1;
                    if (dp[temp.first][temp.second] > max) {
                        max = dp[temp.first][temp.second];
                        ret = { temp.first,temp.second };
                    }
                    q.push(temp);
                }
            }
        }
    }

    //vi vec = { max, ret.first, ret.second };
    return max;
}

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> table(H, vector<char>(W));
    int dist = 0;
    rep(i, H)rep(j, W) cin >> table[i][j];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (table[i][j] == '.') {
                BFS(table, { i,j }) > dist ? dist = BFS(table, { i,j }) : 1;
            }
        }
    }
    cout << dist << endl;

}
