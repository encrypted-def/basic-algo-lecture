// Authored by : windowdong11
// Co-authored by : -
// http://boj.kr/0350797626e0424db3de3235df4cd01a
#include <bits/stdc++.h>
using namespace std;

char cube[6][3][3];
char color[] = {'w', 'y', 'r', 'o', 'g', 'b'};
enum side{
  up = 0,
  down,
  front,
  back,
  left,
  right,
};

void initGlobal(){
  for(int s = 0; s < 6; ++s)
    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j)
        cube[s][i][j] = color[s];
}
void rotate(int side, bool isclockwise){
  char tmp[3][3];
  if(isclockwise)
    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j)
        tmp[j][2 - i] = cube[side][i][j];
  else 
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
          tmp[2 - j][i] = cube[side][i][j];
  swap(cube[side], tmp);
}

void rotateside(int side, bool isclockwise){
  rotate(side, isclockwise);
  int tmp;
  if(side == side::front){
    if(isclockwise){
      for(int i = 0; i < 3; ++i){
        tmp = cube[side::up][2][i];
        cube[side::up][2][i] = cube[side::left][2 - i][2];
        cube[side::left][2 - i][2] = cube[side::down][0][2 - i];
        cube[side::down][0][2 - i] = cube[side::right][i][0];
        cube[side::right][i][0] = tmp;
      }
    }
    else {
      for(int i = 0; i < 3; ++i){
        tmp = cube[side::up][2][i];
        cube[side::up][2][i] = cube[side::right][i][0];
        cube[side::right][i][0] = cube[side::down][0][2 - i];
        cube[side::down][0][2 - i]= cube[side::left][2 - i][2];
        cube[side::left][2 - i][2] = tmp;
      }
    }
  }
  else if(side == side::back){
    if(isclockwise){
      for(int i = 0; i < 3; ++i){
        tmp = cube[side::up][0][i];
        cube[side::up][0][i] = cube[side::right][i][2];
        cube[side::right][i][2] = cube[side::down][2][2 - i];
        cube[side::down][2][2 - i] = cube[side::left][2 - i][0];
        cube[side::left][2 - i][0] = tmp;
      }
    }
    else {
      for(int i = 0; i < 3; ++i){
        tmp = cube[side::up][0][i];
        cube[side::up][0][i] = cube[side::left][2 - i][0];
        cube[side::left][2 - i][0] = cube[side::down][2][2 - i];
        cube[side::down][2][2 - i] = cube[side::right][i][2];
        cube[side::right][i][2] = tmp;
      }
    }
  }
  else if(side == side::left){
    if(isclockwise){
      for(int i = 0; i < 3; ++i){
        tmp = cube[side::up][i][0];
        cube[side::up][i][0] = cube[side::back][i][0];
        cube[side::back][i][0]  = cube[side::down][i][0];
        cube[side::down][i][0] = cube[side::front][i][0];
        cube[side::front][i][0] = tmp;

      }
    }
    else {
      for(int i = 0; i < 3; ++i){
        tmp = cube[side::up][i][0];
        cube[side::up][i][0] = cube[side::front][i][0];
        cube[side::front][i][0] = cube[side::down][i][0];
        cube[side::down][i][0] = cube[side::back][i][0];
        cube[side::back][i][0] = tmp;
      }
    }
  }
  else if(side == side::right){
    if(isclockwise){
      for(int i = 0; i < 3; ++i){
        tmp = cube[side::up][i][2];
        cube[side::up][i][2] = cube[side::front][i][2];
        cube[side::front][i][2] = cube[side::down][i][2];
        cube[side::down][i][2] = cube[side::back][i][2];
        cube[side::back][i][2] = tmp;
      }
    }
    else {
      for(int i = 0; i < 3; ++i){
        tmp = cube[side::up][i][2];
        cube[side::up][i][2] = cube[side::back][i][2];
        cube[side::back][i][2]  = cube[side::down][i][2];
        cube[side::down][i][2] = cube[side::front][i][2];
        cube[side::front][i][2] = tmp;
      }
    }
  }
  else if(side == side::up){
    if(isclockwise){
      for(int i = 0; i < 3; ++i){
        tmp = cube[side::front][0][i];
        cube[side::front][0][i] = cube[side::right][0][i];
        cube[side::right][0][i] = cube[side::back][2][2 - i];
        cube[side::back][2][2 - i] = cube[side::left][0][i];
        cube[side::left][0][i] = tmp;
      }
    }
    else {
      for(int i = 0; i < 3; ++i){
        tmp = cube[side::front][0][i];
        cube[side::front][0][i] = cube[side::left][0][i];
        cube[side::left][0][i] = cube[side::back][2][2 - i];
        cube[side::back][2][2 - i] = cube[side::right][0][i];
        cube[side::right][0][i] = tmp;
      }
    }
  }
  else if(side == side::down){
    if(isclockwise){
      for(int i = 0; i < 3; ++i){
        tmp = cube[side::front][2][i];
        cube[side::front][2][i] = cube[side::left][2][i];
        cube[side::left][2][i] = cube[side::back][0][2 - i];
        cube[side::back][0][2 - i] = cube[side::right][2][i];
        cube[side::right][2][i] = tmp;
      }
    }
    else {
      for(int i = 0; i < 3; ++i){
        tmp = cube[side::front][2][i];
        cube[side::front][2][i] = cube[side::right][2][i];
        cube[side::right][2][i] = cube[side::back][0][2 - i];
        cube[side::back][0][2 - i] = cube[side::left][2][i];
        cube[side::left][2][i] = tmp;
      }
    }
  }
}

int main()
{
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
      switch (s[0])
      {
      case 'F':
        rotateside(side::front, s[1] == '+');
        break;
      case 'B':
        rotateside(side::back, s[1] == '+');
        break;
      case 'U':
        rotateside(side::up, s[1] == '+');
        break;
      case 'D':
        rotateside(side::down, s[1] == '+');
        break;
      case 'L':
        rotateside(side::left, s[1] == '+');
        break;
      case 'R':
        rotateside(side::right, s[1] == '+');
        break;
      }
    }
    for(int i = 0; i < 3; ++i){
      for(int j = 0; j < 3; ++j)
        cout << cube[up][i][j];
      cout << '\n';
    }
  }
  return 0;
}