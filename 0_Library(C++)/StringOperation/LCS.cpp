#include"../INCLUDES.h"

int LCS(string s, string t) {
    if (s.size() == 0 || t.size() == 0) {
        return 0;
    }
    else {
        int Ns = s.size(), Nt = t.size();
        vector<vector<int>> dp(Ns, vi(Nt));
        //inds == 0
        bool fg_s = false;
        for (int indt = 0; indt < Nt; indt++) {
            if (s[0] == t[indt]) fg_s = true;
            if (fg_s) dp[0][indt] = 1;
        }
        //indt == 0
        bool fg_t = false;
        for (int inds = 0; inds < Ns; inds++) {
            if (t[0] == s[inds]) fg_t = true;
            if (fg_t) dp[inds][0] = 1;
        }
        printv2(dp);
        cout << fg_s << fg_t << endl;
        for (int inds = 1; inds < Ns; inds++) {
            for (int indt = 1; indt < Nt; indt++) {
                //上と下からdp maxで進んでゆく
                if (s[inds] == t[indt]) {
                    dp[inds][indt] = dp[inds - 1][indt - 1] + 1;
                }
                else {
                    dp[inds][indt] = max(dp[inds][indt - 1], dp[inds - 1][indt]);
                }
            }
        }
        printv2(dp);
        return dp[Ns - 1][Nt - 1];
    }
}

signed main(){
    string s = "abab";
    string t = "abab";
    LCS(s,t);
    sysp;
}