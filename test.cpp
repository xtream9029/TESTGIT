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