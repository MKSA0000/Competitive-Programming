#include"../INCLUDES.h"
    
vector<vector<int>> next_combination(int N, int K) {
    vector<vector<vector<int>>> comb(K + 1, vvi());
    for (int i = 0; i < N; i++) {
        comb[1].push_back({ i });
    }
    for (int i = 1; i < K; i++) {
        for (auto& v : comb[i]) {
            // 単調増加なので、末尾の値以上であるものを全て試す
            int b = v.back();
            for (int a = b+1; a < N; a++) {
                auto v2 = v;
                v2.push_back(a);
                comb[i + 1].push_back(v2);
            }
        }
    }
    return comb[K];
}
