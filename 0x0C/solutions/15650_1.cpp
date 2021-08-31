// Authored by : OceanShape700
// Co-authored by : -
// http://boj.kr/5378d116242244a38cd2d7fc28d8678d
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> a;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  // M의 개수만큼 0을 넣어줌
  for(int i = 0; i < N; ++i)  a.push_back(i < M ? 0 : 1);
  do{
    for(int i = 0; i < N; ++i)
      if(a[i] == 0) cout << i+1 << ' ';
    cout << '\n';
  }while(next_permutation(a.begin(), a.end()));
}
