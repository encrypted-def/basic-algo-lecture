// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/2461d178f26a4313acf781d37ecfde89
#include <bits/stdc++.h>
using namespace std;

const int MX = 100000 * 10 + 5;
const int ROOT = 1;

int chk[MX];
int nxt[MX][26];
int unused = ROOT + 1;

int ctoi(char c){
  return c - 'a';
}

string insert(string& s){
  int cur = ROOT;
  bool isconfirmed = 0;
  string nick = "";
  for(auto c : s){
    int& next = nxt[cur][ctoi(c)];
    if(!isconfirmed) nick += c;
    if(next == -1) {
      next = unused++;
      isconfirmed = 1;
    }
    cur = next;
  }
  chk[cur]++;
  if(chk[cur] >= 2) nick += to_string(chk[cur]);
  return nick;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < MX; i++)
    fill(nxt[i], nxt[i] + 26, -1);

  int n; cin >> n;
  string s;
  while(n--){
    cin >> s;
    cout << insert(s) << '\n';
  }
}