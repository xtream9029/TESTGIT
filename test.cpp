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

vector<int> solution(vector<string> v) {
	vector<int> answer;
	set<string> s;
	map<string, int> m;

	for (int i = 0; i < v.size(); i++) {
		s.insert(v[i]);
	}

	int left = 0;
	int right = 0;
	int ax, ay;//최종 답
	int dif = v.size() + 100;

	//이중 loop가 없음
	while (left <= right) {
		if (right == v.size()) {
			if (m.size() == s.size()) {
				if (right - left < dif) {
					dif = right - left;
					ax = left + 1, ay = right;
				}
			}
			else break;
		}

		if (m.size() < s.size()){
			if (m.find(v[right]) != m.end()) {
				m[v[right]]++;
			}
			else {
				m.insert(make_pair(v[right], 1));
			}
			right += 1;
		}

		if (m.size() == s.size()) {
			if (right - left < dif) {
				dif = right - left;
				ax = left + 1, ay = right;
			}

			int k = --m[v[left]];
			if (k == 0) m.erase(v[left]);
			left += 1;
		}
	}//while

	answer.push_back(ax);
	answer.push_back(ay);
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	vector<int> ans = solution(v);
	cout << ans[0] << ' ' << ans[1];
	return 0;
}
