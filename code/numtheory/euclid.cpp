int euclid(int a, int b, int *x, int *y) {
    // Extended Euclidean algorithm
    // base case
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int x1, y1; //store recursive call
    int gcd = euclid(b%a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}