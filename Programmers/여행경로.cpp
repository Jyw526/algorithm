#include <string>
#include <vector>

using namespace std;

vector<string> answer;
vector<int> visited;
void dfs(vector<string> v, vector<vector<string>> tickets, int N) {
    if (v.size() == N + 1) {
        /*for (int i = 0; i < N + 1; i++) {
            cout << v[i] << " ";
        }
        cout << '\n';*/
        if (answer.size() == 0) {
            answer = v;
        }
        else {
            string s1 = "";
            string s2 = "";
            for (int i = 0; i < N; i++) {
                s1 += answer[i];
                s2 += v[i];
            }
            if (s1 > s2) {
                for (int i = 0; i < N; i++) {
                    answer[i] = v[i];
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            if (v.back() == tickets[i][0]) {
                visited[i] = true;
                v.push_back(tickets[i][1]);
                dfs(v, tickets, N);
                visited[i] = false;
                v.pop_back();
            }
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    
    int N = tickets.size();
    for (int i = 0; i < tickets.size(); i++) {
        visited.push_back(0);
    }
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == "ICN") {
            visited[i] = true;
            vector<string> v;
            v.push_back("ICN");
            v.push_back(tickets[i][1]);
            dfs(v, tickets, N);
            visited[i] = false;
        }
    }
   
    return answer;
}