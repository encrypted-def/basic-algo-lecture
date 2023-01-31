// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/a2f78447b24e4d9c822110b818c32699
#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
  vector<int> primes;
  vector<bool> state(n + 1, true);
  state[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (!state[i]) continue;
    for (int j = i * i; j <= n; j += i)
      state[j] = false;
  }
  for (int i = 2; i <= n; i++) {
    if (state[i]) primes.push_back(i);
  }
  return primes;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> primes = sieve(10000000);
  long long a, b;
  cin >> a >> b;
  int cnt = 0;
  for (int p : primes) {
    for (long long i = p; i <= b / p; i *= p)
      cnt += (i * p >= a);
  }
  cout << cnt;
}
