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

struct pa {
    int x;
    int y;
};

bool check(string s, vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == s) return false;
    }
    return true;
}

vector<int> solution(vector<string> gems){
    vector<int> answer;
    set<string> Set;

    pa ANSWER;
    for (int i = 0; i < gems.size(); i++) {
        Set.insert(gems[i]);
    }

    int left = 0;
    int right = 0;
    int dif = gems.size();
    int S;

    //투포인터 알고리즘
    while (left <= right){
        if (right == gems.size()) break;

        S = right - left+1;

        if (S < Set.size()) {
            right += 1;
        }
        else if (S >= Set.size()) {
            set<string> A;
            for (int i = left; i <= right; i++) {
                A.insert(gems[i]);
            }
            if (Set == A){
                if (S - 1 < dif) {
                    dif = S - 1;
                    ANSWER.x = left;
                    ANSWER.y = right;
                }
                left += 1;
            }
            else right += 1;
        }
    }//while

    answer.push_back(ANSWER.x + 1);
    answer.push_back(ANSWER.y + 1);
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    vector<int> rt = solution(v);
    cout << rt[0] << ' ' << rt[1];
    return 0;
}