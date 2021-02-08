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

vector<int> solution(int n, vector<string> words) {
	map<int, int> person;
	map<string, bool> wb;
	vector<int> v;
	bool flag = false;

	

	//각 사람이 몇번째인지 기록한 맵
	for (int i = 1; i <= n; i++) {
		person.insert(make_pair(i, 0));
	}

	//예외 처리
	if (words[0].size() == 1) {
		v.push_back(1);
		v.push_back(1);
		return v;
	}

	wb.insert(make_pair(words[0], true));
	person[1]++;
	for (int i = 1; i < words.size(); i++) {
		string before = words[i - 1];
		string current = words[i];
		if (wb.find(current) == wb.end() && before[before.length() - 1] == current[0] && current.size() > 1) {
			person[(i + 1)%n]++;
			wb.insert(make_pair(current,true));
		}
		else {
			flag = true;
			v.push_back((i + 1) % n);//몇번째 사람
			v.push_back(++person[(i + 1) % n]);//몇번째 차례
		}
	}
	
	if (flag==true && v.empty()){
		v.push_back(0);
		v.push_back(0);
	}
	return v;
}

int main() {
	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		v.push_back(x);
	}
	vector<int> ans = solution(n,v);
	cout << ans[0] << ' ' << ans[1];
	return 0;
}