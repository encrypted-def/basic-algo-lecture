// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/2ac3becd640f49c0813660ad18387058
#include <bits/stdc++.h>
using namespace std;

const int MX = 20 * 1000 * 2 + 2;
const int ROOT = 1;

int n, unused;
vector<pair<char, int>> trie[MX]; // trie[cur] = {char, nxt}
bool is_wc_app[MX]; // is wild card applicable
bool chk[MX]; // should be removed

int find(char c, int cur) {
  for(auto [d, nxt] : trie[cur])
    if(c == d) return nxt;
  return -1;
}

void insert(string &s, bool code) {
  int cur = ROOT;
  is_wc_app[ROOT] = code;
  for(char c : s) {
    int nxt = find(c, cur);
    if(nxt == -1) {
      nxt = unused;
      trie[cur].push_back({c, unused++});
    }
    is_wc_app[nxt] = code;
    cur = nxt;
  }
  chk[cur] = code;
}

int search(int cur) {
  if(is_wc_app[cur]) return 1;

  int res = chk[cur];
  for(auto [c, nxt] : trie[cur])
    res += search(nxt);
  return res;
}

void solve() {
  fill(is_wc_app, is_wc_app + MX, 0);
  fill(chk, chk + MX, 0);
  unused = 2;

  for(int i = ROOT; i < MX; i++)
    trie[i].clear();
  
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    insert(s, 1);
  }
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    insert(s, 0);
  }
  int ans = search(ROOT);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}
/*
초기 세팅
- N1과 N2가 각각 최대 1000개씩일 수 있으며,
  파일 이름은 20글자 이하기 때문에
  MX값을 20 * 1000 * 2 + 2로 설정했습니다.

  영문 대소문자가 총 52개이므로
  확인해야 하는 문자가 많아 2차원 배열로 다음 노드를 구현할 경우
  시간이 꽤 걸릴 수 있을 거라 판단하여,
  트라이 노드는 페어의 동적 배열 형태로 구현하였습니다.


insert 함수 동작
- 지워야 하는 파일의 이름들을 삽입할 때는
  와일드카드를 붙일 수 있다고 표시합니다.
  이는 cur까지 오면서 만든 문자열 뒤에
  *을 붙여 rm 명령을 할 수 있다는 의미로 구현했습니다.

  예를 들어, 예제에 나온 것 같이 clean이 지워야 하는 문자라면
  (ROOT) -> c -> l -> e -> a -> n을 거치면서 is_wc_app 값을 1로 설정하는데,
  이는 '*', 'c*', 'cl*', 'cle*', 'clea*', 'clean*' 명령을 쓸 수 있는 상태임을 의미합니다.

  이후 삽입이 끝난 후 마지막 노드에는 chk 값을 설정합니다(33번째 줄).

  지우면 안 되는 파일의 이름들을 삽입할 때는
  와일드카드를 적용할 수 없다고 표시합니다(30번째 줄).


search 함수로 연산 수 계산
- search 함수로 인접한 트라이 노드를 확인하며
  필요한 rm 연산 수를 계산합니다.
  특별히 와일드카드를 적용할 수는 없지만
  지워야 하는 파일의 이름은 chk로 표시되어 있기 때문에
  현 노드에서 지워야 하는 연산 수에 이를 추가합니다(39번째 줄).

  만약 현노드에 와일드카드를 적용할 수 있는 경우,
  한 번의 연산이 필요하므로 1을 반환합니다.
*/