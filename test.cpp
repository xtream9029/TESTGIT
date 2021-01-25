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

bool check(vector<string> v, string k) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == k) return false;
    }
    return true;
}

bool isExist(vector<string> v, string k) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == k) return true;
    }
    return false;
}

int solution(string str1, string str2) {
    int answer = 0;

    vector<string> v1;
    vector<string> v2;
    vector<string> v;

    double interSize = 0;
    double unionSize = 0;

    for (int i = 0; i < str1.length() - 1; i++) {
        char a, b;
        a = str1[i], b = str1[i + 1];

        if ((a >= 65 && a <= 90 || a >= 97 && a <= 122) && (b >= 65 && b <= 90 || b >= 97 && b <= 122)) {
            if (a >= 97 && a <= 122) {
                a -= 32;
            }
            if (b >= 97 && b <= 122) {
                b -= 32;
            }
            string tmp = "";
            tmp += a;
            tmp += b;
            v1.push_back(tmp);
        }
    }

    for (int i = 0; i < str2.length() - 1; i++) {
        char a, b;
        a = str2[i], b = str2[i + 1];

        if ((a >= 65 && a <= 90 || a >= 97 && a <= 122) && (b >= 65 && b <= 90 || b >= 97 && b <= 122)) {
            if (a >= 97 && a <= 122) {
                a -= 32;
            }
            if (b >= 97 && b <= 122) {
                b -= 32;
            }
            string tmp = "";
            tmp += a;
            tmp += b;
            v2.push_back(tmp);
        }
    }

    map<string, int> m1;
    for (int i = 0; i < v1.size(); i++) {
        m1[v1[i]] = 0;
    }
    map<string, int> m2;
    for (int i = 0; i < v2.size(); i++) {
        m2[v2[i]] = 0;
    }

    for (int i = 0; i < v1.size(); i++) {
        m1[v1[i]]++;
    }
    for (int i = 0; i < v2.size(); i++) {
        m2[v2[i]]++;
    }

    map<string, int>::iterator mt1;
    map<string, int>::iterator mt2;

    for (mt1 = m1.begin(); mt1 != m1.end(); mt1++) {
        string tmp = mt1->first;
        int k = mt1->second;
        for (mt2 = m2.begin(); mt2 != m2.end(); mt2++) {
            if (tmp == mt2->first) {
                interSize += double(min(k, mt2->second));
            }
        }
    }

    for (mt1 = m1.begin(); mt1 != m1.end(); mt1++) {
        unionSize += double(mt1->second);
    }
    for (mt2 = m2.begin(); mt2 != m2.end(); mt2++) {
        unionSize += double(mt2->second);
    }

    unionSize -= interSize;

    if (unionSize == 0) {
        answer = 65536;
    }
    else {
        double t;
        t = (interSize) / unionSize;
        answer = trunc(t * 65536);
    }
    return answer;
}