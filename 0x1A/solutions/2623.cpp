// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/ab569c7de568444cbf1cd16ed9e4fb55
#include <bits/stdc++.h>
using namespace std;

int n, m;
int id[1002];
vector<int> adj[1002];
vector<int> sq;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  int no, u, v;
  for(int i = 0; i < m; i++) {
    cin >> no;
    if(no == 0) continue;
    cin >> u;
    while(--no) {
      cin >> v;
      adj[u].push_back(v);
      id[v]++;
      swap(u, v);
    }
  }

  queue<int> q;
  for(int i = 1; i <= n; i++)
    if(!id[i]) q.push(i);

  while(!q.empty()) {
    int cur = q.front(); q.pop();
    sq.push_back(cur);
    for(int nxt : adj[cur])
      if(--id[nxt] == 0) q.push(nxt);
  }
  if(sq.size() != n) cout << 0;
  else for(auto s : sq) cout << s << ' ';
}
/*
이 풀이에서는 출연자 순서를 그래프로 추상화한다.

가수 번호를 순차적으로 입력 받는데,
이들을 u에서 v로 가는 간선이라 가정하여
indegree 값을 계산한다.

예제 입력 중 한 줄인 3 1 4 3에서
간선의 정보를 아래와 같이 설정한다.
1 -> 4 / 4 -> 3 (1에서 4로 가는 간선 / 4에서 3으로 가는 간선)
이 경우 4와 3의 indegree를 각각 1씩 증가시킨다.

indegree는 0인 정점은 자신에게 들어오는 간선이 없다는 것이므로,
해당 정점들은 현재 출연 가능한 가수가 된다.

따라서 이런 정점에 대해 BFS를 수행하며,
BFS에서 차례가 되었을 때 출연자 순서를 담는 배열인 sq에 넣는다.
큐에서 나온 정점들에 인접한 정점들은 indegree를 하나씩 감소시킨다.
이 과정에서 또 indegree가 0인 정점이 확인되면 큐에 넣고 BFS를 수행한다.

만약 이러한 과정을 마쳤을 때 출연자 순서를 담는 벡터인 sq의 크기가
출연자의 총 숫자와 같지 않다면 순서를 정하는 것이 불가능한 경우이므로
첫째 줄에 0을 출력한다.

출연자 순서를 담는 벡터인 sq의 크기가 출연자의 총 숫자와 같다면
벡터 sq의 원소를 출력한다.
*/