// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/0b00507b5e3743d4b95451fa8bf75ba9
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int num[10];

void func(int k, int st){
  if(k == m){
    for(int i = 0; i < m; i++)
      cout << num[arr[i]] << " ";
    cout << "\n";
    return;
  }

  for(int i = st; i < n; i++){
    arr[k] = i;
    func(k+1, i);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> num[i];
  sort(num, num+n);
  func(0, 0);
}
