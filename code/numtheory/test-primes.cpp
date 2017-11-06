#include <iostream>
#include <vector>
#include "primes.cpp"

using namespace std;

int main() {
    // Testing of functions in primes.cpp

    // Test of prime_sieve
    int ssz = 100000;
    bool sieve[ssz];
    int n = 100;
    prime_sieve(&sieve[0], n); // primes < 100
    for (int i = 0; i < n; ++i)
        if (sieve[i]) cout << i << ' ';
    cout << endl;
    // OUTPUT: 
    // 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97

    for (int p : primes_to(100))
        cout << p << ' ';
    cout << endl;
    // OUTPUT: 
    // 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97

    // Test     
}