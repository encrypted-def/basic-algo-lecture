// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/250280ac422d4be8a7bbc04ad75f695f
#include <bits/stdc++.h>
using namespace std;

const int MXN = 10010;
int lc[MXN], rc[MXN], N, colno, root;
pair<int, int> colLR[MXN];
void inorder(int curr, int d) {
  if (curr == -1) return;
  inorder(lc[curr], d + 1);
  colno++;
  auto &[lcol, rcol] = colLR[d];
  if (!lcol || colno < lcol) lcol = colno;
  if (!rcol || rcol < colno) rcol = colno;
  inorder(rc[curr], d + 1);
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  vector<bool> isRoot(N + 1, true);
  for (int i = 0; i < N; i++) {
    int p, l, r;
    cin >> p >> l >> r;
    lc[p] = l;
    rc[p] = r;

    if (l != -1) isRoot[l] = false;
    if (r != -1) isRoot[r] = false;
  }
  for (int i = 1; i <= N; i++)
    if (isRoot[i]) {
      root = i;
      break;
    }
  int mxWidth = 0, mxDepth = 0;
  inorder(root, 0);
  for (int d = 0; d < N; d++) {
    auto [lcol, rcol] = colLR[d];
    if (lcol + rcol == 0) break;
    int width = rcol - lcol + 1;
    if (mxWidth < width) {
      mxWidth = width;
      mxDepth = d;
    }
  }
  cout << mxDepth + 1 << ' ' << mxWidth;
}
/*
규칙을 살펴보면, 노드의 왼쪽, 노드 자신, 노드의 오른쪽 순으로
열을 채워나가는데, 이는 중위순회(inorder)에 해당합니다.

따라서 먼저 루트 노드를 찾은 뒤, 루트에서부터 중위순회를 돌며
왼쪽부터 열번호를 부여하고, 해당 깊이의 열번호의
최소(left)와 최대(right)를 갱신합니다.
마지막으로 깊이마다 너비를 측정해서 최대 너비를 반환하면 됩니다.
*/