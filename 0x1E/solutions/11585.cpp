// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/a1ccc7f474624b30a6f184958e4c185b
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000 + 2;

int n, f[MX];
char r[MX], m[MX];

int gcd(int a, int b) {
  if(a == 0) return b;
  return gcd(b % a, a);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> r[i];
  for(int i = 0; i < n; i++) cin >> m[i];

  int j = 0;
  for(int i = 1; i < n; i++) {
    while(j > 0 && m[i] != m[j]) j = f[j - 1];
    if(m[i] == m[j]) f[i] = ++j;
  }

  int cnt = 0; j = 0;
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
룰렛(roulette)은 r배열에 저장하고
찾을 고기(meat) 패턴을 m배열에 저장한다.

m에 대한 실패함수를 구한 후 룰렛과 매칭을 시도한다.

룰렛에는 인덱스 0부터 (n - 1)을 시작점으로 갖는
길이가 n인 n개의 패턴이 있다.
시작점이 i인 패턴의 인덱스는 (n - 1)에 도달하면
0이 된 후 다시 증가하며 (i - 1)까지 오게 된다.

따라서 고기 패턴과 룰렛 배열을 매칭하는데, 
룰렛 배열의 인덱스를 원형으로 반복되게 설정해줘야 한다.
이를 0부터 2*n - 2까지 증가하는 인덱스 i로 나타냈으며,
실제 룰렛 배열 내 인덱스 ci는 0부터 (n - 1) 범위 내에서 제어한다.

이렇게 룰렛 배열과 고기 패턴의 매칭 횟수를 cnt 배열에 기록하고,
n과 cnt의 최대공약수를 구해 cnt/n을 기약분수 형태로 출력한다.
*/