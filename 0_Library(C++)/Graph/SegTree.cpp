#include"../INCLUDES.h"

template<typename X> // Xはdataの型(int bitset string vector<int>等)
class Segtree { // inputは0-indexed
private:
	int N = -1;
	vector<X> data; //ゼロに近いほうが親
	function<X(X, X)> func;
	X e_id;
public:
	Segtree(int n_, function<X(X, X)> f, X e) {
		func = f; e_id = e;
		int N_ = 1;
		while (N_ < n_) N_ *= 2;
		N = N_;
		data.resize(2 * N - 1, e_id);
	}

	void update(int k, X d) {
		k += N - 1;
		data[k] = d; //１点更新 // add queryのときは data[k] += a;としなければならない
		while (k > 0) {
			k = (k - 1) / 2;
			data[k] = func(data[k * 2 + 1], data[k * 2 + 2]);
		}
	}

	X query_sub(int a, int b, int k, int l, int r) {
		// k:現在見ているノードの位置  [l,r):dat[k]が表している区間
		if (r <= a || b <= l) { // 範囲外なら考えない
			return 0;
		}
		else if (a <= l && r <= b) { // 範囲内なので自身の値を返す
			return data[k];
		}
		else { // 一部区間が被る時
			X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
			X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
			return func(vl, vr);
		}
	}
	X query(int a, int b){ // 0-indexed
		if (b < a) swap(a, b);
		return query_sub(a, b+1, 0, 0, N);
	}
};

int ctoi(char c){
    return c - 'a';
}

const int s = 26;
bitset<s> operator|(const bitset<s> &lhs, const bitset<s> &rhs){
    bitset<s> r;
    for(int i = 0; i < s; i++){
        r[i] = lhs[i] | rhs[i];
    }
    return r;
}

signed main() {
	int N; cin >> N;
    string t; cin >> t;
    int Q; cin >> Q;
    bitset<s> e = 0;
    auto fx = [](bitset<s> l,bitset<s> r){ return l|r;};
    Segtree<bitset<s>> seg(N,fx,e);
    for(int i = 0; i < t.size(); i++){
        bitset<s> tmp;
        tmp[ctoi(t[i])] = true;

    }

	for(int i = 0; i < Q; i++){
        int x; cin >> x;
        if(x == 1){
            int pos; cin >> pos;
            char c; cin >> c;
            bitset<s> bs; bs[ctoi(c)] = true;
            seg.update(--pos,bs);
        }else{
            int l,r; cin >> l >> r;
            bitset<s> q = seg.query(--l,--r);
            cout << q.count() << endl;
        }
    }
    sysp;
}