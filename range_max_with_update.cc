#include <bits/stdc++.h>

using namespace std;

/*
constexpr int n = 1000;
SegTree<int> st(n);
st.Update(0, 1);
auto max_val = st.QueryMax(0, n - 1); // => 1
*/
template <typename T>
class SegTree {
 public:
  SegTree(int n) : n_(n) {
    int sz = ceil(log2(n));
    sz = 2 * pow(2, sz) - 1;
    tree_ = vector<T>(sz);
  }

  T QueryMax(int l, int r) { return query_max_util(0, l, r, 0, n_ - 1); }

  void Update(int i, T val) { update_util(0, 0, n_ - 1, i, val); }

 private:
  T query_max_util(int i, int qL, int qR, int l, int r) {
    if (l >= qL && r <= qR) return tree_[i];
    if (l > qR || r < qL) return INT_MIN;
    int m = (l + r) / 2;
    return max(query_max_util(2 * i + 1, qL, qR, l, m),
               query_max_util(2 * i + 2, qL, qR, m + 1, r));
  }

  void update_util(int i, int l, int r, int pos, T val) {
    if (pos < l || pos > r) return;
    if (l == r) {
      tree_[i] = val;
      return;
    }
    int m = (l + r) / 2;
    update_util(2 * i + 1, l, m, pos, val);
    update_util(2 * i + 2, m + 1, r, pos, val);
    tree_[i] = max(tree_[2 * i + 1], tree_[2 * i + 2]);
  }

  int n_;
  vector<T> tree_;
};
