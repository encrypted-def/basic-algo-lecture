// Authored by : scsc3204
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/1f2b2e61aaa04415ac587b3d77b0fd65
#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[100002];
int score[100002];
vector<int> child[100002];

void dfs(int cur) {
  if(p[cur] != -1)
    score[cur] += score[p[cur]];
  for(int nxt : child[cur])
    dfs(nxt);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> p[i];
    if(p[i] == -1) continue;
    child[p[i]].push_back(i);
  }
  while(m--) {
    int i, w;
    cin >> i >> w;
    score[i] += w;
  }
  dfs(1);
  for(int i = 1; i <= n; i++) cout << score[i] << ' ';
}

/*
매번 칭찬을 아래로 뿌리면 O(nm)이지만 칭찬을
모아두었다가 마지막에 한번에 전파하면 O(n+m)에 해결 가능
*/
