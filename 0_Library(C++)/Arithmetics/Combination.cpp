#include"../INCLUDES.h"

class MyCombination{
private:
	vector<long long> fac, ifac;
public:
	ll mpow(ll x, ll n) { //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
		ll ans = 1;
		while (n != 0) {
			if (n & 1) ans = ans * x % MOD;
			x = x * x % MOD;
			n = n >> 1;
		}
		return ans;
	}

	ll comb(ll a, ll b) { //aCbをmod計算
		if (a == 0 && b == 0)return 1;
		if (a < b || a < 0)return 0;

		ll tmp = ifac[a - b] * ifac[b] % MOD;

		return tmp * fac[a] % MOD;
	}

	MyCombination(long long SIZE = 200001) {
		fac.resize(SIZE);
		ifac.resize(SIZE);
		fac[0] = 1;
		ifac[0] = 1;
		for (ll i = 0; i < SIZE - 1; i++) {
			fac[i + 1] = fac[i] * (i + 1) % MOD; // n!(mod M)
			ifac[i + 1] = ifac[i] * mpow(i + 1, MOD - 2) % MOD; // k!^{M-2} (mod M) ←累乗にmpowを採用
		}
	}
};

class Lcombination{
public:
	ll PowIterative(ll a,ll b){
		ll res = 1;
		for(; b > 0; b >>= 1, a = a * a % MOD){
			if(b % 2 == 1){
				res = res * a % MOD;
			}
		}
		return res;
	}
	ll Lcomb(ll n, ll k){
		ll ans = 1;
		ans = LPerm(n,k);
		ll FactorialA = LPerm(k,k);
		FactorialA = PowIterative(FactorialA,MOD-2);
		ans *= FactorialA;
		ans %= MOD;
		return ans;
	}
	ll LPerm(ll n, ll k){
		ll res = 1;
		for(ll i = 0; i < k; i++){
			res *= n-i;
			res %= MOD;
		}
		return res;
	}
};