// Authored by : syoh0708
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/c50bcbc8af2f4462869639fe0f5b17da
#include <bits/stdc++.h>
using namespace std;

int n, diam;
vector<pair<int, int>> adj[10005];

// cur의 subtree에서 cur와 가장 거리가 먼 정점까지의 거리
int dfs(int cur) {
  vector<int> dist; 

  int first = 0; // cur를 root로 하는 subtree에 속한 정점 중 cur와 가장 거리가 먼 정점까지의 거리
  int second = 0; // cur를 root로 하는 subtree에 속한 정점 중 cur와 두번째로 먼 정점까지의 거리
  // first + second가 트리의 지름 후보임

  for (auto nxt : adj[cur]) {
    // dist : cur의 자식인 nxt을 root로 하는 subtree에 있는 정점 중 cur와 가장 거리가 먼 정점까지의 거리
    int dist = dfs(nxt.first) + nxt.second;
    if(dist > first){ // 제일 긴게 갱신된다면
      second = first;
      first = dist;
    }
    else if(dist > second){ // 두번째로 긴게 갱신된다면
      second = dist;
    }
  }
  // 설령 자식이 1명이라도 second에 0이 들어있어 처리가 자연스럽게 가능
  diam = max(diam, first + second);

  return first;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v, d; cin >> u >> v >> d;
        
    adj[u].push_back({v, d});
  }

  dfs(1);
  cout << diam;
}

/**
 * 각 정점 x를 루트로 잡고 최대한 길게 내려가는 두 양갈래 정점 a, b를 구하고나면
 * a -> x -> b를 트리의 지름 후보로 생각할 수 있다. 이를 재귀적으로 구하면 된다.
*/
