// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/2fe6deab624e4c83b409ab234ee8aa48
#include <bits/stdc++.h>
using namespace std;

int func(int n) {
  int i = 1, sum = 0;
  while (n > i) sum += i * i, n -= i++;
  return sum + i * n;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  cin >> a >> b;
  cout << func(b) - func(a - 1);
}
/*
수열을 (1) (2 2) (3 3 3) ... 과 같이 묶으면 i 번째 군의 합은 i * i임을 이용했다.
*/
