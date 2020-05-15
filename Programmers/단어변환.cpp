#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool check = false;
    bool visited[51] = { false, };
    queue<pair<string, int> > q;
    q.push({ begin,0 });
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == target) {
            check = true;
            break;
        }
    }
    if (!check) return answer;
    else {
        while (!q.empty()) {
            string w = q.front().first;
            int c = q.front().second;
            q.pop();
            if (w == target) {
                answer = c;
                break;
            }
            for (int i = 0; i < words.size(); i++) {
                if (!visited[i]) {
                    int cnt = 0;
                    for (int j = 0; j < w.length(); j++) {
                        if (w[j] != words[i][j])
                            cnt++;
                    }
                    if (cnt == 1) {
                        visited[i] = true;
                        q.push({ words[i],c + 1 });
                    }
                }
            }
        }
        
    }
    return answer;
}