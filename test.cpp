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

int StringToInt(string s) {
    int k = 1;
    int num = 0;
    for (int i = s.length()-1; i >= 0; i--) {
        num += (s[i] - '0')*k;
        k *= 10;
    }
    return num;
}

string solution(string s) {
    string answer = "";
    vector<int> v;
    bool minus_flag = false;
    string tmp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') {
            if (minus_flag == false) {
                minus_flag = true;
            }
        }
        else if(s[i]==' '){
            if (minus_flag == true) {
                v.push_back(-StringToInt(tmp));
                minus_flag = false;
                tmp = "";
            }
            else {
                v.push_back(StringToInt(tmp));
                tmp = "";
            }
        }
        else {
            tmp += s[i];
        }
    }
    if (minus_flag == true) {
        v.push_back(-StringToInt(tmp));
        minus_flag = false;
    }
    else {
        v.push_back(StringToInt(tmp));
    }

    sort(v.begin(), v.end());

    /*vector<int> Min;
    vector<int> Max;
    string tmp_1 = "";
    string tmp_2 = "";
    int a = v.front();
    int b = v.back();
    
    if (a == 0) {
        tmp_1 += '0';
    }
    if (b == 0) {
        tmp_2 += '0';
    }

    while (abs(a) > 0) {
        Min.push_back(a % 10);
        a /= 10;
    }
    while (abs(b) > 0) {
        Max.push_back(b % 10);
        b /= 10;
    }
        
    reverse(Min.begin(), Min.end());
    reverse(Max.begin(), Max.end());

    for (int i = 0; i < Min.size(); i++) {
        int t = Min[i];
        if (t < 0) {
            tmp_1 += '-';
            tmp_1 += char(abs(t)+48);
        }
        else {
            tmp_1 += char(t + 48);
        }
    }
    for (int i = 0; i < Max.size(); i++) {
        int t = Max[i];
        if (t < 0) {
            tmp_2 += '-';
            tmp_2 += char(abs(t) + 48);
        }
        else {
            tmp_2 += char(t + 48);
        }
    }*/
    answer = to_string(v.front()) + ' ' + to_string(v.back());
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string k;
    getline(cin, k);
    cout << solution(k);
    return 0;
}