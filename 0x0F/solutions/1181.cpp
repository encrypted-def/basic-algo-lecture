// Authored by : tongnamuu
// Co-authored by : -
// http://boj.kr/e365634189b1497a95abaf856df7758f
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  vector<string>a(n);
  for(int i=0;i<n;++i) cin>>a[i];
  sort(a.begin(), a.end(), [](const string& u, const string& v){
    int ul = u.length();
    int vl = v.length();
    if(ul!=vl) return ul < vl;
    return u < v;
  });
  a.erase(unique(a.begin(), a.end()), a.end()); // a에서 중복된 원소를 제거하는 명령
  for(string& s : a) cout<<s<<'\n';
  return 0;
}
