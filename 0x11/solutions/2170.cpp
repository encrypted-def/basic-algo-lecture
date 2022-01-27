// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/c5472861d2ee4a1e8f8c3c60f477f0bc
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<pair<int,int>> events;  
  int n;
  cin >> n;
  while(n--){
    int l, r;
    cin >> l >> r;
    events.push_back({l, 1});
    events.push_back({r, -1});
  }
  sort(events.begin(), events.end());
  int cnt = 0; // 현재 선의 개수
  int tot = 0; // 전체 길이(= 답)
  int loc = -1e9; // 현재 위치
  for(auto event : events){
    if(cnt > 0) tot += (event.X - loc);
    loc = event.X;
    cnt += event.Y;
  }
  cout << tot;
}
/*
선의 시작과 끝을 이벤트로 관리해 선이 1개 이상 있는 구간을 계속 더해준다.
*/
