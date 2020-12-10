#pragma GCC optimize ("O2")
#pragma GCC target ("avx2")
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
#include <bit>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n; i > -1; i--)
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
void OptimizeInput() { cin.tie(0);cout.tie(0); ios::sync_with_stdio(false); }
int opow(int a, int b) { int ans = 1; rep(i, b) { ans *= a; }return ans; }
template<class T>int gcd(T a, T b) { if (a < b)swap(a, b); if (a % b == 0)return b; return gcd(a % b, b); }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; }return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; }return 0; }
template<class T>void printv1(vector<T>& v) { for (auto& vv : v) { cout << vv << " "; }cout << endl; }
template<class T>void printv2(vector<vector<T>>& v) { for (auto& r : v) printv1(r); }
template<class T>void inputv1(vector<T>& v) { for (auto& e : v) { cin >> e; } }
template<class T>void inputv2(vector<vector<T>>& v) { for (auto& r : v)for (auto& e : r) { cin >> e; } }
