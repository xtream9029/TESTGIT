#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <stdio.h>
#include <sstream>
#include <string.h>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1};
bool check[30][30];
int Map[30][30];

struct node {
	int x;
	int y;
};

int min_cost = 987654321;
int n;

//왜 최단거리를 보장해주지 못하는지 이해해야함
void dfs(int x,int y,vector<node> &v) {
	if (x == n - 1 && y == n - 1) {
		int cnt = 0;
		for (int i = 1; i < v.size()-1; i++) {
			if (abs(v[i - 1].x - v[i + 1].x) == 1 && abs(v[i - 1].y - v[i + 1].y) == 1) {
				cnt++;
			}
		}
		int cost = 100 * (v.size() - 1) + 500 * cnt;
		min_cost = min(cost, min_cost);
		return;
	}

	for (int i = 0; i <4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || nx >= n) continue;
		if (ny < 0 || ny >= n) continue;

		if (Map[nx][ny] == 0) {
			if (check[nx][ny]) continue;
			check[nx][ny] = true;
			v.push_back(node{ nx,ny });
			dfs(nx, ny, v);
			v.pop_back();
			check[nx][ny] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];
		}
	}

	vector<node> v;
	v.push_back(node{ 0,0 });
	dfs(0, 0, v);
	cout << min_cost;
	return 0;
}