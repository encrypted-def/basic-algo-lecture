// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/485b69efb085449ca4c64d848656498b
#include <bits/stdc++.h>
using namespace std;

int n, k;
int d[102][100002];
int w[102];
int v[102];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> w[i] >> v[i];
  
  for(int i = 0; i < n; i++){
    for(int j = 1; j <= k; j++){
      if(i-1 >= 0)
        d[i][j] = d[i-1][j];
      if(j-w[i] >= 0){
        if(i-1 >= 0)
          d[i][j] = max(d[i][j], d[i-1][j-w[i]] + v[i]);
        else
          d[i][j] = v[i];
      }
    }
  }
  cout << d[n-1][k];
}
