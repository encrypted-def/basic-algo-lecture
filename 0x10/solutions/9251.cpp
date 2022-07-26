// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/73844bd37f6a4dbb9e036d53dab8ad65
#include <bits/stdc++.h>
using namespace std;

int d[1005][1005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  cin >> a >> b;

  int len_a = a.length();
  int len_b = b.length();

  for(int i = 1; i <= len_a; i++){
    for(int j = 1; j <= len_b; j++){
      if(a[i-1] == b[j-1]) d[i][j] = d[i-1][j-1] + 1;
      else d[i][j] = max(d[i-1][j], d[i][j-1]);
    }
  }
  cout << d[len_a][len_b];
}
