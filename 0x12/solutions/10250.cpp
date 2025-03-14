// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/550449db64cd4f6d956ed2b55688df53
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  int h, w, n;
  int fl, no;
  string ans, nostr;
  while(t--){
    cin >> h >> w >> n;
    no = (n - 1) / h + 1;
    fl = (n - 1) % h + 1;
    
    nostr = to_string(no);
    if(nostr.size() == 1)
      nostr = '0' + nostr;

    ans = to_string(fl) + nostr;
    cout << ans << '\n';
  }
}
/*
조건에 따라 엘리베이터에서 가까운, 즉 낮은 번호의 방을
낮은 층에서부터 높은 층까지 채운 후 다음 번호로 넘어간다.

n번째로 도착한 손님에게 방을 부여한다고 하자.
호실의 1, 10의 자리 숫자(no)는 n을 H로 나눈 몫과 관련되며
층수(fl)는 n을 H로 나눈 나머지와 관련된다.
해당 관계는 18-19번째 줄과 같이 정리된다.

만약 호수가 한 자릿수라면 앞에 0을 붙인다.
이후 층수와 호수를 붙여 완성된 방 번호를 출력한다.
*/