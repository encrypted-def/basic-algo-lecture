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
/*
p가 10^7 언저리이면 p^2는 a와 b 사이이나 p^3이 long long 범위를 벗어날 수 있다.
integer overflow 방지를 위해 i = p, p^2, p^3, ... 으로 두고 이 때 i*p가 거의 소수인데
i <= b / p 이 아니면(i*p <= b가 아니면) break를 하는 방식을 사용해 i*p를 계산할 때
overflow가 발생하지 않도록 한다.
*/
