// Authored by : audwns27
// Co-authored by : -
// http://boj.kr/a9eb8b5b0eea4c5aaa2ffd3331ec2208

#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int day, night, height;
  cin >> day >> night >> height;

  cout << (height - night - 1) / (day-night) + 1;

  return 0;
}

/*

단순 반복문으로 작성시 O(N)으로 heigth < 1,000,000,000 범위에서 시간초과

하루 동안 움직이는 거리 = (day - night)
목표 높이 = height 
목표 도달 당일에는 미끄러지지 않기 때문에 총 (height - night) 높이를 올라가야 한다.

(day - night)미터씩 올라가 (heigth - nigth)미터와 같거나 작은 거리가 남는 날이 정답. 

만일 (height - night)가 정확히 (day - night)로 나누어떨어지지 않는다면, 몫에 1을 더한 값이 정답.

하지만 (height - night)가 정확히 (day - night)로 나누어떨어지는 경우를 감안해서 처음부터 (height - night)에 1을 더 빼고 나눈 후, 무조건 1을 더하는 방식 사용.

*/