#include <bits/stdc++.h>

using namespace std;

class SparseTable {
 public:
  SparseTable(vector<int> &arr) {
    int n = arr.size();
    int k = log2(n) + 1;
    vector<vector<int>> lookup(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
      lookup[i][0] = arr[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 0; (i + (1 << j) - 1) < n; i++) {
        if (lookup[i][j - 1] > lookup[i + (1 << (j - 1))][j - 1]) {
          lookup[i][j] = lookup[i][j - 1];
        } else {
          lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1];
        }
      }
    }
    lookup_ = move(lookup);
  }

  int QueryMax(int l, int r) {
    int j = log2(r - l + 1);
    if (lookup_[l][j] >= lookup_[r - (1 << j) + 1][j]) {
      return lookup_[l][j];
    } else {
      return lookup_[r - (1 << j) + 1][j];
    }
  }

 private:
  vector<vector<int>> lookup_;
};
