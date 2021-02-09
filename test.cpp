#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <map>
#include <set>
using namespace std;

struct pa {
	int x;
	int y;
};

int Map[55][55];
bool check[55][55];
int D[55][55];
int M = 987654321;
int n, m;

int wallCount = 0;
int virusCount = 0;
int nullCount = 0;

bool flag = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int Min = 987654321;

vector<pa> v;
vector<pa> non_active_virus;

bool check_member(pa k, vector<pa> v) {
	for(int i=0;i<v.size();i++){
		if (k.x==v[i].x && k.y==v[i].y)
			return true;
	}
	return false;
}

bool whereVirus(int x, int y) {
	for (int i = 0; i < v.size(); i++) {
		if (x == v[i].x && y == v[i].y) {
			return true;
		}
	}
	return false;//바이러스 위치가 아님
}

void bfs(queue<pa> q, int cnt);

void dfs(vector<pa>& tmp, int x, int cnt) {
	if (tmp.size() == m) {
		memset(D, 0, sizeof(D));
		memset(check, false, sizeof(check));
		queue<pa> q;

		for (int i = 0; i < v.size(); i++) {
			if (check_member(v[i], tmp)) {
				//활성 바이러스
				q.push(v[i]);
				check[v[i].x][v[i].y] = true;
			}
			else {
				non_active_virus.push_back(v[i]);
			}
		}
		bfs(q, cnt);
		return;
	}

	for (int i = x; i < v.size(); i++) {
		tmp.push_back(v[i]);
		dfs(tmp, i + 1, cnt);
		tmp.pop_back();
	}
}

void bfs(queue<pa>q ,int cnt) {
	while (!q.empty()) {
		pa cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if (check_member(pa{ nx,ny }, non_active_virus)){
				if (check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(pa{ nx,ny });
					D[nx][ny] = D[cur.x][cur.y];
				}
			}
			else {
				if (check[nx][ny] == false && Map[nx][ny] == 0) {
					check[nx][ny] = true;
					q.push(pa{ nx,ny });
					D[nx][ny] = D[cur.x][cur.y] + 1;
					cnt++;
				}
			}
		}
	}

	//활성이든 비활성이든 구분하지않고 전부 0으로 바꿈
	for (int i = 0; i < v.size(); i++) {
		D[v[i].x][v[i].y] = 0;
	}

	int k = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (k < D[i][j] && !whereVirus(i, j)) {
				k = D[i][j];
			}
		}
	}

	if (cnt == n * n - wallCount) {
		flag = 1;//바이러스가 모든 빈칸에 퍼졌다는 것
		Min = min(Min, k);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];

			if (Map[i][j] == 2) {
				v.push_back(pa{ i,j });
				virusCount++;
			}

			if (Map[i][j] == 0) {
				nullCount++;
			}

			if (Map[i][j] == 1) {
				wallCount++;
			}
		}
	}

	if (nullCount == 0 && virusCount >= 1) {
		cout << 0;
		return 0;
	}

	vector<pa> tmp;
	dfs(tmp, 0, virusCount);

	if (flag == 1) {
		cout << Min;
	}
	else if (flag == 0) {
		cout << -1;
	}

	return 0;
}