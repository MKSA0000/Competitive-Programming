#include"../INCLUDES.h"

vector<vector<int>> WarshallFloyd(vector<vector<int>>& vec){
    //return minimum dist table dp[i][j]
    assert(vec.size() == vec[0].size());
    int N = vec.size();
    auto dp = vec;
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    return dp;
};
