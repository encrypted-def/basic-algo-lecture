// Authored by : scsc3204
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/2396665d65a7478c95fadcb70a0236ab
#include <bits/stdc++.h>
using namespace std;

string t, p;
vector<int> f, ans;

vector<int> failure(){
  vector<int> f(p.size());
  int j = 0;
  for(int i = 1; i < (int)p.size(); i++){
    while(j > 0 && p[i] != p[j]) j = f[j-1];
    if(p[i] == p[j]) f[i] = ++j;
  }
  return f;
}

void solve(){
  int j = 0;
  for(int i = 0; i < (int)t.size(); i++){    
    while(j > 0 && t[i] != p[j]) j = f[j-1];
    if(t[i] == p[j]) j++;
    if(j == (int)p.size()){
      ans.push_back(i + 1 - j);
      j = f[j-1];
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  getline(cin, t);
  getline(cin, p);

  f = failure();
  solve();

  cout << ans.size() << '\n';
  for(int a : ans) cout << (a + 1) << ' ';
}
/*
t와 p 모두 공백이 포함된 문자열을 받아야 하기 때문에
getline을 활용한다.

BOJ 16916과 다르게 일치하는 문자열을 찾아도 계속 진행해야 하기 때문에
j = f[j-1]로 변경한다.
*/
