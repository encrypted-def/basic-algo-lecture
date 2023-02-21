// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/4b53821dbc8c411ba1913a9f5a0e905c
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000 + 2;

int n;
char input[MX];

vector<int> failure(string &s) {
  vector<int> f(s.size());
  int j = 0;
  for(int i = 1; i < n; i++) {
    while(j > 0 && s[i] != s[j]) j = f[j - 1];
    if(s[i] == s[j]) f[i] = ++j;
  }
  return f;
}

int gcd(int a, int b) {
  if(a == 0) return b;
  return gcd(b % a, a);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> input[i];
  string r(input);
  for(int i = 0; i < n; i++) cin >> input[i];
  string m(input);

  vector<int> f = failure(m);
  int cnt = 0, j = 0;
  for(int i = 0; i < 2*n - 1; i++) {
    int ci = i;
    if(ci >= n) ci -= n;
    while(j > 0 && r[ci] != m[j]) j = f[j - 1];
    if(r[ci] == m[j]) j++;
    if(j == n) { cnt++; j = f[j - 1]; }
  }
  int g = gcd(cnt, n);
  cout << cnt / g << '/' << n / g;
}
/*
룰렛(roulette)은 문자열 r에 저장하고
찾을 고기(meat) 패턴을 문자열 m에 저장한다.

m에 대한 실패함수를 구한 후 룰렛과 매칭을 시도한다.

룰렛에는 인덱스 0부터 (n - 1)을 시작점으로 갖는
길이가 n인 n개의 패턴이 있다.
패턴이 순환되기 때문에, 시작점이 i인 패턴의 인덱스가
(n - 1)에 도달하면 0으로 돌아가 (i - 1)까지 증가한다.

따라서 고기 패턴과 룰렛을 매칭하는데,
룰렛의 인덱스가 순환되도록 구현한다.
이를 0부터 2*n - 2까지 증가하는 인덱스 i로 나타냈으며,
실제 룰렛 내 문자를 가리키는 인덱스 ci는
0부터 (n - 1) 범위 내에서 제어한다.

이렇게 룰렛과 고기 패턴의 매칭 횟수를 cnt 배열에 기록하고,
n과 cnt의 최대공약수를 구해 cnt/n을 기약분수 형태로 출력한다.
*/