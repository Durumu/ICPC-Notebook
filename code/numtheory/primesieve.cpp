void prime_sieve(bool* sieve, int n) {
    // populates sieve with each prime < n
    // PRECONDITION: sieve has size < n
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i < n; ++i) sieve[i] = true;
    for(int i = 2; i < (int)sqrt(n); ++i)
        if (sieve[i]) for (int j = i*i; j < n; j+=i)
            sieve[j] = false;
}