#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  while (a) {
    swap(a, b);
    a %= b;
  } 
  return b;
}

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
}

ll mod_inv(ll a, ll m) {
  pair<ll, ll> p;
  ll g = egcd(a, m, p);
  if (g > 1) return -1; // NO SOLUTION
  return (p.F % m + m) % m; // in case x < 0
}
