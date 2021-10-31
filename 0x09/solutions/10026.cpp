// Authored by : seeys
// Co-authored by : -
// http://boj.kr/d5f45854d45a402b8e64682b2b4d300f
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[101][101];
bool vis[101][101];
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; 

void bfs(int i, int j) {
	queue<pair<int, int>> Q;
	Q.push({ i,j });
	vis[i][j] = 1;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;
			vis[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int not_g = 0; //적록색약이 아닌사람
	int is_g = 0; //적록색약인 사람

	// 적록색약이 아닌 사람의 값을 구하기 위한 과정
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j]) {
				not_g++;
				bfs(i, j);
			}
		}
	}

	memset(vis, 0, sizeof(vis)); // 적록색약인 사람을 구하기위한 방문배열 초기화

	// 적록색약은 초록과 빨강을 구분 못하므로 초록이면 빨강으로 바꿔줌
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}

	// 적록색약인 사람의 값을 구하기 위한 과정
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j]) {
				is_g++;
				bfs(i, j);
			}
		}
	}

	cout << not_g << " " << is_g;
	return 0;
}