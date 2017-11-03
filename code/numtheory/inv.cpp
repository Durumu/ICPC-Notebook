int inv(int a, int m) {
    int x, y;
    euclid(a, m, &x, &y);
    return x;
}