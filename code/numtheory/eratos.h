#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N = 100000; 

bitset<N> eratos() {
  bitset<N> sieve; sieve.set();
  sieve[0] = sieve[1] = 0;
  for (int i = 2; i < N; ++i) {
    if (not sieve[i]) continue;
    for (ll j = i*i; j < N; j += i) 
      sieve[j] = 0;
  }
  return sieve;
}
