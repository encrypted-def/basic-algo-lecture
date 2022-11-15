// Authored by : scsc3204
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/ab41dfbdcc9249aebe5aebea3797a27b
#include <bits/stdc++.h>
using namespace std;

int k, v, e;
int gr[20002];
vector<int> adj[20002];

bool solve() {
  fill(gr, gr + v + 1, -1);
  
  for(int i = 1; i <= v; i++) {
    if(gr[i] != -1) continue;

    queue<int> q;
    q.push(i);
    gr[i] = 0;

    while(!q.empty()) {
      int cur = q.front(); q.pop();
      for(int nxt : adj[cur]) {
        if(gr[nxt] != -1){
          if(gr[nxt] == gr[cur]) return false;
          else continue;
        }
        gr[nxt] = (gr[cur] + 1)%2;
        q.push(nxt);
      }
    }
  }
  return true;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> k;
  while(k--) {
    cin >> v >> e;

    for(int i = 1; i <= v; i++)
      adj[i].clear();

    int i, j;
    while(e--) {
      cin >> i >> j;
      adj[i].push_back(j);
      adj[j].push_back(i);
    }
    if(solve()) cout << "YES\n";
    else cout << "NO\n";
  }
}

/*
gr은 정점이 속한 그룹을 나타내는 변수이다.
방문 전 모든 정점은 gr 값을 -1로 초기화한다.

각 집합에 속한 정점끼리는 서로 인접하면 안 되므로
인접한 정점은 서로 다른 그룹에 속해야한다.
즉, 서로 다른 gr 값을 가져야한다.

solve함수에서는 1번부터 V번 정점을 시작점으로 두고 순회하면서 gr을 확인한다.
시작점이 될 정점은 방문되지 않은 상태여야 하므로 gr 값이 -1이어야 한다.
따라서 gr 값이 -1이 아닌 정점은 시작점으로 두고 순회하지 않는다.

한 번의 순회에서 연결되어 있는 모든 정점을 BFS로 방문하게 된다.
위에서 설명한 것과 같이 각 집합에 속한 정점은 인접하면 안 되므로,
현재 방문한 정점의 gr 값과 다른 값을 다음 방문할 정점의 gr 값으로 할당한다.

다른 두 gr 값은 편의상 0 또는 1로 활용했으며,
28번째 줄 명령을 통해 구현된다.

만약 다음으로 방문야 하는 정점이 이미 방문한 정점이고,
현재 방문한 정점과 같은 gr 값을 갖는다면,
이는 이분 그래프가 아니며, 이에 따라 "NO"를 반환한다.

만약 solve 함수가 "NO"를 반환하지 않고 모든 순회 과정을 마치면
이는 이분 그래프이므로 "YES"를 반환한다.
*/
