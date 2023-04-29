#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
public:
  SegmentTree(vector<int> &arr, int size) {
    n_ = size;
    tree_.resize(4 * n_);
    lazy_.resize(4 * n_);
    build_helper(arr, 0, n_ - 1, 0);
  }

  int query(int left, int right) {
    return query_helper(0, 0, n_ - 1, left, right);
  }

  void update(int left, int right, int val) {
    update_helper(0, 0, n_ - 1, left, right, val);
  }

private:
  vector<int> tree_, lazy_;
  int n_;

  void build_helper(vector<int> &arr, int start, int end, int node) {
    if (start == end) {
      tree_[node] = arr[start];
    } else {
      int mid = (start + end) / 2;
      build_helper(arr, start, mid, node * 2 + 1);
      build_helper(arr, mid + 1, end, node * 2 + 2);
      tree_[node] = tree_[node * 2 + 1] + tree_[node * 2 + 2];
    }
  }

  void propagate(int node, int start, int end) {
    if (lazy_[node] != 0) {
      tree_[node] += (end - start + 1) * lazy_[node];
      if (start != end) {
        lazy_[node * 2 + 1] += lazy_[node];
        lazy_[node * 2 + 2] += lazy_[node];
      }
      lazy_[node] = 0;
    }
  }

  int query_helper(int node, int start, int end, int left, int right) {
    propagate(node, start, end);
    if (right < start || end < left) {
      return 0;
    }
    if (left <= start && end <= right) {
      return tree_[node];
    }
    int mid = (start + end) / 2;
    int sum_left = query_helper(node * 2 + 1, start, mid, left, right);
    int sum_right = query_helper(node * 2 + 2, mid + 1, end, left, right);
    return sum_left + sum_right;
  }

  void update_helper(int node, int start, int end, int left, int right,
                     int val) {
    propagate(node, start, end);
    if (right < start || end < left) {
      return;
    }
    if (left <= start && end <= right) {
      tree_[node] += (end - start + 1) * val;
      if (start != end) {
        lazy_[node * 2 + 1] += val;
        lazy_[node * 2 + 2] += val;
      }
      return;
    }
    int mid = (start + end) / 2;
    update_helper(node * 2 + 1, start, mid, left, right, val);
    update_helper(node * 2 + 2, mid + 1, end, left, right, val);
    tree_[node] = tree_[node * 2 + 1] + tree_[node * 2 + 2];
  }
};
