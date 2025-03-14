// Authored by : jihwan0123
// Co-authored by : BaaaaaaaaaaarkingDog, dustmddus
// http://boj.kr/f7b9b1367b054a08a753f1096b829b26
#include <bits/stdc++.h>
using namespace std;

int n, l;
int board[102][102];

bool check(vector<int>& line){
  int idx = 0;
  int cnt = 1; // 현재 보고 있는, 높이가 같은 구간의 길이
  while (idx < n - 1) {
    // 높이 차이가 1보다 크면 설치 불가
    if (abs(line[idx + 1] - line[idx]) > 1) return 0;
    if (line[idx] == line[idx + 1]) { // 같으면 다음칸 체크
      cnt++;
      idx++;
    }
    else if (line[idx] < line[idx + 1]) { // 다음 칸이 더 높으면
      // l보다 작아서 경사로를 놓을 수 없으면 종료
      if (cnt < l) return 0;
      cnt = 1;
      idx++;
    }
    else {  // 다음 칸이 더 낮으면
      // l 길이 만큼 길이 없으면 경사로 설치 불가
      if (idx + l >= n) return 0;
      for (int i = idx + 1; i < idx + l; i++)
        if (line[i] != line[i + 1]) return 0;
      idx = idx + l; // 경사로 설치했으면, 설치한 칸부터 다음칸과 비교
      cnt = 0;
    }
  }
  return 1;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> l;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> board[i][j];
      
  int ans = 0;

  // 가로
  for (int i = 0; i < n; i++){
    vector<int> line;
    for(int j = 0; j < n; j++) line.push_back(board[i][j]);
    ans += check(line);
  }

  // 세로
  for (int i = 0; i < n; i++){
    vector<int> line;
    for(int j = 0; j < n; j++) line.push_back(board[j][i]);
    ans += check(line);
  }
  cout << ans;
}
/*
2N개의 길에 대해 각각 경사로 설치 여부 확인
*/
