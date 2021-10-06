// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/39302be343944bda8d83b89a00b24759
#include <bits/stdc++.h>
using namespace std;

const int LMT = 100001;
int board[LMT+2];
int sis, bro;
queue<int> Q;
void teleport(int num) {
  int tmp = num;
  if (!tmp) return;
  while (tmp < LMT && !board[bro]) {
    if (!board[tmp]) {
      board[tmp] = board[num];
      Q.push(tmp);
      if (tmp == bro) return;
    }
    tmp <<= 1;
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> sis >> bro;
  board[sis] = 1;
  Q.push(sis);
  teleport(sis);
  while (!board[bro]) {
    int v = Q.front(); Q.pop();
    vector<int> nvLst = { v + 1, v - 1 };
    for (int nv : nvLst) {
      if (nv < 0 || LMT <= nv) continue;
      if (board[nv]) continue;
      board[nv] = board[v] + 1;
      Q.push(nv);
      teleport(nv);
    }
  }
  cout << board[bro]-1;
}

/*
teleport 함수를 이용해 현재 보고 있는 v / nv의 2의 거듭제곱을 한 번에 처리하는 방식으로 풀이한 코드
*/
