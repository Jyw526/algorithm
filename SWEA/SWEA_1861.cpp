#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
using namespace std;
int N;
int map[1001][1001];
int dist[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int x,int y, int cnt) {
    if (dist[x][y] != -1) return dist[x][y];
    dist[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i]; 
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if (map[nx][ny] - map[x][y] == 1) {
                dist[x][y] += dfs(nx, ny, cnt);
            }
        }
    }
    return dist[x][y];
}
void solution() {
    int start= -1;
    int ans = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dfs(i, j, 1);
            if (dist[i][j] > ans) {
                ans = dist[i][j];
                start = map[i][j];
            }
            else if (dist[i][j] == ans && map[i][j] < start) {
                start = map[i][j];
            }
        }
    }
    cout << start << " " << ans << '\n';
}
int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
                dist[i][j] = -1;
            }
        }
        cout << "#" << t << " ";
        solution();
    }
    return 0;
}
