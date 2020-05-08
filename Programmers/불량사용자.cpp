#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

vector<int> bi[9];
bool used[9] = { false, };
set<string> s;
void dfs(int cnt, int N, vector<int> v) {
    if (cnt == N) {
        sort(v.begin(), v.end());
        string str = "";
        for (int i = 0; i < v.size(); i++) {
            str += v[i];
        }
        s.insert(str);
        return;
    }
    for (int i = 0; i < bi[cnt].size(); i++) {
        if (!used[bi[cnt][i]]) {
            used[bi[cnt][i]] = true;
            v.push_back(bi[cnt][i]);
            dfs(cnt + 1, N, v);
            v.pop_back();
            used[bi[cnt][i]] = false;
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    for (int i = 0; i < banned_id.size(); i++) {
        for (int j = 0; j < user_id.size(); j++) {
            bool check = true;
            if (banned_id[i].length() == user_id[j].length()) {
                for (int k = 0; k < banned_id[i].length(); k++) {
                    if (banned_id[i][k] == '*')
                        continue;
                    if (banned_id[i][k] != user_id[j][k]) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    bi[i].push_back(j);
                }
            }
        }
    }
    
    vector<int> vec;
    dfs(0, banned_id.size(),vec);
    answer = s.size();
    return answer;
}
