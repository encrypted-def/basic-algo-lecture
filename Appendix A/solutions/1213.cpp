// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/145ce16e207d42008ec94abf8489ec73
#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int ctoi(char c) { return c - 'A'; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  for(auto c : s)
    cnt[ctoi(c)]++;

  int odd_cnt = 0;
  char odd_al;
  for(char c = 'A'; c <= 'Z'; c++) {
    if(cnt[ctoi(c)] % 2 == 0) continue;
    odd_cnt++; odd_al = c;
  }

  if(odd_cnt > 1) {
    cout << "I'm Sorry Hansoo";
    return 0;
  }

  if(odd_cnt) cnt[ctoi(odd_al)]--;

  for(char c = 'A'; c <= 'Z'; c++) {
    int x = cnt[ctoi(c)] / 2;
    while(cnt[ctoi(c)] != x) {
      cout << c;
      cnt[ctoi(c)]--;
    }
  }

  if(odd_cnt) cout << odd_al;

  for(char c = 'Z'; c >= 'A'; c--) {
    while(cnt[ctoi(c)] != 0) {
      cout << c;
      cnt[ctoi(c)]--;
    }
  }
}
/*
입력 받은 문자열에서 각 알파뱃의 등장 횟수를 세고
이를 cnt 변수에 저장한다(15-17번째 줄).

이중 등장 횟수가 홀수인 알파뱃을 확인한다(19-24번째 줄).
만약, 등장 횟수가 홀수인 알파뱃이 1개보다 많다면 
I'm Sorry Hansoo 문자열을 출력하고 함수를 종료한다.

등장 횟수가 홀수인 알파뱃은 그중 하나가 
반드시 문자열 정중앙에 위치해야 하기 때문에,
횟수를 하나 감소시킨 채로 odd_al 변수에 할당해둔다.

이후 A부터 Z까지 확인하면서 cnt가 절반에 도달할 때까지
해당 문자를 출력하면서 cnt를 감소시킨다(33-39번째 줄).

이제 문자열 앞부분 절반이 출력됐으므로,
만약 odd_cnt에 수가 있다면 odd_al을 출력해 중앙에 위치시킨다(41번째 줄).

이후 Z부터 A까지 역순으로 for문을 돌면서
cnt가 0이 될 때까지 감소시키면서 해당 문자를 출력한다(43-48번째 줄).
*/