// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/bf432c28eda74a7297ea5d6d7d88e85f
#include <bits/stdc++.h>
using namespace std;

int n,k;
int dist[200002];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  int MX = 200000;
  fill(dist,dist+MX,-1);
  deque<int> dq;
  dq.push_back(n);
  dist[n]=0;
  while(!dq.empty()){
    int cur = dq.front(); dq.pop_front();
    if( 2*cur < MX && dist[2*cur] == -1){
      dist[2*cur] = dist[cur];
      dq.push_front(2*cur);
    }
    for(int nxt : {cur-1,cur+1}){
      if(nxt < 0 or nxt >= MX or dist[nxt] != -1) continue;
      dist[nxt] = dist[cur]+1;
      dq.push_back(nxt);      
    }
  } 
  cout << dist[k];
}

/*
0-1 BFS로 해결한 풀이

-1, +1 순이 아닌 +1, -1 순으로 탐색할 경우에는 4 6에 대해 오답 발생 (https://www.acmicpc.net/board/view/144960).
추후 관련 설명 보강 예정
*/
