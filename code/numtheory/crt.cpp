int crt(vector<int> d, vector<int> a) {
    // finds smallest x such that x%d[i] = a[i] for all i
    // PRECONDITION: d.size()==a.size()
    // and all elements in d are coprime with all others
    int product = 1;
    for (int i = 0; i < d.size(); ++i) {
        product *= d[i];
    }
    int result, pp;
    result = 0;
    for (int i = 0; i < d.size(); ++i) {
        pp = product / d[i];
        result += a[i] * inv(pp, d[i]) * pp;
    }
    return result % product;
}