#include <bits/stdc++.h>

using namespace std;

struct custom_hash {
  size_t operator()(const array<int, 2> &p) const {
    auto hash1 = hash<int>{}(p[0]);
    auto hash2 = hash<int>{}(p[1]);
    if (hash1 != hash2) {
      return hash1 ^ hash2;
    }
    return hash1;
  }
};
