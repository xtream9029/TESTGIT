#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <sstream>
#include <stdlib.h>

using namespace std;

void merge_sort(int first, int last, vector<int>& v) {
	if (first >= last)
		return;

	int mid = (first + last) / 2;

	merge_sort(first, mid, v);
	merge_sort(mid+1, last, v);

	int left = first;
	int right = mid + 1;
	vector<int> tmp;

	while (left <= mid && right <= last) {
		if (v[left] < v[right]) {
			tmp.push_back(v[left]);
			left += 1;
		}
		else {
			tmp.push_back(v[right]);
			right += 1;
		}
	}

	for (int i = left; i <= mid; i++) {
		tmp.push_back(v[i]);
	}

	for (int i = right; i <= last; i++) {
		tmp.push_back(v[i]);
	}

	for (int i = first; i <= last; i++) {
		v[i] = tmp[i - first];
	}
}

void quick_sort(int first, int last, vector<int> v) {
	if (first >= last)
		return;

	int pivot = v[first];
	int left = first + 1;
	int right = last;

	while (left <= right) {
		while (left <= last && pivot > v[left]) {
			left += 1;
		}
		while (right > first && pivot <= v[right]) {
			right -= 1;
		}
		if (left <= right) {
			int tmp = v[left];
			v[left] = v[right];
			v[right] = tmp;
		}
	}
	int tmp = v[first];
	v[first] = v[right];
	v[right] = tmp;

	quick_sort(first, right - 1, v);
	quick_sort(right+1, last, v);
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	merge_sort(0, v.size() - 1, v);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}