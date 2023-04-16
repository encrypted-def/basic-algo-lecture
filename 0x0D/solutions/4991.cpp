// Authored by : jimi567
// Co-authored by : -
// http://boj.kr/c814e602489940e8aa103587e2d04fb5
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1};
int r, c;
string arr[22];
int vis[22][22];
int dist[22][22][22][22]; //[i][j] -> [x][y] 최단거리(bfs)
int bfs(pair<int, int> st, pair<int, int> dst) {
  for (int i = 0;i < r;i++) fill(vis[i], vis[i] + c, 0); //memset(vis,0,sizeof(vis));
  queue<pair<int, int>> q;
  q.push(st);
  while (!q.empty()) {
    auto cur = q.front();q.pop();
	if (cur.X == dst.X && cur.Y == dst.Y) return vis[cur.X][cur.Y];
	  for (int dir = 0;dir < 4;dir++) {
	    int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c)continue;
		if (arr[nx][ny] == 'x' || vis[nx][ny] > 0) continue;
		vis[nx][ny] = vis[cur.X][cur.Y] + 1;
		q.push({ nx,ny });
	  }
  }
  return -1;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

	while (1) {
		cin >> c >> r; //입력값이 가로가 먼저임을 주의
		if (!r && !c) break;
		pair<int, int> oripos; //로봇 초기 위치
		vector<pair<int, int>> htc; //청소해야되는 좌표(= '*')
		for (int i = 0;i < r;i++) {
			cin >> arr[i];
			for (int j = 0;j < c;j++) {
				if (arr[i][j] == 'o') oripos = { i,j };
				else if (arr[i][j] == '*') htc.push_back({ i,j });
			}
		}
		bool canCleanUp = 1;
		vector<pair<int, int>> starts; //로봇의 시작위치(= 초기위치 + htc위치)
		starts.push_back(oripos);
		for (auto p : htc) starts.push_back(p);
		for (auto st : starts) {
			for (auto dst : htc) {
				dist[st.X][st.Y][dst.X][dst.Y] = bfs(st, dst);
				if (dist[st.X][st.Y][dst.X][dst.Y] > -1) continue;
				canCleanUp = 0;
				break;
			}
			if (!canCleanUp) break;
		}
		int ans = 0x7f7f7f7f;
		pair<int, int> pos; //로봇의 현재위치
		if (canCleanUp) {
			do {
				int cnt = 0;
				pos = oripos;
				for (auto dst : htc) {
					cnt += dist[pos.X][pos.Y][dst.X][dst.Y];
					pos = dst; //로봇 이동
				}
				ans = min(ans, cnt);
			} while (next_permutation(htc.begin(), htc.end()));
			cout << ans << '\n';
		}
		else cout << -1 << '\n';
	}
}
