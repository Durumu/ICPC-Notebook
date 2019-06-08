#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto& (a) : (x))
#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).size()
#define F first
#define S second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const ll MODN = 1000000007;

// O(n log log n), simple sieve
void eratos(vector<bool>& sieve) {
  fill(all(sieve), 1);
  sieve[0] = sieve[1] = 0;
  int n = sieve.size();
  rep(i, 2, n) {
    if (not sieve[i]) continue;
    for (ll j = i*i; j < n; j += i)
      sieve[j] = 0;
  }
}

// O(n), factorization sieve
// less memory efficient than eratos()
// but enables very quick factorization of numbers < N
// pr should be empty, ends with all primes < N
// where N = lp.size()
// lp[X] = 0 if X is prime, else largest prime factor of X
void linear_sieve(vi& pr, vi& lp) {
  fill(all(lp), 0); // delete if lp is guaranteed to be empty
  rep(i, 2, len(lp)) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.pb(i);
    }
    for (int j = 0; j < len(pr) and pr[j]<=lp[i] and i*pr[j]<len(lp); ++j)
      lp[i*pr[j]] = pr[j];
  }
}

// O(log n), compute (x^n) % m
// can be generalized to 
ll modpow(ll x, ll n, int m) {
  ll res = 1;
  while (n) {
    if (n & 1) res = (res * x) % m;
    x = (x * x) % m;
    n >>= 1;
  }
  return res;
}

// O(log (a+b)), regular GCD
int gcd(int a, int b) {
  while (b) {
    swap(a, b);
    b %= a;
  } return a;
}

// O(log (a+b)), extended GCD
ll egcd(ll a, ll b, pair<ll, ll>& out) {
  ll x = 0, y = 1, u = 1, v = 0;
  ll q, r, m, n;
  while (a) {
    q = b/a, r = b%a;
    m = x - u*q, n = y - v*q;
    b = a, a = r, x = u, y = v, u = m, v = n;
  }
  out = {x, y};
  return b;
  // returns GCD
  // x and y solve Bezout's identity
  // ax + by = 1 (mod GCD(a, b))
}

// O(log a + m), compute x such that ax % m == 1
// DEPENDENCY: egcd()
ll mod_inv(ll a, ll m) {
  pair<ll, ll> p;
  ll g = egcd(a, m, p);
  if (g > 1) return -1; // NO SOLUTION
  return (p.F % m + m) % m; // in case x < 0
}

// O(√n), compute Euler's totient function ϕ(n)
// for repeated queries, speed this up with factorization sieve
ll phi(ll n) {
  ll res = n;
  for (ll i = 2; i*i <= n; ++i) {
    if (n % i != 0) continue;
    while (n % i == 0) n /= i;
    res -= res/i;
  }
  if (n > 1) res -= res/n;
  return res;
}

int main() {
  return 0;
}
