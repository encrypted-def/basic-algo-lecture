// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/fd3427431325431ea6a82e4938589c0d
#include <bits/stdc++.h>
using namespace std;

const int LMT = 100001;
int board[LMT + 2];
int prePos[LMT + 2];
int sis, bro;
queue<int> Q;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> sis >> bro;
  board[sis] = 1;
  prePos[sis] = sis;
  Q.push(sis);
  while (!board[bro]) {
    int v = Q.front(); Q.pop();
    for (int nv : { v + 1, v - 1, 2 * v }) {
      if (nv < 0 || LMT <= nv) continue;
      if (board[nv]) continue;
      board[nv] = board[v] + 1;
      prePos[nv] = v;
      Q.push(nv);
    }
  }
  cout << board[bro]-1 << '\n';
  deque<int> track = {bro};
  while (track.front() != sis)
    track.push_front(prePos[track.front()]);
  for (int p : track) cout << p << ' ';
}