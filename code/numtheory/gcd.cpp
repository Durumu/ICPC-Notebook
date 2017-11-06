// Fast GCD(a, b), O(log(min(a,b)))
int gcd(int a, int b) {
    int t;
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// LCM(a, b), O(log(min(a,b)))
int lcm(int a, int b) {
    return a*b / gcd(a, b);
}