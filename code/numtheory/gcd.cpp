// Fast GCD(a, b), O(log(min(a,b)))
int gcd(int a, int b) {
    while (a != b) {
      if (a > b) a -= b;
      else b -= a;
    }
    return a;
}

// LCM(a, b), O(log(min(a,b)))
int lcm(int a, int b) {
    return a*b / gcd(a, b);
}
