#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
#include <list>
#include <cassert>
#include <functional>
#include <numeric>
#include <iterator>
#include <iomanip>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define pll_INF 9023372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>> 
#define vc vector<char>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define sysp system("PAUSE")
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
#define endl "\n"
#define pi 3.14159265358979
#define int ll
using ll = long long;
using namespace std;
int opow(int a, int b) { int ans = 1; rep(i, b) { ans *= a; }return ans; }
template<class T>int gcd(T a, T b) { if (a < b)swap(a, b); if (a % b == 0)return b; return gcd(a % b, b); }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; }return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; }return 0; }
template<class T>void printv1(vector<T>& v) { for (auto& vv : v) { cout << vv << " "; }cout << endl; }
template<class T>void printv2(vector<vector<T>>& v) { for (auto& r : v) printv1(r); }

template<typename X> // Xはdataの型(int bitset string vector<int>等)
class Segtree { // inputは0-indexed
public:
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
			return e_id;
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
	X query(int a, int b) { // 0-indexed
		if (b < a) swap(a, b);
		return query_sub(a, b + 1, 0, 0, N);
	}
};

signed main() {
	int N, Q; cin >> N >> Q;
	const int Sz = 200001;

	int e = pint_INF;
	auto fx = [](int l, int r) { return min(l,r); };
	Segtree<int> rmq(Sz, fx, e);
	vector<map<int, int, greater<int>>> vec(Sz); // ind_kindergaten -> rating
	map<int, pair<int,int>> child_info; // i-th index - > {kindergarten index, rating}

	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		--b;
		vec[b][a]++;
		child_info[i].first = b;
		child_info[i].second = a;
	}

	//segtree init
	for (int kind_ind = 0; kind_ind < Sz; kind_ind++) {
		if (vec[kind_ind].size() == 0) {
			rmq.update(kind_ind, e);
		}
		else {
			//一番レート高いやつ
			int strongest_of_the_kindergarten = vec[kind_ind].begin()->first;
			rmq.update(kind_ind, strongest_of_the_kindergarten);
		}
	}

	for (int i = 0; i < Q; i++) {
		int C, D; cin >> C >> D;
		--C; --D;
		int prev_child = child_info[C].first;
		int next_child = D;
		child_info[C].first = next_child;

		int rating_child = child_info[C].second;
		vec[prev_child][rating_child]--;
		int prevkind_maxi;
		if (vec[prev_child][rating_child] == 0) {
			vec[prev_child].erase(rating_child);
		}

		if (vec[prev_child].size() == 0) {
			prevkind_maxi = e;
		}else {
			prevkind_maxi = vec[prev_child].begin()->first;
		}

		vec[next_child][rating_child]++;	
		int nextkind_maxi = vec[next_child].begin()->first;

		rmq.update(prev_child, prevkind_maxi);
		rmq.update(next_child, nextkind_maxi);
		int ans = rmq.query(0, Sz - 1);
		cout << ans << endl;;
	}
}