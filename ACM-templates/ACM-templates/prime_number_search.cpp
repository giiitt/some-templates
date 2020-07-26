/*
Abstract	: Using the Sieve of Eratosthenes to find the primer numbers.
Date		: 7/24/2020
Description	:
*/

#include"my_header.h"

class pns {
	int prime[maxn];
	bool is_prime[maxn];
public:
	int sieve(int n) {
		int p = 0;
		for (int i = 0; i <= n; ++i)
			is_prime[i] = true;
		is_prime[0] = is_prime[1] = false;
		for (int i = 2; i <= n; ++i) {
			if (is_prime[i]) {
				prime[p++] = i;
				for (int j = i + i; j <= n; j += i)
					is_prime[j] = false;
			}
		}
		return p;
	}

	void show_result() {
		int max_search = 20;
		for (int i = 0; i < max_search; i++) {
			cout << sieve(i) << " prime numbers before " << i << endl;
		}
	}
};