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

int primeNumber[4000001];

int main() {

	int n;
	cin >> n;
	for (int i = 0; i <= 4000000; i++) {
		primeNumber[i] = 1;
	}

	primeNumber[1] = 0;
	for (int i = 2; i * i <= n; i++) {
		for (int j = i * i; j <= n; j += i) {
			if (primeNumber[j] == 0) continue;
			primeNumber[j] = 0;
		}
	}

	int cnt = 0;
	vector<int> v;
	for (int i = 2; i <= n; i++) {
		if (primeNumber[i] == 1) v.push_back(i);
	}
	
	for (int i = 1; i < (int)v.size(); i++) {
		v[i] += v[i - 1];
	}//for

	int S;
	int left = -1;
	int right = 0;
	while(left<=right){
		if (right >= (int)v.size()) break;
		
		if (left == -1) S = v[right];
		else S = v[right] - v[left];

		if (S < n) right += 1;
		else if (S == n) {
			cnt++;
			right += 1;
		}
		else {
			left += 1;
		}
	}//while

	std::cout << cnt;
	return 0;
}