#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
const int INF = 987654321;

int N;
int bfs(int s, vector<int> adj[]) {
    queue<int> q;
    int dist[1001];
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
    }
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        for (int i = 0; i < adj[n].size(); i++) {
            if (dist[adj[n][i]] > dist[n] + 1) {
                dist[adj[n][i]] = dist[n] + 1;
                q.push(adj[n][i]);
            }
        }
    }
    int cc = 0;
    for (int i = 0; i < N; i++) {
        cc += dist[i];
    }
    return cc;
}
int main() {
    int T;
    int ans;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ans = INF;
        cin >> N;
        vector<int> adj[1001];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int a;
                cin >> a;
                if (a) {
                    adj[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            ans = min(ans, bfs(i,adj));

        }
        cout << "#" << t << " " << ans << '\n';
    }
   
    return 0;
}
