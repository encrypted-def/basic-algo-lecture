// Authored by : ximgea
// Co-authored by : -
// http://boj.kr/b3cbd97a07514681bfd56276392a95fd
#include <bits/stdc++.h>
using namespace std;

int dx[8] = {1,0,-1,0,-1,1,1,-1};
int dy[8] = {0,1,0,-1,1,1,-1,-1};

string board[10];
int n,m,k;

vector<string> select(int x, int y, int z) {

  vector<string> ret = {};
  string cur {board[x][y]};

  if(z == 1) {
    ret.push_back(cur);
    return ret;
  }
  //start at point (x,y)
  //then select z words
  for(int dir{}; dir<8; ++dir) {
    auto cx = x+dx[dir];
    auto cy = y+dy[dir];

    //OOB TEST
    if(cx < 0) cx = n-1;
    else if(cx >= n) cx = 0;

    if(cy < 0) cy = m-1;
    else if(cy >= m) cy = 0;

    for(auto& it : select(cx,cy,z-1)) {
      ret.push_back(cur+it);
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;
  for(int i{}; i<n; ++i)
    cin >> board[i];

  unordered_map<string, int> table {};

  for(int i{}; i<n; ++i)
    for(int j{}; j<m; ++j)
      for(int len{1}; len<=5; ++len)
        for(auto& str : select(i,j,len))
          if(table.find(str) == table.end())
            table[str] = 1;
          else
            table[str]++;

  for(int i{}; i<k; ++i) {
    string word;
    cin >> word;
    cout << table[word] << '\n';
  }
}
