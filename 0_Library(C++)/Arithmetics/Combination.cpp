#include "../INCLUDES.h"

template<long long _MOD>
class MyCombination{
private:
	vector<long long> fac, ifac;
public:
	MyCombination(long long SIZE = 200001){
		fac.resize(SIZE);
		ifac.resize(SIZE);
		fac[0] = 1;
		ifac[0] = 1;
		for (int i = 0; i < SIZE - 1; i++){
			fac[i + 1] = fac[i] * (i + 1) % _MOD;				// n!(mod M)
			ifac[i + 1] = ifac[i] * mpow(i + 1, _MOD - 2) % _MOD; // k!^{M-2} (mod M) ←累乗にmpowを採用
		}
	}

	int mpow(int x, int n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
		int ans = 1;
		while (n != 0)
		{
			if (n & 1)
				ans = ans * x % _MOD;
			x = x * x % _MOD;
			n = n >> 1;
		}
		return ans;
	}

	int comb(int a, int b){ //aCbをmod計算
		if (a == 0 && b == 0)
			return 1;
		if (a < b || a < 0)
			return 0;

		int tmp = ifac[a - b] * ifac[b] % _MOD;

		return tmp * fac[a] % _MOD;
	}
};

class Lcombination{
public:
	int PowIterative(int a, int b)
	{
		int res = 1;
		for (; b > 0; b >>= 1, a = a * a % MOD)
		{
			if (b % 2 == 1)
			{
				res = res * a % MOD;
			}
		}
		return res;
	}
	int Lcomb(int n, int k)
	{
		int ans = 1;
		ans = LPerm(n, k);
		int FactorialA = LPerm(k, k);
		FactorialA = PowIterative(FactorialA, MOD - 2);
		ans *= FactorialA;
		ans %= MOD;
		return ans;
	}
	int LPerm(int n, int k)
	{
		int res = 1;
		for (int i = 0; i < k; i++)
		{
			res *= n - i;
			res %= MOD;
		}
		return res;
	}
};