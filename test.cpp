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

struct Data {
    int former_x;
    int former_y;
    int current_x;
    int current_y;
    int cost;
};

int D[25][25];
bool check[25][25];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int Min = 987654321;

int bfs(vector<vector<int>> board) {
    int Size = board.size();
    queue<Data> q;
    check[0][0] = true;

    if (board[0][1] == 0) {
        q.push(Data{ 0,0,0,1,100 });
        check[0][1] = true;
    }
    if (board[1][0] == 0) {
        q.push(Data{ 0,0,1,0,100 });
        check[1][0] = true;
    }

    while (q.size()) {
        Data cur = q.front();
        q.pop();

        if (cur.current_x == Size - 1 && cur.current_y == Size - 1) {
            Min = min(Min, cur.cost);
            D[Size - 1][Size - 1] = Min;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.current_x + dx[i];
            int ny = cur.current_y + dy[i];

            if (nx < 0 || nx >= Size) continue;
            if (ny < 0 || ny >= Size) continue;

            if (board[nx][ny] == 0) {
                int new_cost = cur.cost + 100;

                if (abs(nx - cur.former_x) == 1 && abs(ny - cur.former_y) == 1)
                    new_cost += 500;

                if (!check[nx][ny]) {
                    check[nx][ny] = true;
                    q.push(Data{ cur.current_x,cur.current_y,nx,ny,new_cost });
                    D[nx][ny] = new_cost;
                }
                else {
                    if (cur.cost <= D[nx][ny]) {
                        q.push(Data{ cur.current_x,cur.current_y,nx,ny, new_cost });
                        D[nx][ny] = new_cost;
                    }
                }
            }
        }//for
    }//while
    return D[Size - 1][Size - 1];
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    memset(check, false, sizeof(check));
    memset(D, 0, sizeof(D));
    answer = bfs(board);
    return answer;
}