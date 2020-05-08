#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool cmp(vector<int> a, vector<int>b) {
    return a.size() < b.size();
}
vector<int> solution(string s) {
    vector<vector<int>> t;
    vector<int> answer;
    string n = "";
    vector<int> tmp;
    for (int i = 1; i < s.length()-1; i++) {
        if (s[i] == ',' && n.length() > 0) {
            int num = atoi(n.c_str());
            tmp.push_back(num);
            n = "";
        }
        else if (s[i] == '}') {
            int num = atoi(n.c_str());
            tmp.push_back(num);
            t.push_back(tmp);
            n = ""; tmp.clear();
        }
        else if (s[i] != '{' && s[i]!=',') {
            n += s[i];
        }
    }
    sort(t.begin(), t.end(), cmp);
    answer.push_back(t[0][0]);
    for (int i = 1; i < t.size(); i++) {
        for (int j = 0; j < t[i].size(); j++) {
            bool check = true;
            for (int k = 0; k < answer.size(); k++) {
                if (t[i][j] == answer[k]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                answer.push_back(t[i][j]);
                break;
            }
        }
;    }
    return answer;
}