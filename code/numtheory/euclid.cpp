// Jack Graham 2017
// euclid.cpp

#include <vector>

typedef long long ll;

using namespace std;

/*  Efficient extended Euclid's algorithm
    Returns GCD(a, b) with integer solutions for
    xa + by == GCD(a, b)
    PRECONDITION:
        a, b > 0
    RUNTIME:
        O(log(min(a, b)))
*/
int euclid(int a, int b, int &x, int &y) {
    if (a == 0) { // base case
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1; //store recursive call here
    int gcd = euclid(b%a, a, x1, y1);

    x = y1 - x1*b/a; // these calls bubble down
    y = x1;
 
    return gcd;
}

/*  Modular inverse using euclid()
    Returns x s.t (x*a)%m == 1
    PRECONDITION:
        a, m > 0
    RUNTIME:
        O(log(min(a, m)))
*/
int inv(int a, int m) {
    int x, y;
    euclid(a, m, x, y);
    return x;
}

/*  Chinese Remainder Theorem implementation
    Finds the smallest x such that x%d[i] = a[i] for all i
    PRECONDITIONS: 
        d.size()==a.size()
        all elements in d are coprime with all others
    RUNTIME:
        O(n log P) where P is product of all numbers in d
*/
int crt(vector<int> d, vector<int> a) {
    ll product = 1; //product across all d
    for (int i = 0; i < d.size(); ++i) {
        product *= d[i];
    }
    ll result, pp;
    result = 0;
    for (int i = 0; i < d.size(); ++i) {
        pp = product / d[i];
        result += a[i] * inv(pp, d[i]) * pp;
    }
    return (int)(result % product);
}
