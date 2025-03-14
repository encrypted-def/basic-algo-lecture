// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/49443a5d49ac434bba080f88f809a4b0
#include <bits/stdc++.h>
using namespace std;

const int MX = 10000*10 + 5; // 최대 길이가 10인 10000개 문자열 고려
const int ROOT = 1;

int unused = ROOT + 1;
int nxt[MX][10];
bool chk[MX];

int t, n;

int ctoi(char c){
  return c - '0';
}

bool insert(string& s){
  int cur = ROOT;
  for(auto c : s){
    if(nxt[cur][ctoi(c)] == -1)
      nxt[cur][ctoi(c)] = unused++;
    cur = nxt[cur][ctoi(c)];
    if(chk[cur]) return 0;
  }
  if(cur != unused - 1) return 0;
  chk[cur] = 1;
  return 1;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--){
    fill(chk, chk + MX, 0);
    for(int i = 0; i < MX; i++)
      fill(nxt[i], nxt[i] + 10, -1);
    unused = ROOT + 1;
    bool isvalid = 1;

    cin >> n;
    string s;
    while(n--){
      cin >> s;
      if(!insert(s)) isvalid = 0;
    }
    if(isvalid) cout << "YES\n";
    else cout << "NO\n";
  }
}