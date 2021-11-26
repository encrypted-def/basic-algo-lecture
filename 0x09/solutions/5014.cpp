// Authored by : std-freejia
// Co-authored by : -
// http://boj.kr/b964314a11544ddba420db6f3dab1f22
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int f, s, g, u, d, answer;
int vis[1000002];
bool flag = false;

void bfs(){

  queue<pair<int,int> > qu; // 현재 층, 버튼 클릭 수
  vis[s] = 1; // 현재 위치 방문
  qu.push({s, 0}); // 0 번 클릭

  while(!qu.empty()){
    int curs = qu.front().X;
    int curcnt = qu.front().Y;
    qu.pop();

    if(curs == g) {
      flag = true;
      answer = curcnt;
      break;
    }

    int nexts[2] = {curs + u, curs - d};

    for(auto next : nexts){
      if(next <= f && next > 0 && vis[next] == 0){ // 존재하는 층 범위 및 방문 여부 확인
        vis[next] = 1;
        qu.push({next, curcnt+1});
      }
    }
  }

}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> f >> s >> g >> u >> d;

  bfs();

  if(flag) cout << answer;
  else cout << "use the stairs";

  return 0;
}