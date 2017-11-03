vector<int> primes_to(int maxp) {
    // returns a vector of all primes <= maxp
    ++maxp;
    vector<int> v;
    bool sieve[maxp];
    prime_sieve(sieve, maxp);
    for (int i = 0; i < maxp; ++i)
        if (sieve[i]) v.push_back(i);
    return v;
}