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

#define MAX 987654321
int Min = MAX;//가장 짧은걸 구해야 하므로

int solution(string s) {
    int answer = 0;

    for (int i = 1; i <= s.length(); i++) {
        string tmp = "";
        vector<string> v;

        //문자열을 자르는 과정
        for (int k = 0; k < s.length(); k++) {
            tmp += s[k];

            if (tmp.length() == i) {
                v.push_back(tmp);
                tmp = "";
            }
        }
        v.push_back(tmp);

        string S = "";
        int cnt = 1;
        for (int k = 0; k < v.size() - 1; k++) {
            if (v[k] == v[k + 1]) {
                cnt++;
            }
            else {
                if (cnt == 1) {
                    S += v[k];
                }
                else if (cnt > 1) {
                    S += to_string(cnt) + v[k];
                }
                cnt = 1;
            }
        }
        S += v[v.size() - 1];

        if (Min > S.length()) Min = S.length();
    }
    answer = Min;
    return answer;
}

int main() {
    string s;
    cin >> s;

    cout << solution(s);
    return 0;
}