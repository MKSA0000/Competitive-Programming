#include "../INCLUDES.h"

/*
以下は半開区間[start,end)で管理する

sum squareは[x_st,x_ed] x [y_st,y_ed]に含まれる値の和を返す
*/
template <typename T> //基本こいつにはアクセスしない
vector<vector<T>> accum2d(vector<vector<T>> &vec)
{ // 0-indexed
    int H = vec.size();
    int W = vec[0].size();
    vector<vector<T>> res(H + 1, vector<T>(W + 1));
    for (int i = 1; i < H + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            res[i][j] = vec[i - 1][j - 1] - res[i - 1][j - 1] + res[i][j - 1] + res[i - 1][j];
        }
    }
    return res;
}

template <typename T> //accum取る前のindexingでsumを計算できる->閉区間queryを投げる
T sum_square(vector<vector<T>> &accum, vector<T> coor0, vector<T> coor1)
{ // 0-indexed find sum of square from coor0 to coor1 weakly order coor0 <= coor1 is required
    T res = accum[coor1[0] + 1][coor1[1] + 1] + accum[coor0[0]][coor0[1]] - accum[coor1[0] + 1][coor0[1]] - accum[coor0[0]][coor1[1] + 1];
    return res;
}

vector<int> accumulate(const vector<int>& vec){
    vector<int> res(vec.size()+1);
    for(int i = 0; i < vec.size(); i++){
        res[i+1] = res[i] + vec[i];
    }
    return res;
}

vector<int> raccumulate(const vector<int> vec){
    reverse(ALL(vec));
    auto res = accumulate(vec);
    reverse(ALL(res));
    return res;
}

struct Compressor2D {
public:
    map<vector<int>, int> coor_mp;
    vector<vector<int>> cmp_table;
    vector<int> cmp_x;
    vector<int> cmp_y;
 
    void compress() {
        set<int> xaxis;
        set<int> yaxis;
 
        for (auto& [key, val] : coor_mp) {
            int x = key[0], y = key[1];
            xaxis.insert(x - 1); xaxis.insert(x); xaxis.insert(x + 1);
            yaxis.insert(y - 1); yaxis.insert(y); yaxis.insert(y + 1);
        }
 
        int sxs = xaxis.size(), sys = yaxis.size();
 
        cmp_x.resize(sxs); cmp_y.resize(sys);
        cmp_table.resize(sxs, vector<int>(sys));
 
        int x_i; set<int>::iterator x_iter;
        int y_j; set<int>::iterator y_iter;
        for (x_i = 0, x_iter = xaxis.begin(); x_iter != xaxis.end(); x_i++, x_iter++) {
            for (y_j = 0, y_iter = yaxis.begin(); y_iter != yaxis.end(); y_j++, y_iter++) {
                int val = coor_mp[{*x_iter, * y_iter}];
                cmp_x[x_i] = *x_iter;
                cmp_y[y_j] = *y_iter;
                cmp_table[x_i][y_j] = val;
            }
        }
    }
};