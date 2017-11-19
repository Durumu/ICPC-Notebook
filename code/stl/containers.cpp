// Jack Graham
// containers.cpp

#include <iostream>

#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#define n 10000
#define log2n 14

void vector_features() {
    // Declare vector with initial size, O(n)
    vector<int> v(n);
   
    // Populating vector with things
    for (int i = 0; i < n; ++i)
        v.at(i) = i*i;

    // Looking at the vector's ends
    cout << v.front() << ' ' << v.back() << endl;
    // should be:
}

int main() {

}