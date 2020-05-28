#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int dist[20001];
    vector<int> v[20001]; 
    for(int i=0;i<n;i++){
        dist[i] = 987654321;
    }
    for(int i=0;i<edge.size();i++){
        v[edge[i][0]-1].push_back(edge[i][1]-1);
        v[edge[i][1]-1].push_back(edge[i][0]-1);
    }
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0;i<v[node].size();i++){
            if(dist[v[node][i]] > dist[node] + 1){
                dist[v[node][i]] = dist[node] + 1;
                q.push(v[node][i]);
            }
        }
    }
    int maxDist = -1;
    for(int i=0;i<n;i++){
        maxDist = max(maxDist, dist[i]);
    }
    for(int i=1;i<n;i++){
        if(dist[i] == maxDist)
            answer++;
    }
    return answer;
}