#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <sstream>
#include <stdlib.h>

using namespace std;

struct Data {
	int A[3][3];
	int d;
};

int firstState[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
int destState[3][3] = {{1,2,3},{4,5,6},{7,8,0}};
vector<Data> check;

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> firstState[i][j];
		}
	}

	queue<Data> q;







}