long long power(long long x, long long y, int p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}

long long modInverse(long long n, int p) {
  return power(n, p - 2, p);
}
