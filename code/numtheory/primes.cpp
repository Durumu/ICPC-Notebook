// Jack Graham 2017
// primes.cpp

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*  prime_sieve takes a blank sieve and populates it
    with primes
    PRECONDITION: 
        sieve.size() >= 2
    RUNTIME: 
        O (n log log n)
*/
void prime_sieve(vector<bool>& sieve) {
    fill(sieve.begin(), sieve.end(), true);
    sieve[0] = false;
    sieve[1] = false;
    for(int i = 2; i*i < sieve.size(); ++i)
        if (sieve[i]) for (int j = i*i; j < sieve.size(); j+=i)
            sieve[j] = false;
}

/*  primes_to returns a vector of all primes < n
    PRECONDITION:
        n > 0
    RUNTIME:
        O(n log log n)
*/
vector<int>& primes_to(int n) {
    vector<bool> sieve(n);
    vector<int> primes;
    for (int i = 2; i*i < n; ++i) if (!sieve[i]) {
        primes.push_back(i);
        for (int j = i*i; j < n; j+=i) sieve[j] = true;
    }
    return primes;
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
    int sqrtn = (int)sqrt(n);
    vector<bool> sieve(sqrtn);
    prime_sieve(sieve);
    for (int p = 0; p < sqrtn; ++p) { 
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