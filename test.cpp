#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
using namespace std;

struct pa {
	int x;
	int y;
	int state;
};

int n, m;
int Map[1000][1000];
int check[1000][1000][2];//단순 2D check로는 풀 수가 없음
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int bfs() {
	queue<pa> q;
	q.push(pa{ 0,0,0 });
	check[0][0][0] = true;

	while (q.size()) {
		pa cur = q.front();
		q.pop();

		if (cur.x == n - 1 && cur.y == m - 1) {
			//cur.state값이 0인지 1인지는 알수가 없음
			return check[cur.x][cur.y][cur.state]+1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (nx < 0 || nx >= n) continue;
			if (ny < 0 || ny >= m) continue;

			if (Map[nx][ny] == 0) {
				check[nx][ny][cur.state] = check[cur.x][cur.y][cur.state] + 1;
				q.push(pa{ nx,ny,cur.state});
			}

			else if (Map[nx][ny] == 1) {//벽인 경우
				if (check[nx][ny][cur.state]==0) {
					check[nx][ny][cur.state+1] = check[cur.x][cur.y][cur.state]+1;
					q.push(pa{ nx,ny,cur.state + 1 });
				}
			}
		}//for
	}//while
	return -1;
}



int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < (int)s.length(); j++) {
			Map[i][j] = s[j] - '0';
		}
	}
	memset(check, false, sizeof(check));
	cout << bfs();
	return 0;
}