// Authored by : Hot6Mania
// Co-authored by : -
// http://boj.kr/e5fe7cb3d25e4e4d8e1d94eeb95f04c1
#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[1010][1010], d[1010][1010];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  for(int i = 1; i <= n; ++i){
    string s;
    cin >> s;
    for(int j = 1; j <= m; ++j)
      board[i][j] = s[j-1] - '0';
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      if(board[i][j]){
        d[i][j] = min({d[i-1][j], d[i][j-1], d[i-1][j-1]}) + 1;
        ans = max(ans, d[i][j]);
      }
    }
  }
  cout << ans * ans;
}
