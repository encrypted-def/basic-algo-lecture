// Authored by : diyamea
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/83a68d1bac5641b7927f9c4bab434237
#include <bits/stdc++.h>
using namespace std;

//clockwise
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

//counter-clockwise
int cdx[4] = {0,-1,0,1};
int cdy[4] = {1,0,-1,0};

int r,c,t;
int room[55][55];


int machine_bottom;

void dust_spread() {
  int dummy[55][55] = {};
  int dummy2[55][55] = {};
  for(int i{}; i<r; ++i) {
    for(int j{}; j<c; ++j) {
      if(room[i][j] <= 0) continue;
      dummy2[i][j] = room[i][j];
      for(int dir{}; dir<4; ++dir) {
        auto x = i+dx[dir];
        auto y = j+dy[dir];
        if(x < 0 || y < 0 || x >= r || y >= c) continue;
        if(room[x][y] == -1) continue;
        dummy[x][y] += room[i][j]/5;
        dummy2[i][j] -= room[i][j]/5;
      }
    }
  }
  for(int i{}; i<r; ++i) {
    for(int j{}; j<c; ++j) {
      if(room[i][j] == -1) continue;
      room[i][j] = dummy[i][j]+dummy2[i][j];
    }
  }
}

void clockwise_wind(int i, int j, int dir, int prev_dust) {
  if(room[i][j] == -1) return;

  auto move_dust = room[i][j];
  room[i][j] = prev_dust;
  auto x = i+dx[dir];
  auto y = j+dy[dir];
  if(x < 0 || y < 0 || x >= r || y >= c) {
    dir++;
    x = i+dx[dir];
    y = j+dy[dir];
    clockwise_wind(x, y, dir, move_dust);
  }
  else
    clockwise_wind(x, y, dir, move_dust);
}

void counter_clockwise_wind(int i, int j, int dir, int prev_dust) {
  if(room[i][j] == -1) return;

  auto move_dust = room[i][j];
  room[i][j] = prev_dust;
  auto x = i+cdx[dir];
  auto y = j+cdy[dir];
  if(x < 0 || y < 0 || x >= r || y >= c) {
    dir++;
    x = i+cdx[dir];
    y = j+cdy[dir];
    counter_clockwise_wind(x, y, dir, move_dust);
  }
  else
    counter_clockwise_wind(x, y, dir, move_dust);
}

void air_cleaner() {
  auto x2 = machine_bottom;
  auto x1 = x2-1;

  counter_clockwise_wind(x1, 1, 0, 0);
  clockwise_wind(x2, 1, 0, 0);
}

int dust_sum() {
  int sum = 0;
  for(int i{}; i<r; ++i) {
    for(int j{}; j<c; ++j) {
      if(room[i][j] == -1) continue;
      sum += room[i][j];
    }
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c >> t;

  for(int i{}; i<r; ++i) {
    for(int j{}; j<c; ++j) {
      cin >> room[i][j];
      if(room[i][j] == -1)
        machine_bottom = i;
    }
  }
  while(t--) {
    dust_spread();
    air_cleaner();
  }

  cout << dust_sum();
}
