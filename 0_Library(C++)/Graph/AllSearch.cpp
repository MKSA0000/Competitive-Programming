#include"INCLUDES.h"

void solve(string s){

}

void AllSearch(int digit, int base, string s) {
    if (digit > 0) {
        for (int i = 0; i < base; i++) {
            AllSearch(digit - 1, base, s + to_string(i));
        }
    }
    else {// 下一桁まで指定済みの想定のもと
        solve(s);
    }
}

//bit全探索

vector<vector<int>> Bitwise_AllSearch(int digit) {
	vector<vector<int>> res;

	for (int bit = 0; bit < (1 << digit); bit++) {
		vector<int> S;
		for (int i = 0; i < digit; i++) {
			if (bit & (1 << i)) {
				S.push_back(i);
			}
		}

		res.push_back(S);
	}

	return res;
}