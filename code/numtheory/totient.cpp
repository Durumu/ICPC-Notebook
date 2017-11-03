int phi(int n)
{    
    int result = n;
    for (int p : primes_to((int)sqrt(n)))
    {
        while (n % p == 0) {
            n /= p;
            result -= result / p;
        }
    }
 
    if (n > 1)
        result -= result / n;
    return result;
}