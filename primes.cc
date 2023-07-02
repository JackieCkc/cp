#include <bits/stdc++.h>

using namespace std;

vector<int> GetPrimes(int mv) {
    vector<int> mp(mv + 1, 1);
    vector<int> arr;
    for (long long i = 2; i <= mv; i++) {
        if (mp[i]) {
            arr.push_back(i);
        } else {
            continue;
        }
        for (long long j = i + i; j <= mv; j += i) {
            mp[j] = 0;
        }
    }
    return arr;
}
