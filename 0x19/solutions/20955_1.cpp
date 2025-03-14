// Authored by : scsc3204
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/ae6be2f242b44089a06fe25b5700ac0b
#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000;

int n, m;
int cnt, p[MX + 2];

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void try_merge(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) { cnt++; return; }
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  fill(p, p+n+1, -1);
  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    try_merge(u, v);
  }

  cout << n - m - 1 + 2*cnt;
}
/*
유니온 파인드를 활용한 별해입니다.

간선을 입력 받으면서 merge를 시도합니다.
두 정점의 부모가 동일하지 않다면 merge를 수행합니다.
두 정점의 부모가 동일한 경우
해당 간선은 불필요한 간선이므로
자르는 연산 횟수인 cnt를 증가시킵니다.

이 연산을 완료한 뒤에 남은 간선 수는 총 (m - cnt)개가 됩니다.
여기서 간선을 연결해 (n - 1)개의 간선을 확보해야 트리가 구성됩니다.
따라서 연결해야 하는 간선 수는 (n - 1) - (m - cnt)개가 됩니다.

그러므로 간선을 잇고 자르는 총 연산 수는
(n - 1) - (m - cnt) + cnt = n - m - 1 + 2*cnt이며,
이를 답으로 출력합니다.
*/
