#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[1005];
int d[1005][1005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> board[i];

  for(int i = 0; i < n; i++)
    d[i][0] = board[i][0] - '0';

  for(int j = 0; j < m; j++)
    d[0][j] = board[0][j] - '0';

  for(int i = 1; i < n; i++){
    for(int j = 1; j < m; j++){
      if(board[i][j] == '0')
        continue;
      d[i][j] = min({d[i-1][j], d[i-1][j-1], d[i][j-1]}) + 1;
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++)
      ans = max(ans, d[i][j]);
  }

  cout << ans * ans << '\n'; 
}
