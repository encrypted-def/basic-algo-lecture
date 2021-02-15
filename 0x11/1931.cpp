// http://boj.kr/78a1da4606a04caab418333f8fa4f001
#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> s[100005]; // schedule, 정렬의 편의를 위해 {끝 시간, 시작 시간}으로 저장

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> s[i].second >> s[i].first;
  sort(s,s+n); // 먼저 끝나는 시간을 비교하고, 끝나는 시간이 동일하면 시작 시간 순으로 정렬
  int ans = 0;
  int t = 0; // 현재 시간
  for(int i = 0; i < n; i++){
    if(t > s[i].second) continue; // 시작 시간이 현재 시간보다 이전인 회의라면 무시
    ans++; // 시작 시간이 현재 시간 이후인 회의를 찾았으므로 회의의 수에 1 증가
    t = s[i].first; // 현재 시간을 s[i]의 끝나는 시간으로 변경한다.
  }
  cout << ans;
}
