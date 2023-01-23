// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/60926cdce50b4a819abe165497d7c1b5
#include <bits/stdc++.h>
using namespace std;

const int MX = 50;

int delnode, cnt, root;
vector<int> child[MX + 2];

void bfs() {
  if(root == delnode) return;
  queue<int> q;
  q.push(root);
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    bool isleaf = 1;
    for(int c : child[cur]) {
      if(c == delnode) continue;
      isleaf = 0;
      q.push(c);
    }
    cnt += isleaf;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    int p; cin >> p;
    if(p == -1) { root = i; continue; }
    child[p].push_back(i);
  }

  cin >> delnode;
  bfs();
  cout << cnt;
}
/*
부모 노드 정보를 역으로 활용해 자녀 노드들을 저장한다.
너비 우선 탐색을 통해 자녀 노드들을 돌아본다.
해당 노드에 삭제된 노드가 아닌 자녀 노드가 있는 경우, 이를 리프가 아니라 판정한다.
해당 노드가 리프인 경우 cnt 변수를 하나 증가시킨다.
이후 정답으로 cnt를 출력한다.
*/
