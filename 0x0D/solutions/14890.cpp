// Authored by : jihwan0123
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/9187f01ead404a5388ea1df4e7140121
#include <bits/stdc++.h>
using namespace std;

int n, l;
int row[102][102];
int col[102][102];

int check(int k, int board[][102]) { // 경사로 설치 가능 여부 확인
  int idx = 0;
  int cnt = 1;
  while (idx < n - 1) {
    // 높이 차이가 1보다 크면 설치 불가
    if (abs(board[k][idx + 1] - board[k][idx]) > 1) return 0;
    if (board[k][idx] == board[k][idx + 1]) { // 같으면 다음칸 체크
      cnt++;
      idx++;
    } else if (board[k][idx] < board[k][idx + 1]) { // 다음 칸이 더 높으면
      // l보다 작아서 경사로를 놓을 수 없으면 종료
      if (cnt < l) return 0;
      cnt = 1;
      idx++;
    } else {  // 다음 칸이 더 낮으면
      // l 길이 만큼 길이 없으면 경사로 설치 불가
      if (idx + l > n) return 0;
      for (int i = idx + 1; i < idx + l; i++)
        if (board[k][i] != board[k][i + 1]) return 0;
      idx = idx + l; // 경사로 설치했으면, 설치한 칸부터 다음칸과 비교
      cnt = 0; // 경사로 놓을 수 없는 곳이므로 cnt = 0
    }
  }
  return 1;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> l;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> col[i][j];
      row[j][i] = col[i][j]; // check 함수 하나로 확인하기 위해 전치행렬 저장
    }

  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += check(i, col) + check(i, row);
  cout << ans;
}
/*
2N개의 길에 대해 각각 경사로 설치 여부 확인
*/
