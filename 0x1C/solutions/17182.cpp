// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/fc1abbed93dc448298fb2f95392894b5
#include <bits/stdc++.h>
using namespace std;

const int MX = 10;

int adj[MX + 2][MX + 2];
vector<int> comb;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, st; cin >> n >> st;
  for(int i = 0; i < n; i++)
    if(i != st) comb.push_back(i);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> adj[i][j];

  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
  
  int ans = 0x7f7f7f7f;
  do {
    int tmp = adj[st][comb[0]];
    for(int i = 1; i < n - 1; i++)
      tmp += adj[comb[i - 1]][comb[i]];
    ans = min(tmp, ans);
  } while(next_permutation(comb.begin(), comb.end()));
  
  cout << ans;
}
/*
N이 10으로 모든 순열을 계산할 만하기에 
행성에서 다음 행성으로 이동하는 경로를 next_permutation으로 확인합니다.

시작 행성인 st를 제외한 나머지 행성 번호는 comb에 추가합니다.
플로이드 알고리즘으로 한 행성에서 다른 행성으로 이동하는 최소 시간을 구합니다.
이후 모든 순열을 확인하며 모든 행성을 탐사하는 데 걸리는 최소 시간을 계산합니다.
*/