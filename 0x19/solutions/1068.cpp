// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/ef0d4335c54848f8a8da8a558a1984a8
#include <bits/stdc++.h>
using namespace std;

const int MX = 50;

int delnode, cnt;
vector<int> adj[MX + 2];
int p[MX + 2];

void trav(int cur) {
  if(cur == delnode) return;
  if(p[cur] == -1) { cnt++; return; }
  trav(p[cur]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> p[i];
    if(p[i] == -1) continue;
    adj[p[i]].push_back(i);
    adj[i].push_back(p[i]);
  }

  cin >> delnode;
  for(int cur = 0; cur < n; cur++) {
    bool isleaf = 1;
    for(int nxt : adj[cur])
      if(nxt != p[cur] && nxt != delnode)
        isleaf = 0;
    if(isleaf) trav(cur);
  }
  cout << cnt;
}
/*
트리 정보를 통해 간선 정보를 저장한다.

노드 마다 간선 정보를 확인하면서
다음 노드가 부모 노드가 아닌데
이것이 삭제된 노드가 아니라면
리프가 아니라고 판별한다.

리프로 판별된 노드에 대해 순회를 한다.
순회 시 현 노드가 삭제된 노드면 더이상 진행하지 않는다.
만약 부모 노드가 -1인 루트에 도달했다면
여전히 트리에 속한 리프 노드임이 확인된 것이기 때문에 cnt를 증가시킨다.

이후 정답으로 cnt를 출력한다.
*/