#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <typename T>
class RollingHash {
 public:
  static ll mul0, mul1;
  static vector<vector<ll>> pmo;

  RollingHash(vector<T>& arr) { init(arr); }

  RollingHash(string& s) {
    vector<T> arr(s.size());
    for (int i = 0; i < s.size(); i++) {
      arr[i] = s[i] - 'a';
    }
    init(arr);
  }

  pair<ll, ll> Hash(int l, int r) {
    assert(l <= r);
   
    while ((int)pmo[0].size() < r + 2) {
      pmo[0].push_back(pmo[0].back() * mul0 % mo0_);
      pmo[1].push_back(pmo[1].back() * mul1 % mo1_);
    }
    ll hash1 =
        (hash_[0][r + 1] + (mo0_ - hash_[0][l] * pmo[0][r + 1 - l] % mo0_)) %
        mo0_;
    ll hash2 =
        (hash_[1][r + 1] + (mo1_ - hash_[1][l] * pmo[1][r + 1 - l] % mo1_)) %
        mo1_;
    return {hash1, hash2};
  }

  pair<ll, ll> Hash() { return Hash(0, l_ - 1); }

  bool Same(int l1, int r1, int l2, int r2) {
    auto [h1, h2] = Hash(l1, r1);
    auto [h3, h4] = Hash(l2, r2);
    return h1 == h3 && h2 == h4;
  }

  pair<ll, ll> concat(pair<ll, ll> L, pair<ll, ll> R, int RL) {
    while (pmo[0].size() < RL + 2) {
      pmo[0].push_back(pmo[0].back() * mul0 % mo0_);
      pmo[1].push_back(pmo[1].back() * mul1 % mo1_);
    }
    return {(R.first + L.first * pmo[0][RL]) % mo0_,
            (R.second + L.second * pmo[1][RL]) % mo1_};
  }

 private:
  void init(vector<T>& arr) {
    l_ = arr.size();
    hash_.resize(2);
    hash_[0] = hash_[1] = vector<ll>(1, 0);

    if (mul0 == -1) {
      mul0 = 10009 + (((ll)&mul0 + time(NULL)) >> 5) % 1259,
      mul1 = 10007 + (((ll)&mul1 + time(NULL)) >> 5) % 2257;
      pmo = {{1}, {1}};
    }

    for (int i = 0; i < l_; i++) {
      hash_[0].push_back((hash_[0].back() * mul0 + add0_ + arr[i]) % mo0_);
    }

    for (int i = 0; i < l_; i++) {
      hash_[1].push_back((hash_[1].back() * mul1 + add1_ + arr[i]) % mo1_);
    }
  }

  const ll mo0_ = 1000000021, mo1_ = 1000000009;
  const ll add0_ = 1000010007, add1_ = 1003333331;
  vector<vector<ll>> hash_;
  int l_;
};

template <typename T>
ll RollingHash<T>::mul0 = -1;

template <typename T>
ll RollingHash<T>::mul1 = -1;

template <typename T>
vector<vector<ll>> RollingHash<T>::pmo;
