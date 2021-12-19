// Authored by : windowdong11
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/31c7548b7f964e70b774e9fb393f34bf
#include <bits/stdc++.h>
using namespace std;

char cube[6][3][3];
char color[] = {'w', 'y', 'r', 'o', 'g', 'b'};

const int UP = 0;
const int DOWN = 1;
const int FRONT = 2;
const int BACK = 3;
const int LEFT = 4;
const int RIGHT = 5;

void initGlobal(){
  for(int s = 0; s < 6; ++s)
    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j)
        cube[s][i][j] = color[s];
}

void rotate(int side, bool isclockwise){
  int rot = 1;
  if(!isclockwise) rot = 3;
  while(rot--){
    char tmp[3][3];
    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j)
        tmp[j][2 - i] = cube[side][i][j];
    swap(cube[side], tmp);
  }
}

void rotateside(int side, bool isclockwise){
  rotate(side, isclockwise);
  int rot = 1;
  if(!isclockwise) rot = 3;
  int tmp;
  while(rot--){
    if(side == FRONT){
      for(int i = 0; i < 3; ++i){
        tmp = cube[UP][2][i];
        cube[UP][2][i] = cube[LEFT][2 - i][2];
        cube[LEFT][2 - i][2] = cube[DOWN][0][2 - i];
        cube[DOWN][0][2 - i] = cube[RIGHT][i][0];
        cube[RIGHT][i][0] = tmp;
      }
    }
    else if(side == BACK){
      for(int i = 0; i < 3; ++i){
        tmp = cube[UP][0][i];
        cube[UP][0][i] = cube[RIGHT][i][2];
        cube[RIGHT][i][2] = cube[DOWN][2][2 - i];
        cube[DOWN][2][2 - i] = cube[LEFT][2 - i][0];
        cube[LEFT][2 - i][0] = tmp;
      }
    }
    else if(side == LEFT){
      for(int i = 0; i < 3; ++i){
        tmp = cube[UP][i][0];
        cube[UP][i][0] = cube[BACK][i][0];
        cube[BACK][i][0]  = cube[DOWN][i][0];
        cube[DOWN][i][0] = cube[FRONT][i][0];
        cube[FRONT][i][0] = tmp;
      }
    }
    else if(side == RIGHT){
      for(int i = 0; i < 3; ++i){
        tmp = cube[UP][i][2];
        cube[UP][i][2] = cube[FRONT][i][2];
        cube[FRONT][i][2] = cube[DOWN][i][2];
        cube[DOWN][i][2] = cube[BACK][i][2];
        cube[BACK][i][2] = tmp;
      }
    }
    else if(side == UP){
      for(int i = 0; i < 3; ++i){
        tmp = cube[FRONT][0][i];
        cube[FRONT][0][i] = cube[RIGHT][0][i];
        cube[RIGHT][0][i] = cube[BACK][2][2 - i];
        cube[BACK][2][2 - i] = cube[LEFT][0][i];
        cube[LEFT][0][i] = tmp;
      }
    }
    else{ // DOWN
      for(int i = 0; i < 3; ++i){
        tmp = cube[FRONT][2][i];
        cube[FRONT][2][i] = cube[LEFT][2][i];
        cube[LEFT][2][i] = cube[BACK][0][2 - i];
        cube[BACK][0][2 - i] = cube[RIGHT][2][i];
        cube[RIGHT][2][i] = tmp;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    initGlobal();
    int n;
    cin >> n;
    string s;
    while(n--){
      cin >> s;
      if(s[0] == 'F') rotateside(FRONT, s[1] == '+');
      else if(s[0] == 'B') rotateside(BACK, s[1] == '+');
      else if(s[0] == 'U') rotateside(UP, s[1] == '+');
      else if(s[0] == 'D') rotateside(DOWN, s[1] == '+');
      else if(s[0] == 'L') rotateside(LEFT, s[1] == '+');
      else rotateside(RIGHT, s[1] == '+');
    }
    for(int i = 0; i < 3; ++i){
      for(int j = 0; j < 3; ++j)
        cout << cube[UP][i][j];
      cout << '\n';
    }
  }
  return 0;
}

/*
매번 회전이 발생했을 때 칸에 적힌 값들이 어떻게 변화하는지를 잘 계산해서 넣어줘야 한다.
시계 방향, 반시계 방향을 다 구현하는 대신 반시계 방향은 시계 방향 회전을 3번 하는
방법으로 구현하면 구현량을 조금이나마 줄일 수 있다.
*/
