// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/ba68f0cb91a745f0a5bd4e3724ea52b3
#include <bits/stdc++.h>
using namespace std;

const int MX = 10000*500 + 5;
const int ROOT = 1;

int unused = ROOT + 1;
int nxt[MX][26];

int n, m;

int ctoi(char c){
  return c - 'a';
}

void insert(string& s){
  int cur = ROOT;
  for(char c : s){
    if(nxt[cur][ctoi(c)] == -1)
      nxt[cur][ctoi(c)] = unused++;
    cur = nxt[cur][ctoi(c)];
  }
}

bool check(string& s){
  int cur = ROOT;
  for(char c : s){
    if(nxt[cur][ctoi(c)] == -1)
      return 0;
    cur = nxt[cur][ctoi(c)];
  }
  return 1;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;

  for(int i = 0; i < MX; i++)
    fill(nxt[i], nxt[i] + 26, -1);

  string s;
  while(n--){
    cin >> s;
    insert(s);
  }
  int ans = 0;
  while(m--){
    cin >> s;
    ans += check(s);
  }
  cout << ans;
}