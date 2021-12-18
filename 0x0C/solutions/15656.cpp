// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/6caa5519520247128be896a27dbc46fa
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a;
int ans[10];

void func(int k){
  if(k == m){
    for(int i = 0; i < m; i++) cout << ans[i] << " ";
    cout << "\n";
    return;
  }

  for(int i = 0; i < n; i++){
    ans[k] = a[i];
    func(k+1);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  sort(a.begin(), a.end());
  func(0);
}
