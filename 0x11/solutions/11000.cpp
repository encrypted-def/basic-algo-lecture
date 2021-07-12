// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/69b0f4555f01421196fb1b39f9c2c776

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
vector<pair<int,int>> event;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    int s, t;
    cin >> s >> t;
    event.push_back({s, 1});
    event.push_back({t, -1});
  }
  sort(event.begin(), event.end());
  int ans = 0; // 필요한 강의실의 최대 개수
  int curtime = event[0].X; // 현재 시간
  int cur = 0; // 현재 시간에 열려있는 강의실의 개수
  int idx = 0; // 현재 보고있는 event에서의 인덱스
  while(true){
    while(idx < 2*n && event[idx].X == curtime){
      cur += event[idx].Y;
      idx++;      
    }
    ans = max(ans, cur);
    if(idx == 2*n) break;
    curtime = event[idx].X;    
  }
  cout << ans << '\n';
}

/*
문제의 답은 결국 가장 많은 수업이 열리는 시간에서의 수업의 개수이다.
수업 개수의 변화가 발생하는 (s, 1), (t, -1)을 전부 수집한 후 정렬하고 같은 시간대의 event를 묶어서 처리한다.
*/
