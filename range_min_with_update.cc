#include <bits/stdc++.h>

using namespace std;

template <typename T>
class SegTree {
 public:
  SegTree(int n) : n_(n) {
    int sz = ceil(log2(n));
    sz = 2 * pow(2, sz) - 1;
    tree_ = vector<T>(sz, INT_MAX);
  }

  T QueryMin(int l, int r) { return query_min_util(0, l, r, 0, n_ - 1); }

  void Update(int i, T val) { update_util(0, 0, n_ - 1, i, val); }

 private:
  T query_min_util(int i, int qL, int qR, int l, int r) {
    if (l >= qL && r <= qR) return tree_[i];
    if (l > qR || r < qL) return INT_MAX;
    int m = (l + r) / 2;
    return min(query_min_util(2 * i + 1, qL, qR, l, m),
               query_min_util(2 * i + 2, qL, qR, m + 1, r));
  }

  void update_util(int i, int l, int r, int pos, T val) {
    if (pos < l || pos > r) return;
    if (l == r) {
      tree_[i] = min(val, tree_[i]);
      return;
    }
    int m = (l + r) / 2;
    update_util(2 * i + 1, l, m, pos, val);
    update_util(2 * i + 2, m + 1, r, pos, val);
    tree_[i] = min(tree_[2 * i + 1], tree_[2 * i + 2]);
  }

  int n_;
  vector<T> tree_;
};
