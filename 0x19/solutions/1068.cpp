// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/b3eaf019e73a47d597bbd7bf69a99f7c
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> child[55];
int del;
int root;
// 문제의 조건대로 del이 root인 subtree를 트리에서 제거한 이후
// x가 root인 subtree에서 leaf node의 수를 반환하는 함수
int go(int x){
  if(x == del) return 0;// x가 del일 경우에는 0 반환
  if(child[x].empty()) return 1; // x 자체가 leaf일 경우 1 반환
  if(child[x].size() == 1 && child[x][0] == del) return 1; // x에 자식 del만 있는 경우 마찬가지로 leaf이니 1 반환
  int ret = 0;
  // x가 leaf가 아닐 경우 go(x) = go(child[x][0])+go(child[x][1])+...
  for(auto nxt : child[x])
    ret += go(nxt);
  return ret;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    int p;
    cin >> p;
    if(p == -1){
      root = i;
      continue;
    }
    child[p].push_back(i);
  }
  cin >> del;
  cout << go(root) << '\n';  
}
