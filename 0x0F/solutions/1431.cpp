// Authored by : std-freejia
// Co-authored by : -
//http://boj.kr/a342438cdab4474bb1c8480dc793ff60
#include <bits/stdc++.h>
using namespace std;

int n;
string st;
vector<string> v;
string numst = "0123456789"; // 숫자 포함 여부 확인용

bool cmp (string& a, string& b){
  int lena = a.size(), lenb = b.size();
  int suma = 0, sumb = 0;
  if(lena != lenb) return lena < lenb;

  for(int i = 0; i < lena; i++){ // 숫자만 더한다.
    if(numst.find(a[i]) <= numst.size()) suma += (a[i] - '0');
  }
  for(int i = 0; i < lenb; i++){
    if(numst.find(b[i]) <= numst.size()) sumb += (b[i] - '0');
  }
  if(suma != sumb) return suma < sumb;
  return a < b; // 사전순
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> st;
    v.push_back(st);
  }
  sort(v.begin(), v.end(), cmp);
  for(auto i : v) cout << i << '\n';
  return 0;
}