#include <bits/stdc++.h>

using namespace std;

template <class T>
class UnionFind {
 public:
  UnionFind(size_t n) {
    par_.reserve(n);
    size_.reserve(n);
    for (size_t i = 0; i < n; i++) {
      par_[i] = i;
      size_[i] = 1;
    }
  }

  T Find(T a) {
    if (par_[a] == a) {
      return a;
    }
    par_[a] = Find(par_[a]);
    return par_[a];
  }

  void Union(T a, T b) {
    T par_a = Find(a);
    T par_b = Find(b);
    if (par_a != par_b) {
      par_[par_a] = par_b;
      size_[par_b] += size_[par_a];
    }
  }

  size_t size(T a) { return size_[a]; }

 private:
  vector<T> par_;
  vector<T> size_;
};
