#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct Compare {
  bool operator() (const pii& a, const pii& b) {
    return pii(-a.first,a.second) < pii(-b.first,b.second);
  }
};

int main() {
  vector<pii> pairs = {{1, 2}, {3, 3}, {3, 4}, {1, 3}, {5, 4}};
  sort(pairs.begin(), pairs.end(), Compare());
  // pairs is now {{5, 4}, {3, 3}, {3, 4}, {1, 2}, {1, 3}}
}
