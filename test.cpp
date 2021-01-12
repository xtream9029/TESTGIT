#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <sstream>
#include <stdlib.h>

using namespace std;

int n, t, g;
bool check[100000];
bool flag = false;
int answer = 0;

struct Data {
	int x;
	int cnt;
};

int fun(int x) {
	x *= 2;
	vector<int> v;
	while (x > 0) {
		v.push_back(x % 10);
		x /= 10;
	}
	
	for (int i = v.size() - 1; i >= 0; i--) {
		if (0<v[i]) {
			v[i]--;
			break;
		}
	}

	int k = 1;
	int rt = 0;
	for (int i = 0; i < v.size(); i++) {
		rt += (k * v[i]);
		k *= 10;
	}
	return rt;
}

void bfs(int start) {
	queue<Data> q;
	check[start] = true;
	q.push(Data{start,0});

	while (q.size()) {
		Data cur = q.front();
		q.pop();
		int curNum = cur.x;
		int curCount = cur.cnt;

		if (curNum == g && curCount <= t) {
			answer = curCount;
			flag = true;
			return;
		}

		if (curNum+1 < 100000 && curCount<t) {
			if (check[curNum+1] == false) {
				check[curNum+1] = true;
				q.push(Data{curNum+1,curCount+1});
			}
		}

		int k = fun(curNum);
		if (0 <k && k < 100000 && curCount <t) {
			if (check[k] == false) {
				check[k] = true;
				q.push(Data{ k,curCount + 1 });
			}
		}
	}//while
	return;
}


int main() {
	cin >> n >> t >> g;
	memset(check, false, sizeof(check));
	bfs(n);
	if (flag) {
		cout << answer;
	}
	else cout << "ANG";
	return 0;
}