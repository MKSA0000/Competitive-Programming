#include"../INCLUDES.h"
class LargeNumber {
private:
	bool is_prime[1000000 + 13];// Up to 1e6 + 13
	vector<long long> Prime_table;
public:
	vector<long long> Eratosthenes(const long long N = 1000007) { // return primes up to N
		for (int i = 0; i <= N; i++)
		{
			is_prime[i] = true;
		}
		for (int i = 2; i <= N; i++)
		{
			if (is_prime[i])
			{
				for (int j = 2 * i; j <= N; j += i)
				{
					is_prime[j] = false;
				}
				Prime_table.emplace_back(i);
			}
		}
		return Prime_table;
	}

	template<typename T>
	map<T, T> Factorization(T N) const {
		map<T, T> mp;
		if (N == 1) {
			return mp;
		}

		for (int i = 0; i < Prime_table.size(); i++) {
			while (N % Prime_table[i] == 0) {
				mp[Prime_table[i]]++;
				N /= Prime_table[i];
			}
		}

		if (N > 1) mp[N]++;

		return mp;
	}


	bool isPrime(long long x) {
		if (x == 0 || x == 1) {
			return false;
		}
		return is_prime[x];
	}
};