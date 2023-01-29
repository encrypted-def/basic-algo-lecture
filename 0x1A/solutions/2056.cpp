// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/c67ca9dd2a1442d7affc8f67f894a736
#include <bits/stdc++.h>
using namespace std;

int n, ans;
int dur[10'002]; // work duration
int ind[10'002]; // indegree
vector<int> rel[10'002]; // related node
vector<int> tt[1'000'002]; // time table, finished work

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> dur[i];
    int m; cin >> m;
    if(!m) tt[dur[i]].push_back(i);
    while(m--) {
      int x; cin >> x;
      rel[x].push_back(i);
      ind[i]++;
    }
  }

  for(int t = 0; t <= 1'000'000; t++) {
    for(int finished : tt[t]) {
      ans = t;
      for(int r : rel[finished]) {
        ind[r]--;
        if(ind[r] != 0) continue;
        tt[t + dur[r]].push_back(r);
      }
    }
  }
  cout << ans;
}
/*
정의 - (작업) 소요 시간: 작업을 마치는 데 걸리는 시간

타임테이블(tt)은 흐르는 시간 값으로 인덱싱하며,
vector<int>에는 해당 시간에 끝나는 작업을 기록합니다.

입력을 받을 때 선행 작업이 없는 경우
타임테이블 상의 해당 작업 소요 시간 인덱스에 작업 번호를 기록합니다(21번째 줄).
선행 작업이 있는 경우엔 해당 작업의 인접 리스트에 저장합니다.
또한 선행 작업들의 indegree 값을 증가시킵니다.

29번째 줄부터 시간 t를 백만까지 증가시키며 타임테이블을 확인합니다.
  - 최대 시간 백만은 작업 수 10,000개가 시간 100만큼 순차적으로 진행되어야 하는 때를 상정한 것입니다.

타임테이블 상 그 시간에 마친 작업이 있는 경우 다음 작업을 합니다.
  1. 모든 작업을 완료하기 위해 필요한 최소 시간 값을 갱신합니다: ans = t.
  2. 마친 작업의 인접 리스트를 확인하며 indegree를 감소시킵니다.
    - 만약 indegree가 0인 작업이 있다면 그 작업을 시작할 수 있는 것이기 때문에
      타임테이블 상 마치는 시점(t + dur[r])에 해당 작업 번호를 추가한다.

이같은 방법으로 최상위 선행 작업부터 최하위 선행 작업까지 선행 조건이 완료되는 때마다
타임테이블에 기록할 수 있으며, 마치는 작업이 있을 때마다 ans을 갱신하면
마지막 작업이 끝나는 시점을 저장할 수 있다.
*/