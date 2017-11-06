// Jack Graham 2017
// primes.cpp

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*  prime_sieve sieves for all primes < n
    PRECONDITION: 
        sizeof(sieve) < n, n > 0
    RUNTIME: 
        O (n log log n)
*/
void prime_sieve(bool* sieve, int n) {
    sieve[0] = false, sieve[1] = false;
    for (int i = 2; i < n; ++i) sieve[i] = true;
    for(int i = 2; i < (int)sqrt(n); ++i)
        if (sieve[i]) for (int j = i*i; j < n; j+=i)
            sieve[j] = false;
}

/*  primes_to returns a vector of all primes <= n
    
    PRECONDITION:
        n > 0
    RUNTIME:
        O(n log log n)
*/
vector<int> primes_to(int n) {
    vector<int> v;
    bool sieve[++n];
    prime_sieve(&sieve[0], n);
    for (int i = 0; i < n; ++i)
        if (sieve[i]) v.push_back(i);
    return v;
}

/*  Euler's totient function
    PRECONDITION:
        n > 0
    RUNTIME:
        O(prime factors of n + sqrt(n))
*/
int phi(int n)
{    
    int result = n;
    int s = (int)sqrt(n);
    bool sieve[s];
    prime_sieve(&sieve[0], s);
    for (int p = 0; p < s; ++p) { 
        if (sieve[p]) { // p is prime
            while (n % p == 0) {
                n /= p;
                result -= result / p;
            }
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}