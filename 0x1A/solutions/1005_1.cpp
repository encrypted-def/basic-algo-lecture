// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/643416ff30264d9fb1290fb046114b8c
#include <bits/stdc++.h>
using namespace std;

int n, k, w;
int a[1005];
int d[1005];
vector<int> adj[1005];

int go(int x){
  if(d[x] != -1)
    return d[x];
  
  d[x] = 0;
  for(int nxt : adj[x])
    d[x] = max(d[x], go(nxt));
  
  return d[x] = d[x] + a[x];
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(d, d+1001, -1);
  int t;
  cin >> t;
  while(t--){
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
      cin >> a[i];
    while(k--){
      int u, v;
      cin >> u >> v;
      adj[v].push_back(u);
    }
    cin >> w;
    cout << go(w) << '\n';

    fill(d, d+n+1, -1);
    for(int i = 1; i <= n; i++)
      adj[i].clear();
  }
}

/*
top-down 방식을 이용한 코드. 자세한 설명은
Appendix E - 다이나믹 프로그래밍 심화 강의 참고.
*/