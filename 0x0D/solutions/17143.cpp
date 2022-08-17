// Authored by : diyamea
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/d1a144e4330c4034b70fd7befaacd314
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
// 0->up , 1->down, 2->right, 3->left

int r, c, m;
int fisherman_pos = 0;
int sum = 0;

vector<tuple<int,int,int>> board[105][105];
vector<tuple<int,int,int>> dummy[105][105];

bool shark_exist(int i, int j) {
  return board[i][j].size() >= 1;
}

void shark_move(int i, int j) {
  int velocity, dir, size;
  tie(velocity, dir, size) = board[i][j][0];
  board[i][j].pop_back();

  // Up Or Down
  if(0 <= dir && dir <= 1) {
    auto mv = velocity % (2*(r-1));
    while(mv--) {
    i += dx[dir];
    j += dy[dir];
      if (i <= 0 || j <= 0 || i > r || j > c) {
        dir = 1-dir;
        i += 2*dx[dir];
        j += 2*dy[dir];
      }
    }
  }
  // Left Or Right
  else {
    auto mv = velocity % (2*(c-1));
    while(mv--) {
    i += dx[dir];
    j += dy[dir];
      if (i <= 0 || j <= 0 || i > r || j > c) {
        dir = 5-dir;
        i += 2*dx[dir];
        j += 2*dy[dir];
      }
    }
  }
  dummy[i][j].push_back({velocity, dir, size});
}

void eat(int i, int j) {
  sort(board[i][j].begin(), board[i][j].end(),
       [](auto& a , auto& b) { return get<2>(a) > get<2>(b);});
  while(board[i][j].size() > 1)
    board[i][j].pop_back();
}

void sharks_move() {
  for(int i = 1; i <= r; ++i)
    for(int j = 1;j <= c; ++j)
      if(shark_exist(i,j))
        shark_move(i,j);

  for(int i = 1; i <= r; i++){
    for(int j = 1; j <= c; j++){
      board[i][j] = dummy[i][j];
      dummy[i][j].clear();
    }
  }

  for(int i = 1; i<=r; ++i)
    for(int j = 1; j<=c; ++j)
      if(board[i][j].size() > 1)
        eat(i,j);
}

int catch_shark(int i, int j) {
  int v, dir, size;
  tie(v, dir, size) = board[i][j][0];
  board[i][j].pop_back();
  return size;
}

void fisherman_turn() {
  fisherman_pos++;
  for(int i{1}; i<=r; ++i)
    if(shark_exist(i, fisherman_pos)) {
      sum += catch_shark(i,fisherman_pos);
      return;
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c >> m;
  int x, y, velocity, dir, size;
  for(int i{}; i<m; ++i) {
    cin >> x >> y >> velocity >> dir >> size;
    board[x][y].push_back({velocity,dir-1,size});
  }

  while(fisherman_pos <= c) {
    fisherman_turn();
    sharks_move();
  }

  cout << sum;
}
